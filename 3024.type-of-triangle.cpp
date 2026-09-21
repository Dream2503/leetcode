/*
 * @lc app=leetcode id=3024 lang=cpp
 *
 * [3024] Type of Triangle
 */

// @lc code=start
class Solution {
public:
    std::string triangleType(const std::vector<int>& nums) {
        if (nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[2] + nums[0] > nums[1]) {
            if (nums[0] == nums[1] && nums[1] == nums[2] && nums[2] == nums[0]) {
                return "equilateral";
            }
            if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
                return "isosceles";
            }
            return "scalene";
        }
        return "none";
    }
};
// @lc code=end
