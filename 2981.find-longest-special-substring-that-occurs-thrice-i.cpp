/*
 * @lc app=leetcode id=2981 lang=cpp
 *
 * [2981] Find Longest Special Substring That Occurs Thrice I
 */

// @lc code=start
class Solution {
public:
    int maximumLength(const std::string& s) {
        const int size = s.size();
        int res = -1;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j <= size; j++) {
                int str_size = size;
                std::string_view str = s;

                if (const std::string substring = s.substr(i, j - i); std::ranges::count(substring, substring.front()) == j - i) {
                    int cnt = 0;

                    while (!str.empty() && str_size >= j - i) {
                        if (str.starts_with(substring)) {
                            if (++cnt == 3) {
                                res = std::max(res, j - i);
                                break;
                            }
                        }
                        str.remove_prefix(1);
                        str_size--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
