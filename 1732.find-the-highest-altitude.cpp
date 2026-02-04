/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start
class Solution {
public:
    int largestAltitude(const std::vector<int>& gain) {
        int current = 0, res = 0;

        for (const int element : gain) {
            res = std::max(res, current += element);
        }
        return res;
    }
};
// @lc code=end
