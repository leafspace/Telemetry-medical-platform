package cn.cslg.database;

import java.sql.*;

/**
 * Created by 18852 on 2017/3/7.
 */
public class MySqlDatabaseConnection{
    private static String driverName = "com.mysql.jdbc.Driver";
    private static String userName = "root";
    private static String userPassword = "admin";
    private static String dbName = "test";

    private static Connection connection;
    private static PreparedStatement preparedStatement;

    public Connection getConnection(){
        try {
            String url = "jdbc:mysql://localhost:3306/" + dbName + "?useUnicode=true&characterEncoding=utf8&user=" + userName + "&password=" + userPassword;
            Class.forName(driverName);                                         //加载数据库驱动程序类
            MySqlDatabaseConnection.connection = DriverManager.getConnection(url);       //获取数据库链接
            return MySqlDatabaseConnection.connection;
        } catch (ClassNotFoundException e) {
            System.out.println("Error : No Mysql driver !");
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    public void allClose(){
        try{
            if(MySqlDatabaseConnection.preparedStatement != null){
                preparedStatement.close();
            }
            if(MySqlDatabaseConnection.connection != null){
                connection.close();
            }
        }catch (SQLException e){
            e.printStackTrace();
        }
    }

    public void update(String sql){
        try {
            preparedStatement = MySqlDatabaseConnection.connection.prepareStatement(sql);
            preparedStatement.executeUpdate();
            //connection.commit();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public ResultSet query(String sql){
        try {
            preparedStatement = MySqlDatabaseConnection.connection.prepareStatement(sql);
            ResultSet resultSet = preparedStatement.executeQuery();
            return resultSet;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
}
