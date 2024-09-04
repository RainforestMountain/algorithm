package test1;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class UdpServerSocket {
    private DatagramSocket serverSocket = null;

    public UdpServerSocket(int port) throws SocketException {
        serverSocket = new DatagramSocket(port);
    }

    public void start() throws IOException {
        System.out.println("服务器启动");

        while (true) {
            //不需要连接, 直接接收请求
            DatagramPacket requestPacket = new DatagramPacket(new byte[4096], 4096);
            serverSocket.receive(requestPacket);
            //解析请求, 计算响应
            String request = new String(requestPacket.getData(), 0, requestPacket.getLength());
            String response = process(request);
            //发送返回响应,需要对方的地址
            DatagramPacket responsePacket = new DatagramPacket(response.getBytes(), 0, response.getBytes().length, requestPacket.getAddress(), requestPacket.getPort());
            serverSocket.send(responsePacket);
            //记录日志
            System.out.println("address: " + requestPacket.getAddress() + " req = " + request + " resp = " + response);
        }
    }

    public String process(String request) {
        return request;
    }

    public static void main(String[] args) throws IOException {
        UdpServerSocket udpServerSocket = new UdpServerSocket(9000);
        udpServerSocket.start();
    }

}
