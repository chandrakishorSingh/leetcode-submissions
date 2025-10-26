class DiningPhilosophers {
    private boolean[] isForkAvailable;
    private ReentrantLock lock;
    private Condition condition;

    public DiningPhilosophers() {
        this.isForkAvailable = new boolean[]{true, true, true, true, true};
        this.lock = new ReentrantLock();
        this.condition = lock.newCondition();
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
                           Runnable pickLeftFork,
                           Runnable pickRightFork,
                           Runnable eat,
                           Runnable putLeftFork,
                           Runnable putRightFork) throws InterruptedException {
        try {
            int leftFork = (philosopher + 4) % 5;
            int rightFork = philosopher;
            
            lock.lock();
            
            while (!this.isForkAvailable[leftFork] || !this.isForkAvailable[rightFork]) {
                this.condition.await();
            }
            
            pickLeftFork.run();
            pickRightFork.run();
            eat.run();
            putLeftFork.run();
            putRightFork.run();
            
            this.isForkAvailable[leftFork] = true;
            this.isForkAvailable[rightFork] = true;
            this.condition.signalAll();
        } finally {
            lock.unlock();
        }
    }
}