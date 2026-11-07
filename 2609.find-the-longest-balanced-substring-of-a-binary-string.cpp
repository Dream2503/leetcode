/*
 * @lc app=leetcode id=2609 lang=cpp
 *
 * [2609] Find the Longest Balanced Substring of a Binary String
 */

// @lc code=start
class Solution {
public:
    int findTheLongestBalancedSubstring(const std::string& s) {
        const int size = s.size();
        int res = 0, i = 0;

        while (i < size) {
            int count_0 = 0, count_1 = 0;

            while (i < size && s[i] == '1') {
                i++;
            }
            while (i < size && s[i] == '0') {
                count_0++;
                i++;
            }
            while (i < size && s[i] == '1' && count_1 < count_0) {
                count_1++;
                i++;
            }
            res = std::max(res, std::min(count_0, count_1));
        }
        return 2 * res;
    }
};
// @lc code=end
