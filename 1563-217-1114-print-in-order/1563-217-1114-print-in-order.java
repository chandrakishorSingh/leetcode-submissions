class Foo {
    private Semaphore gate2 = new Semaphore(0);
    private Semaphore gate3 = new Semaphore(0);

    public Foo() {}

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        gate2.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        gate2.acquire();
        printSecond.run();
        gate3.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        gate3.acquire();
        printThird.run();
    }
}