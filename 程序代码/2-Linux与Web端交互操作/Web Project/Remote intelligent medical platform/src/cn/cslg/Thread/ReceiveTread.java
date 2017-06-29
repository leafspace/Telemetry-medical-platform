package cn.cslg.Thread;

import cn.cslg.database.MySqlDatabaseConnection;

import java.io.BufferedReader;
import java.net.Socket;
import java.util.Date;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;

public class ReceiveTread extends Thread {
    Socket socket;
    InputStreamReader inputStreamReader;
    BufferedReader bufferedReader;


    public ReceiveTread(Socket socket, InputStreamReader inputStreamReader) {
        this.socket = socket;
        this.inputStreamReader = inputStreamReader;
        this.bufferedReader = new BufferedReader(inputStreamReader);
    }


    @Override
    public void run() {
        String result = null;
        String temp = new String();
        try {
            while(true){
                result = this.bufferedReader.readLine();
                while(result != null){
                    if(result.equals(temp + "finish")) {
                        this.socket.close();
                        break;
                    }
                    temp += result;
                    System.out.println("Info : " + result);

                    /*
                    SimpleDateFormat dataFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                    String time = dataFormat.format(new Date());

                    String sql = "INSERT INTO information(information, time) VALUES('" + information + "', '" + time + "');";
                    MySqlDatabaseConnection mySqlDatabaseConnection = new MySqlDatabaseConnection();
                    mySqlDatabaseConnection.getConnection();
                    mySqlDatabaseConnection.update(sql);
                    mySqlDatabaseConnection.allClose();
                    */
                }

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}