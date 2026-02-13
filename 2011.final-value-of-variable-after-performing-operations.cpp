/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
class Solution {
public:
    int finalValueAfterOperations(const std::vector<std::string>& operations) {
        int res = 0;

        for (const std::string& operation : operations) {
            res += operation[1] == '+' ? 1 : -1;
        }
        return res;
    }
};
// @lc code=end
