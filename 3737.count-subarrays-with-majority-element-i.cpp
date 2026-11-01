/*
 * @lc app=leetcode id=3737 lang=cpp
 *
 * [3737] Count Subarrays With Majority Element I
 */

// @lc code=start
class Solution {
public:
    int countMajoritySubarrays(const std::vector<int>& nums, const int target) {
        const int size = nums.size();
        int res = 0;
        std::vector<int> prefix_count;
        prefix_count.reserve(size + 1);
        prefix_count.push_back(0);

        for (const int num : nums) {
            prefix_count.push_back(prefix_count.back() + (num == target));
        }
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j <= size; j++) {
                res += 2 * (prefix_count[j] - prefix_count[i]) > j - i;
            }
        }

        return res;
    }
};
// @lc code=end
