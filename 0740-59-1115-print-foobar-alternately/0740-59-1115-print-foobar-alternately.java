class FooBar {
    private int n;
    private volatile int turn = 0;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (turn != 0) {}
            
        	// printFoo.run() outputs "foo". Do not change or remove this line.
        	printFoo.run();
            turn = 1;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while (turn != 1) {}
            
            // printBar.run() outputs "bar". Do not change or remove this line.
        	printBar.run();
            turn = 0;
        }
    }
}