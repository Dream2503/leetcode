/*
 * @lc app=leetcode id=3637 lang=cpp
 *
 * [3637] Trionic Array I
 */

// @lc code=start
class Solution {
public:
    bool isTrionic(const std::vector<int>& nums) {
        std::array<bool, 3> flags = {};
        const int size = nums.size();
        int i = 1;

        while (i < size && nums[i - 1] < nums[i]) {
            flags[0] = true;
            i++;
        }
        while (i < size && nums[i - 1] > nums[i]) {
            flags[1] = true;
            i++;
        }
        while (i < size && nums[i - 1] < nums[i]) {
            flags[2] = true;
            i++;
        }
        return i == size && flags[0] && flags[1] && flags[2];
    }
};
// @lc code=end
