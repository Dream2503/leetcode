/*
 * @lc app=leetcode id=1114 lang=java
 *
 * [1114] Print in Order
 */

// @lc code=start
class Foo {
    private int step = 1;

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        step = 2;
        notifyAll();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        while (step < 2) {
            wait();
        }
        printSecond.run();
        step = 3;
        notifyAll();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        while (step < 3) {
            wait();
        }
        printThird.run();
    }
}
// @lc code=end
