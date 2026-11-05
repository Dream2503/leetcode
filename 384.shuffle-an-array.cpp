/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
class Solution {
    const std::vector<int>& nums;
    std::vector<int> last;
    std::mt19937 rng;

public:
    Solution(const std::vector<int>& nums) : nums(nums), last(nums), rng(std::random_device{}()) {}

    std::vector<int>& reset() { return last = nums; }

    std::vector<int>& shuffle() {
        std::ranges::shuffle(last, rng);
        return last;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
