/*
 * @lc app=leetcode id=1869 lang=cpp
 *
 * [1869] Longer Contiguous Segments of Ones than Zeros
 */

// @lc code=start
class Solution {
public:
    bool checkZeroOnes(const std::string& s) {
        const int size = s.size();
        int i = 0, max_zero = 0, max_one = 0;

        while (i < size) {
            int current = 1;

            while (i < size - 1 && s[i] == s[i + 1]) {
                current++;
                i++;
            }
            if (s[i] - '0') {
                max_one = std::max(max_one, current);
            } else {
                max_zero = std::max(max_zero, current);
            }
            i++;
        }
        return max_one > max_zero;
    }
};
// @lc code=end
