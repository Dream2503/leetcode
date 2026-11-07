/*
 * @lc app=leetcode id=3798 lang=cpp
 *
 * [3798] Largest Even Number
 */

// @lc code=start
class Solution {
public:
    std::string& largestEven(std::string& s) {
        while (!s.empty() && s.back() == '1') {
            s.pop_back();
        }
        return s;
    }
};
// @lc code=end
