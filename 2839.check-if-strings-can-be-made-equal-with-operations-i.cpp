/*
 * @lc app=leetcode id=2839 lang=cpp
 *
 * [2839] Check if Strings Can be Made Equal With Operations I
 */

// @lc code=start
class Solution {
public:
    bool canBeEqual(std::string& s1, const std::string& s2) {
        if (s1 == s2) {
            return true;
        }
        std::swap(s1[0], s1[2]);

        if (s1 == s2) {
            return true;
        }
        std::swap(s1[1], s1[3]);

        if (s1 == s2) {
            return true;
        }
        std::swap(s1[0], s1[2]);

        if (s1 == s2) {
            return true;
        }
        return false;
    }
};
// @lc code=end
