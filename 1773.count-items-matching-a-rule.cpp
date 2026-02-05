/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

// @lc code=start
class Solution {
public:
    int countMatches(const std::vector<std::vector<std::string>>& items, const std::string ruleKey, const std::string ruleValue) {
        int idx;

        if (ruleKey == "type") {
            idx = 0;
        } else if (ruleKey == "color") {
            idx = 1;
        } else {
            idx = 2;
        }
        return std::ranges::count_if(items, [idx, &ruleValue](const std::vector<std::string>& item) -> bool { return item[idx] == ruleValue; });
    }
};
// @lc code=end
