class Foo {
    private int turn = 1;
    private final ReentrantLock lock = new ReentrantLock();
    private final Condition turnChanged = lock.newCondition();
    
    public Foo() {}

    public void first(Runnable printFirst) throws InterruptedException {
        lock.lock();
        
        try {
            printFirst.run();
            turn = 2;
            turnChanged.signalAll();
        } finally {
            lock.unlock();
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock.lock();
        
        try {
            while (turn != 2) {
                turnChanged.await();
            }
            
            printSecond.run();
            turn = 3;
            turnChanged.signalAll();
        } finally {
            lock.unlock();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock.lock();
        
        try {
            while (turn != 3) {
                turnChanged.await();
            }
            
            printThird.run();
        } finally {
            lock.unlock();
        }
        
    }
}