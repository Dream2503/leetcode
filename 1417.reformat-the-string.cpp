/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 */

// @lc code=start
class Solution {
public:
    std::string& reformat(std::string& s) {
        std::array<int, 26> alphabets = {};
        std::array<int, 10> digits = {};

        for (const char ch : s) {
            if (isalpha(ch)) {
                alphabets[ch - 'a']++;
            } else {
                digits[ch - '0']++;
            }
        }
        const int alpha_count = std::reduce(alphabets.begin(), alphabets.end(), 0), digit_count = std::reduce(digits.begin(), digits.end(), 0);

        if (std::abs(alpha_count - digit_count) > 1) {
            s.clear();
        } else {
            int k = alpha_count > digit_count ? 0 : 1;

            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < alphabets[i]; j++) {
                    s[k] = 'a' + i;
                    k += 2;
                }
            }
            k = alpha_count > digit_count ? 1 : 0;

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < digits[i]; j++) {
                    s[k] = '0' + i;
                    k += 2;
                }
            }
        }
        return s;
    }
};
// @lc code=end
