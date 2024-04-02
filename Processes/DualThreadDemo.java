class ThreadExample extends Thread{
    public void run() {
        for(int i = 0; i < 5; i++) {
            System.out.println("From Thread ex: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class RunnableExample implements Runnable {
    public void run() {
        for(int i = 0; i < 5; i++) {
            System.out.println("From Thread ex: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class DualThreadDemo {
    public static void main(String[] args) {
        ThreadExample thread1 = new ThreadExample();
        Thread thread2 = new Thread(new RunnableExample());

        thread1.start();
        thread2.start();
    }
}