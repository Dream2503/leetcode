/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(const std::string& s1, const std::string& s2) {
        const int size = s1.size();
        int i, j;

        for (i = 0; i < size; i++) {
            if (s1[i] != s2[i]) {
                break;
            }
        }
        for (j = i + 1; j < size; j++) {
            if (s1[j] != s2[j]) {
                break;
            }
        }
        for (int k = j + 1; k < size; k++) {
            if (s1[k] != s2[k]) {
                return false;
            }
        }
        if (i >= size) {
            return true;
        }
        if (j >= size) {
            return false;
        }
        return s1[i] == s2[j] && s1[j] == s2[i];
    }
};
// @lc code=end
