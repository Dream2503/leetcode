/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 */

// @lc code=start
class Solution {
public:
    bool checkOnesSegment(const std::string& s) {
        const int size = s.size();
        int i = 0;

        while (i < size && s[i] == '1') {
            i++;
        }
        while (i < size && s[i] == '0') {
            i++;
        }
        return i >= size;
    }
};
// @lc code=end

