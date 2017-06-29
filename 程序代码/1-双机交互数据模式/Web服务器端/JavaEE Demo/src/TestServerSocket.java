import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

public class TestServerSocket {

    public static void main(String args[]) throws IOException {
        final int portNumber = 80;
        System.out.println("Creating server socket on port " + portNumber);
        ServerSocket serverSocket = new ServerSocket(portNumber);
        while (true) {
            Socket socket = serverSocket.accept();
            InputStreamReader rd = new InputStreamReader(socket.getInputStream(),"UTF-8");
            char[] data = new char[1024];
            rd.read(data);
            System.out.println(data);
            socket.close();
        }
    }
}
