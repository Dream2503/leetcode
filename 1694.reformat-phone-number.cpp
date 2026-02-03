/*
 * @lc app=leetcode id=1694 lang=cpp
 *
 * [1694] Reformat Phone Number
 */

// @lc code=start
class Solution {
public:
    std::string reformatNumber(const std::string& number) {
        int i = 0;
        std::string res;

        for (const char ch: number) {
            if (std::isdigit(ch)) {
                res.push_back(ch);

                if (i == 2) {
                    res.push_back('-');
                }
                i = (i + 1) % 3;
            }
        }
        const int size = res.size();
        int idx = res.find_last_of('-');

        if (idx == size - 1) {
            res.pop_back();
        } else if (idx == size - 2) {
            std::swap(res[idx - 1], res[idx]);
        }
        return res;
    }
};
// @lc code=end

