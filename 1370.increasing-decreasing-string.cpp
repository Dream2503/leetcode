/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 */

// @lc code=start
class Solution {
public:
    std::string& sortString(std::string& s) {
        bool done = false;
        int i = 0;
        std::array<int, 26> hash = {};

        for (const char ch : s) {
            hash[ch - 'a']++;
        }
        while (!done) {
            done = true;

            for (int j = 0; j < 26; j++) {
                if (hash[j]) {
                    s[i++] = 'a' + j;
                    hash[j]--;
                    done = false;
                }
            }
            for (int j = 25; j >= 0; j--) {
                if (hash[j]) {
                    s[i++] = 'a' + j;
                    hash[j]--;
                    done = false;
                }
            }
        }
        return s;
    }
};
// @lc code=end
