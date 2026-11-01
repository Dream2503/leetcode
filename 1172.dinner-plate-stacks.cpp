/*
 * @lc app=leetcode id=1172 lang=cpp
 *
 * [1172] Dinner Plate Stacks
 */

// @lc code=start
class DinnerPlates {
    const int capacity;
    std::vector<std::vector<int>> stack;
    std::set<int> available, non_empty;

public:
    DinnerPlates(const int capacity) : capacity(capacity) {}

    void push(const int val) {
        if (available.empty()) {
            stack.emplace_back();
            available.insert(stack.size() - 1);
        }
        const int idx = *available.begin();
        stack[idx].push_back(val);

        if (stack[idx].size() == capacity) {
            available.erase(idx);
        }
        non_empty.insert(idx);
    }

    int pop() {
        if (non_empty.empty()) {
            return -1;
        }
        return popAtStack(*non_empty.rbegin());
    }

    int popAtStack(const int index) {
        if (index < 0 || index >= stack.size() || stack[index].empty()) {
            return -1;
        }
        const int res = stack[index].back();
        stack[index].pop_back();
        available.insert(index);

        if (stack[index].empty()) {
            non_empty.erase(index);
        }
        return res;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end
