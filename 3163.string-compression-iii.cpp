/*
 * @lc app=leetcode id=3163 lang=cpp
 *
 * [3163] String Compression III
 */

// @lc code=start
class Solution {
public:
    std::string compressedString(const std::string& word) {
        const int size = word.size();
        int i = 0;
        std::string res;

        while (i < size) {
            const char ch = word[i++];
            int count = 1;

            while (i < size && ch == word[i]) {
                count++;
                i++;
            }
            res.append(std::views::repeat(std::format("9{}", ch), count / 9) | std::views::join | std::ranges::to<std::string>());

            if (count % 9) {
                res.append(std::format("{}{}", count % 9, ch));
            }
        }
        return res;
    }
};
// @lc code=end
