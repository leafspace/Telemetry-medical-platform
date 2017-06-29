package cn.cslg.tools;

import cn.cslg.database.MySqlDatabaseConnection;

import java.sql.ResultSet;
import java.util.ArrayList;
import java.sql.SQLException;

/**
 * Created by 18852 on 2017/3/21.
 */
public class GetData {
    public ArrayList<DataStruts> informations;

    public GetData(){
        informations = new ArrayList<DataStruts>();
    }

    public ArrayList<DataStruts> getInformations(){
        ResultSet resultSet = null;
        informations.clear();
        MySqlDatabaseConnection mySqlDatabaseConnection = new MySqlDatabaseConnection();
        mySqlDatabaseConnection.getConnection();
        resultSet = mySqlDatabaseConnection.query("SELECT information, time FROM information ORDER BY id DESC;");
        if(resultSet != null){
            try {
                while (resultSet.next()) {
                    DataStruts dataStruts = new DataStruts(resultSet.getString(1), resultSet.getString(2));
                    informations.add(dataStruts);
                }
            }catch (SQLException e){
                e.printStackTrace();
            }
        }
        mySqlDatabaseConnection.allClose();
        return this.informations;
    }
}
