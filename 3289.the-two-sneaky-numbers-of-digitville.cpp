/*
 * @lc app=leetcode id=3289 lang=cpp
 *
 * [3289] The Two Sneaky Numbers of Digitville
 */

// @lc code=start
class Solution {
public:
    std::vector<int> getSneakyNumbers(const std::vector<int>& nums) {
        std::vector hash(nums.size() - 2, false);
        std::vector<int> res;
        res.reserve(2);

        for (const int num : nums) {
            if (!hash[num]) {
                hash[num] = true;
            } else if (res.size() < 2) {
                res.push_back(num);
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
