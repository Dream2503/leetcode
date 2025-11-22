/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(const std::vector<int>& nums, const int k) { return at_most(nums, k) - at_most(nums, k - 1); }

    int at_most(const std::vector<int>& nums, const int k) {
        if (k < 0) {
            return 0;
        }
        const int size = nums.size();
        int left = 0, res = 0;
        std::unordered_map<int, int> hash;

        for (int right = 0; right < size; right++) {
            hash[nums[right]]++;

            while (hash.size() > k) {
                if (!--hash[nums[left]]) {
                    hash.erase(nums[left]);
                }
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end
