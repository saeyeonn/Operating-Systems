import java.net.*;
import java.io.*;

public class DateClient {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("127.0.0.1", 6013);

            InputStream in = socket.getInputStream();
            BufferedReader br = new BufferedReader(new InputStreamReader(in));

            // read date from socket
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            
                // close socket connection
                socket.close();
            } 
        } catch (IOException e) {
            System.err.println(e);
        }
    }    
}
