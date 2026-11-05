/*
 * @lc app=leetcode id=3941 lang=cpp
 *
 * [3941] Password Strength
 */

// @lc code=start
class Solution {
public:
    int passwordStrength(std::string& password) {
        std::ranges::sort(password);
        const int size = std::ranges::unique(password).begin() - password.begin();
        return std::ranges::fold_left(password | std::views::take(size), 0, [](const int res, const char ch) -> int {
            if (ch >= 'a' && ch <= 'z') {
                return res + 1;
            }
            if (ch >= 'A' && ch <= 'Z') {
                return res + 2;
            }
            if (ch >= '0' && ch <= '9') {
                return res + 3;
            }
            if (std::ranges::contains(std::string_view("!@#$"), ch)) {
                return res + 5;
            }
            std::unreachable();
        });
    }
};
// @lc code=end
