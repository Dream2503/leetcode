/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 */

// @lc code=start
class Solution {
public:
    int triangularSum(std::vector<int>& nums) {
        int size = nums.size();

        while (size > 1) {
            size--;

            for (int i = 0; i < size; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums.pop_back();
        }
        return nums.front();
    }
};
// @lc code=end
