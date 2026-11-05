/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(const std::string& s, const int k) {
        const int size = s.size();
        int left = 0, right = 0, res = 0, max = 0;
        std::array<int, 26> hash{};

        while (right < size) {
            max = std::max(max, ++hash[s[right] - 'A']);

            while (right - left + 1 - max > k) {
                hash[s[left++] - 'A']--;
            }
            res = std::max(res, right - left + 1);
            right++;
        }
        return res;
    }
};
// @lc code=end
