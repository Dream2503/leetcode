/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

// @lc code=start
class Solution {
public:
    bool makeEqual(const std::vector<std::string>& words) {
        const int size = words.size();
        std::array<int, 26> freq = {};

        for (const std::string& word : words) {
            for (const char ch : word) {
                freq[ch - 'a']++;
            }
        }
        return std::ranges::all_of(freq, [size](const int element) -> bool { return element % size == 0; });
    }
};
// @lc code=end
