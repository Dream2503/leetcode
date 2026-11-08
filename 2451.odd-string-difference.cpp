/*
 * @lc app=leetcode id=2451 lang=cpp
 *
 * [2451] Odd String Difference
 */

// @lc code=start
class Solution {
public:
    std::string oddString(const std::vector<std::string>& words) {
        std::unordered_multimap<std::string, std::string> hash;

        for (std::string word : words) {
            const char factor = word.front();
            std::string temp = word;

            for (char& ch : word) {
                ch -= factor;
            }
            hash.emplace(word, std::move(temp));
        }
        return (hash |
                std::views::filter([&hash](const std::pair<std::string, std::string>& element) -> bool { return hash.count(element.first) == 1; }))
            .begin()
            ->second;
    }
};
// @lc code=end
