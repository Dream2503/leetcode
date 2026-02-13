/*
 * @lc app=leetcode id=2027 lang=cpp
 *
 * [2027] Minimum Moves to Convert String
 */

// @lc code=start
class Solution {
public:
    int minimumMoves(std::string& s) {
        const int size = s.size();
        int i = 0, res = 0;

        while (i < size) {
            while (i < size && s[i] == 'O') {
                i++;
            }
            if (i < size) {
                i += 3;
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
