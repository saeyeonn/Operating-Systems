package JavaThread;

import java.util.concurrent.ForkJoinPool;

public class ForkJoinParallelism {
    private static final int SIZE = 0;
    ForkJoinPool pool = new ForkJoinPool();

    int[] arr = new int[SIZE];

//    SumTask task = new SumTask(0, SIZE - 1,arr);
//    int sum = pool.invoke(task);
}
