class H2O {
    private int remainingHydrogenCount;
    private int remainingOxygenCount;
    private ReentrantLock lock;
    private Condition condition;
    
    public H2O() {
        remainingHydrogenCount = 2;
        remainingOxygenCount = 1;
        lock = new ReentrantLock();
        condition = lock.newCondition();
    }

    private boolean isMoleculeFormed() {
        return (remainingHydrogenCount == 0) && (remainingOxygenCount == 0);
    }
    
    private void resetHydrogenAndOxygenCount() {
        remainingHydrogenCount = 2;
        remainingOxygenCount = 1;
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        try {
            lock.lock();
            
            while (remainingHydrogenCount == 0) {
                condition.await();
            }
            
            // releaseHydrogen.run() outputs "H". Do not change or remove this line.
            releaseHydrogen.run();
            remainingHydrogenCount--;
            
            if (isMoleculeFormed()) {
                resetHydrogenAndOxygenCount();
            }
            condition.signalAll();
        } finally {
            lock.unlock();
        }
		
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        try {
            lock.lock();
            
            while (remainingOxygenCount == 0) {
                condition.await();
            }
            
            // releaseOxygen.run() outputs "O". Do not change or remove this line.
            releaseOxygen.run();
            remainingOxygenCount--;
            
            if (isMoleculeFormed()) {
                resetHydrogenAndOxygenCount();
            }
            condition.signalAll();
        } finally {
            lock.unlock();
        }
        
    }
}