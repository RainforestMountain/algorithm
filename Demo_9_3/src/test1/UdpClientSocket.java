package test1;

import javax.imageio.stream.ImageInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;
import java.util.Scanner;

public class UdpClientSocket {
    DatagramSocket clientSocket = null;
    String serverIp;
    int serverPort;

    public UdpClientSocket(String ip, int port) throws SocketException {
        serverIp = ip;
        serverPort = port;
        clientSocket = new DatagramSocket();
    }

    public void start() throws IOException {
        Scanner scanner = new Scanner(System.in);
        System.out.println("客户端启动");
        while (true) {
            //读取并发送请求,需要对方的地址
            String request = scanner.next();
            DatagramPacket requestPacket = new DatagramPacket(request.getBytes(), 0, request.getBytes().length,
                    InetAddress.getByName(serverIp), serverPort);
            clientSocket.send(requestPacket);
            //接收服务器的响应
            DatagramPacket responsePacket = new DatagramPacket(new byte[4096], 4096);
            clientSocket.receive(responsePacket);
            //解析响应内容

            String response = new String(responsePacket.getData(), 0, responsePacket.getLength());

            System.out.println(response);
        }
    }

    public static void main(String[] args) throws IOException {
        UdpClientSocket udpClientSocket = new UdpClientSocket("127.0.0.1", 9000);
        udpClientSocket.start();
    }
}
