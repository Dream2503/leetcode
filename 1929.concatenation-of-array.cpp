/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int> getConcatenation(const std::vector<int>& nums) {
        std::vector<int> res;
        res.reserve(nums.size() * 2);
        res.insert(res.end(), nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());
        return res;
    }
};
// @lc code=end
