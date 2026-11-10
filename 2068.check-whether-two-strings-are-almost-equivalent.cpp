/*
 * @lc app=leetcode id=2068 lang=cpp
 *
 * [2068] Check Whether Two Strings are Almost Equivalent
 */

// @lc code=start
class Solution {
public:
    bool checkAlmostEquivalent(const std::string& word1, const std::string& word2) {
        std::array<int, 26> hash1{}, hash2{};

        for (const auto [ch1, ch2] : std::views::zip(word1, word2)) {
            hash1[ch1 - 'a']++;
            hash2[ch2 - 'a']++;
        }
        return std::ranges::all_of(std::views::zip(hash1, hash2),
                                   [&](const std::tuple<int, int>& zip) -> bool { return std::abs(std::get<0>(zip) - std::get<1>(zip)) <= 3; });
    }
};
// @lc code=end
