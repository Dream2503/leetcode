/*
 * @lc app=leetcode id=2899 lang=cpp
 *
 * [2899] Last Visited Integers
 */

// @lc code=start
class Solution {
public:
    std::vector<int> lastVisitedIntegers(const std::vector<int>& nums) {
        int k = 0;
        std::vector<int> seen, res;

        for (const int num : nums) {
            if (num == -1) {
                res.push_back(seen.size() < ++k ? -1 : seen[seen.size() - k]);
            } else {
                k = 0;
                seen.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end
