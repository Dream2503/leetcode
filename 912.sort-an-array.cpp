/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
    void quick_sort(std::vector<int>& nums, const int low, const int high) {
        if (low < high) {
            const int pivot = nums[(low + high) / 2];
            int i = low, j = high;

            while (i <= j) {
                while (nums[i] < pivot) {
                    i++;
                }
                while (nums[j] > pivot) {
                    j--;
                }
                if (i <= j) {
                    std::swap(nums[i++], nums[j--]);
                }
            }
            quick_sort(nums, low, i - 1);
            quick_sort(nums, i, high);
        }
    }

public:
    std::vector<int>& sortArray(std::vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
        return nums;
        // std::sort(nums.begin(), nums.end());
        // return nums;
    }
};
// @lc code=end
