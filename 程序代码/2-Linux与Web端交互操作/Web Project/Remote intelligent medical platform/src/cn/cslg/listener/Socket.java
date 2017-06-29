package cn.cslg.listener;

import cn.cslg.tools.SocketThread;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;

/**
 * Created by 18852 on 2017/3/11.
 */
public class Socket implements HttpSessionListener {
    private SocketThread socketThread;
    public void sessionCreated (HttpSessionEvent se){
        System.out.println("Server contextInitialized over!");
        if (socketThread == null && SocketThread.userNumber > 0)
        {
            socketThread = new SocketThread();
            socketThread.start();
        }
    }

    public void sessionDestroyed (HttpSessionEvent se){
        if (socketThread != null && socketThread.isInterrupted())
        {
            socketThread.closeServerSocket();
            socketThread.interrupt();
        }
    }
}
