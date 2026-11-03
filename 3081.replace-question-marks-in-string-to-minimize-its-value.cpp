/*
 * @lc app=leetcode id=3081 lang=cpp
 *
 * [3081] Replace Question Marks in String to Minimize Its Value
 */

// @lc code=start
class Solution {
public:
    std::string minimizeStringValue(std::string& s) {
        std::vector<char> replace;
        std::array<int, 26> hash{};

        for (const char ch : s | std::views::filter([](const char c) -> bool { return c != '?'; })) {
            hash[ch - 'a']++;
        }
        for ([[maybe_unused]] char& _ : s | std::views::filter([](const char ch) -> bool { return ch == '?'; })) {
            const int idx = std::ranges::min_element(hash) - hash.begin();
            replace.push_back(idx + 'a');
            hash[idx]++;
        }
        auto itr = replace.begin();
        std::ranges::sort(replace);

        for (char& ch : s | std::views::filter([](const char c) -> bool { return c == '?'; })) {
            ch = *itr++;
        }
        return s;
    }
};
// @lc code=end
