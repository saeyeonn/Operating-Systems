package JavaThread;

public class Task implements Runnable{
    @Override
    public void run() {
        System.out.println("I am a thread");

        Thread worker = new Thread(String.valueOf(new Task()));
        worker.start();

        try {
            worker.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        Executor service = new Executor() {
            @Override
            public void execute(Runnable command) {
                System.out.println();
            }
        };

        service.execute(new Task());
    }
}
