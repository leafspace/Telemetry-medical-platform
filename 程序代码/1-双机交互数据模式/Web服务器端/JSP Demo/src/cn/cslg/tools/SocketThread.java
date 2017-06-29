package cn.cslg.tools;

import java.net.Socket;
import java.io.IOException;
import java.net.ServerSocket;
import java.io.InputStreamReader;
import cn.cslg.database.MySqlDatabaseConnection;

/**
 * Created by 18852 on 2017/3/11.
 */
public class SocketThread extends Thread{
    private final int portNumber = 80;
    private ServerSocket serverSocket;

    public SocketThread(){
    }

    public void run() {
        try {
            serverSocket = new ServerSocket(portNumber);
            while (!this.isInterrupted()) {
                Socket socket = serverSocket.accept();
                InputStreamReader rd = new InputStreamReader(socket.getInputStream(), "GB2312");//
                char[] data = new char[1024];
                rd.read(data);
                System.out.println(data);
                socket.close();
                String sql = "INSERT INTO information VALUES('" + data + "');";
                MySqlDatabaseConnection mySqlDatabaseConnection = new MySqlDatabaseConnection();
                mySqlDatabaseConnection.getConnection();
                mySqlDatabaseConnection.update(sql);
                mySqlDatabaseConnection.allClose();

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
        catch (Exception ex)
        {
            System.out.println("SocketThread err:"+ex.getMessage());
        }
    }
}
