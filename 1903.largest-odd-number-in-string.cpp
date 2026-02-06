/*
 * @lc app=leetcode id=1903 lang=cpp
 *
 * [1903] Largest Odd Number in String
 */

// @lc code=start
class Solution {
public:
    std::string& largestOddNumber(std::string& num) {
        while (!num.empty() && (num.back() - '0') % 2 == 0) {
            num.pop_back();
        }
        return num;
    }
};
// @lc code=end
