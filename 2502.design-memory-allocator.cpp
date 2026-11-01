/*
 * @lc app=leetcode id=2502 lang=cpp
 *
 * [2502] Design Memory Allocator
 */

// @lc code=start
class Allocator {
    std::vector<int> memory;

public:
    Allocator(const int n) : memory(n, 0) {}

    int allocate(const int size, const int mID) {
        if (size <= 0 || size > memory.size()) {
            return -1;
        }
        int j = 0, count = 0;
        bool found = false;

        for (int i = 0; i < memory.size(); i++) {
            if (memory[i] == 0) {
                count++;

                if (count == size) {
                    found = true;
                    break;
                }
            } else {
                count = 0;
                j = i + 1;
            }
        }
        if (found) {
            for (int i = j; i < j + size; i++) {
                memory[i] = mID;
            }
            return j;
        }
        return -1;
    }

    int freeMemory(const int mID) {
        int res = 0;

        for (int& id : memory) {
            if (id == mID) {
                id = 0;
                res++;
            }
        }
        return res;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
// @lc code=end
