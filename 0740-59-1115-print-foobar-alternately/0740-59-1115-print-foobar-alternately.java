class FooBar {
    private int n;
    private int turn = 0;
    private final ReentrantLock lock = new ReentrantLock();
    private final Condition turnChanged = lock.newCondition();

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            try {
                lock.lock();
                
                while (turn != 0) {
                    turnChanged.await();
                }
                
                // printFoo.run() outputs "foo". Do not change or remove this line.
                printFoo.run();
                turn = 1;
                turnChanged.signal();
            } finally {
                lock.unlock();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            try {
                lock.lock();
                
                while (turn != 1) {
                    turnChanged.await();
                }
                
                // printBar.run() outputs "bar". Do not change or remove this line.
                printBar.run();
                turn = 0;
                turnChanged.signal();
            } finally {
                lock.unlock();
            }
            
        }
    }
}