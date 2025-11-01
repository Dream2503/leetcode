/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

// @lc code=start
class Solution {
public:
    std::vector<int>& frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> hash;

        for (const int num : nums) {
            hash[num]++;
        }
        std::ranges::sort(nums,
                          [&hash](const int lhs, const int rhs) -> bool { return hash[lhs] < hash[rhs] || hash[lhs] == hash[rhs] && lhs > rhs; });
        return nums;
    }
};
// @lc code=end
