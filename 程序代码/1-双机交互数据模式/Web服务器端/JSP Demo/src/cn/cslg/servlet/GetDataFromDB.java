package cn.cslg.servlet;

import cn.cslg.database.MySqlDatabaseConnection;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Created by 18852 on 2017/3/21.
 */
public class GetDataFromDB  extends HttpServlet {
    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        ResultSet resultSet = null;
        MySqlDatabaseConnection mySqlDatabaseConnection = new MySqlDatabaseConnection();
        mySqlDatabaseConnection.getConnection();
        resultSet = mySqlDatabaseConnection.query("SELECT * FROM information;");
        ArrayList<String> informations = new ArrayList<>();
        if(resultSet != null){
            try {
                while (resultSet.next()) {
                    informations.add(resultSet.getString(1));
                }
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        mySqlDatabaseConnection.allClose();
        request.setAttribute("informations", informations);
        request.getRequestDispatcher("index.jsp").forward(request, response);
    }
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        this.doPost(request, response);
    }
}
