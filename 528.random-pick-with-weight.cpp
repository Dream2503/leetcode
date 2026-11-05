/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
    std::mt19937 rng;
    std::discrete_distribution<> dist;

public:
    Solution(const std::vector<int>& w) : rng(std::random_device()()), dist(w.begin(), w.end()) {}

    int pickIndex() { return dist(rng); }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
