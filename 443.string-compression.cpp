/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    int compress(std::vector<char>& chars) {
        std::vector<char> res;
        const int size = chars.size();
        int i = 0;

        while (i < size) {
            int count = 1;
            res.push_back(chars[i++]);

            while (i < size && res.back() == chars[i]) {
                count++;
                i++;
            }
            if (count > 1) {
                for (const char ch : std::to_string(count)) {
                    res.push_back(ch);
                }
            }
        }
        chars = std::move(res);
        return chars.size();
    }
};
// @lc code=end
