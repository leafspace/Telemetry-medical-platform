package cn.cslg.database;

import java.sql.*;

public class MySqlDatabaseConnection{
    private static String driverName = "com.mysql.jdbc.Driver";
    private static String userName = "root";
    private static String userPassword = "123456";
    private static String databaseIp = "192.168.198.129";
    private static String dbName = "MedicalPlatform";

    private static Connection connection;
    private static PreparedStatement preparedStatement;

    public Connection getConnection(){
        try {
            String url = "jdbc:mysql://" + databaseIp + ":3306/" + dbName + "?useUnicode=true&characterEncoding=utf8&user=" + userName + "&password=" + userPassword;
            Class.forName(driverName);                                                             //加载数据库驱动程序类
            MySqlDatabaseConnection.connection = DriverManager.getConnection(url);                 //获取数据库链接
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
