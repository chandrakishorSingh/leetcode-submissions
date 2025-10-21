class Foo {
    private CountDownLatch latch1 = new CountDownLatch(1);
    private CountDownLatch latch2 = new CountDownLatch(1);
    
    public Foo() {}

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        latch1.countDown();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        latch1.await();
        printSecond.run();
        latch2.countDown();
    }

    public void third(Runnable printThird) throws InterruptedException {
        latch2.await();
        printThird.run();
    }
}