/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
class Solution {
public:
    int countCharacters(const std::vector<std::string>& words, const std::string& chars) {
        static std::array<char, 26> main, temp;
        bool broke = false;
        int res = 0;
        main.fill(0);

        for (const char ch : chars) {
            main[ch - 'a']++;
        }
        for (const std::string& word : words) {
            temp.fill(0);

            for (const char ch : word) {
                if (temp[ch - 'a'] != main[ch - 'a']) {
                    temp[ch - 'a']++;
                } else {
                    broke = true;
                    break;
                }
            }
            if (!broke) {
               res += word.length();
            }
            broke = false;
        }
        return res;
    }
};
// @lc code=end
