/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
    std::stack<int> stack, min_stack;

public:
    MinStack() {}

    void push(const int val) {
        stack.push(val);

        if (min_stack.empty() || val <= min_stack.top()) {
            min_stack.push(val);
        }
    }

    void pop() {
        if (stack.top() == min_stack.top()) {
            min_stack.pop();
        }
        stack.pop();
    }

    int top() { return stack.top(); }

    int getMin() { return min_stack.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
