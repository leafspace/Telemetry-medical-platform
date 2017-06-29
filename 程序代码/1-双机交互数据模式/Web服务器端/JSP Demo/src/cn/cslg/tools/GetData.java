package cn.cslg.tools;

import cn.cslg.database.MySqlDatabaseConnection;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * Created by 18852 on 2017/3/21.
 */
public class GetData {
    public ArrayList<String> informations;

    public GetData(){
        informations = new ArrayList<String>();
    }

    public ArrayList<String> getInformations(){
        ResultSet resultSet = null;
        informations.clear();
        MySqlDatabaseConnection mySqlDatabaseConnection = new MySqlDatabaseConnection();
        mySqlDatabaseConnection.getConnection();
        resultSet = mySqlDatabaseConnection.query("SELECT * FROM information;");
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
        return this.informations;
    }
}
