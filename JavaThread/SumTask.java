package JavaThread;

import java.util.concurrent.RecursiveTask;

public class SumTask extends RecursiveTask<Integer> {
    static final int THRESHOLD = 1000;

    private final int begin;
    private final int end;
    private final int[] arr;

    public SumTask(int begin, int end, int[] arr) {
        this.begin = begin;
        this.end = end;
        this.arr = arr;
    }

    @Override
    protected Integer compute() {
        if (end - begin < THRESHOLD) {
            int sum = 0;
            for (int i = begin; i <= end; i++) {
                sum += arr[i];
            }

            return sum;
        } else {
            int mid = (begin + end) / 2;
            SumTask leftTask = new SumTask(begin, mid, arr);
            SumTask rightTask = new SumTask(mid + 1, end, arr);

            leftTask.fork();
            rightTask.fork();

            return rightTask.join() + leftTask.join();
        }
    }
}
