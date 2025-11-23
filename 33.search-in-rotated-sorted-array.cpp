/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(const std::vector<int>& nums, const int target) {
        const int size = nums.size();
        int low = 0, high = size - 1;

        while (low < high) {
            const int mid = (high + low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        const auto itr1 = std::lower_bound(nums.begin(), nums.begin() + low, target);

        if (itr1 != nums.begin() + low && *itr1 == target) {
            return itr1 - nums.begin();
        }
        const auto itr2 = std::lower_bound(nums.begin() + low, nums.end(), target);

        if (itr2 != nums.end() && *itr2 == target) {
            return itr2 - nums.begin();
        }
        return -1;
    }
};
// @lc code=end
