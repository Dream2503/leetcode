/*
 * @lc app=leetcode id=2864 lang=cpp
 *
 * [2864] Maximum Odd Binary Number
 */

// @lc code=start
class Solution {
public:
    std::string& maximumOddBinaryNumber(std::string& s) {
        const int size = s.size(), ones = std::ranges::count(s, '1');
        s.clear();
        return s.append(ones - 1, '1').append(size - ones, '0').append("1");
    }
};
// @lc code=end
