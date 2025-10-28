/*
 * @lc app=leetcode id=1470 lang=cpp
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int> shuffle(const std::vector<int>& nums, const int n) {
        std::vector<int> res;
        res.reserve(2 * n);

        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[n + i]);
        }
        return res;
    }
};
// @lc code=end
