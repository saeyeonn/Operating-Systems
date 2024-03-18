package JavaThread;

import java.util.concurrent.Callable;

public class Summation implements Callable<Integer> {
    private final int upper;
    @Override
    public Integer call() throws Exception {
        int sum = 0;
        for (int i = 0; i <= upper; i++) {
            sum += i;
        }
        return sum;
    }

    public Summation(int upper) {
        this.upper = upper;
    }

}
