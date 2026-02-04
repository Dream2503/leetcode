/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
public:
    bool check(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;

        for (int i = 0; i < size; i++) {
            if (nums[i] > nums[(i + 1) % size]) {
                res++;

                if (res > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
