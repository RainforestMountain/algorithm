package tcp;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class TcpServerSocket {
    //需要建立连接了
    ServerSocket serverSocket = null;

    public TcpServerSocket(int port) throws IOException {
        serverSocket = new ServerSocket(port);
    }

    public void start() throws IOException {
        //建立连接
        System.out.println("服务器启动");
        while (true) {
            Socket clientSocket = serverSocket.accept();
            process(clientSocket);
        }
    }

    public void process(Socket clientSocket) {

    }
}
