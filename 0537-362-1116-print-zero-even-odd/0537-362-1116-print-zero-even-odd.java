class ZeroEvenOdd {
    private int n;
    private volatile int cumulativeInvocationCount;
    private final ReentrantLock lock;
    private final Condition turnChanged;
    
    public ZeroEvenOdd(int n) {
        this.n = n;
        this.cumulativeInvocationCount = 0;
        this.lock = new ReentrantLock();
        this.turnChanged = lock.newCondition();
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            try {
                lock.lock();

                while ((cumulativeInvocationCount % 2) != 0) {
                    turnChanged.await();
                }

                printNumber.accept(0);
                cumulativeInvocationCount++;
                turnChanged.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        int size = n / 2;
        for (int i = 0; i < size; i++) {
            try {
                lock.lock();

                while ((cumulativeInvocationCount % 4) != 3) {
                    turnChanged.await();
                }

                printNumber.accept((cumulativeInvocationCount + 1) / 2);
                cumulativeInvocationCount++;
                turnChanged.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        int size = (n / 2) + (n % 2);
        for (int i = 0; i < size; i++) {
            try {
                lock.lock();

                while ((cumulativeInvocationCount % 4) != 1) {
                    turnChanged.await();
                }

                printNumber.accept((cumulativeInvocationCount + 1) / 2);
                cumulativeInvocationCount++;
                turnChanged.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }
}