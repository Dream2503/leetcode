/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(const std::vector<int>& arr) {
        std::unordered_map<int, int> hash;
        std::unordered_set<int> seen;

        for (const int element : arr) {
            hash[element]++;
        }
        for (const auto& [_, element] : hash) {
            if (!seen.insert(element).second) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
