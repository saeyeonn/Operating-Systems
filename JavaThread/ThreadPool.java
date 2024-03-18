package JavaThread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ThreadPool {
    public static void main(String[] args) {
        int numTasks = Integer.parseInt(args[0].trim());

        ExecutorService pool = Executors.newCachedThreadPool();

//        for (int i = 0; i < numTasks; i++) {
//            pool.execute(new Task());
//        }

        pool.shutdown();
    }
}
