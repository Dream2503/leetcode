/*
 * @lc app=leetcode id=1436 lang=cpp
 *
 * [1436] Destination City
 */

// @lc code=start
class Solution {
public:
    std::string destCity(const std::vector<std::vector<std::string>>& paths) {
        std::unordered_map<std::string, int> hash;

        for (const std::vector<std::string>& path : paths) {
            hash[path[0]]++;
            hash[path[1]]--;
        }
        for (const auto& [key, value] : hash) {
            if (value == -1) {
                return key;
            }
        }
        return "";
    }
};
// @lc code=end
