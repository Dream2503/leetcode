/*
 * @lc app=leetcode id=3659 lang=cpp
 *
 * [3659] Partition Array Into K-Distinct Groups
 */

// @lc code=start
class Solution {
public:
    bool partitionArray(const std::vector<int>& nums, const int k) {
        const int size = nums.size();

        if (size % k != 0) {
            return false;
        }
        std::unordered_map<int, int> frequency;

        for (const int num : nums) {
            frequency[num]++;
        }
        const int groups = size / k;

        for (const int& freq : frequency | std::views::values) {
            if (freq > groups) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
