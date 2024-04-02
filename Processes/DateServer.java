import java.net.*;
import java.io.*;

public class DateServer {
    public static void main(String[] args) {
        try {
            ServerSocket socket = new ServerSocket(6013);

            // now listen for connection
            while (true) {
                Socket client = socket.accept();

                PrintWriter pWriter = new PrintWriter(client.getOutputStream(), true);

                // write date to socket
                pWriter.println(new java.util.Date().toString());

                // clost socke & resume
                // listen for connections
                client.close();
            }
        } catch (IOExcepton e) {
            System.err.println(e);
        }
    }
    
}