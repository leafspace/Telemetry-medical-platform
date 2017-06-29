package cn.cslg.tools;

import cn.cslg.Thread.ReceiveTread;
import cn.cslg.database.MySqlDatabaseConnection;

import java.io.BufferedReader;
import java.net.Socket;
import java.io.IOException;
import java.net.ServerSocket;
import java.io.InputStreamReader;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by 18852 on 2017/3/11.
 */
public class SocketThread extends Thread {
    private final int portNumber = 10212;
    private ServerSocket serverSocket;
    private Socket[] socket;
    public static int userNumber = 1;

    public SocketThread() {
        try {
            serverSocket = new ServerSocket(portNumber);
            socket = new Socket[10];
            for(int i = 0; i < 10; ++i) {
                socket[i] = null;
            }
            userNumber--;
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        try {
            while (!this.isInterrupted() & serverSocket != null) {
                for(int i = 0; i < 10; ++i) {
                    if(socket[i] == null) {
                        socket[i] = serverSocket.accept();
                        System.out.println("有人接入服务器");
                        InputStreamReader inputStreamReader = new InputStreamReader(socket[i].getInputStream(), "UTF-8");
                        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

                        //System.out.println("Socket Thread info : " + bufferedReader.readLine());
                        //ReceiveTread receiveTread = new ReceiveTread(socket[i], inputStreamReader);
                        //receiveTread.start();


                        String result;
                        do {
                            result = bufferedReader.readLine();
                        }while(result == null);
                        SimpleDateFormat dataFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                        String time = dataFormat.format(new Date());

                        String sql = "INSERT INTO information(information, time) VALUES('" + result + "', '" + time + "');";
                        MySqlDatabaseConnection mySqlDatabaseConnection = new MySqlDatabaseConnection();
                        mySqlDatabaseConnection.getConnection();
                        mySqlDatabaseConnection.update(sql);
                        mySqlDatabaseConnection.allClose();
                    }
                }
            }
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public void closeServerSocket() {
        try {
            if (serverSocket != null && !serverSocket.isClosed()) {
                serverSocket.close();
            }
        }
        catch (Exception e) {
            System.out.println("SocketThread error : " + e.getMessage());
        }finally {
            serverSocket = null;
        }
    }
}
