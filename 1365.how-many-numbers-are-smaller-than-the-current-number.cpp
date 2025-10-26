/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& smallerNumbersThanCurrent(std::vector<int>& nums) {
        std::vector<int*> data;
        data.reserve(nums.size());

        for (int& value : nums) {
            data.push_back(&value);
        }
        int last = -1, callback = 0;
        int i = 0;
        std::priority_queue heap([](const int* lhs, const int* rhs) { return *lhs > *rhs; }, std::move(data));

        while (!heap.empty()) {
            if (*heap.top() == last) {
                *heap.top() = --i;
                callback++;
            } else {
                last = *heap.top();
                i += callback;
                callback = 0;
                *heap.top() = i;
            }
            heap.pop();
            i++;
        }
        return nums;
    }
};
// @lc code=end
