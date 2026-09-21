/*
 * @lc app=leetcode id=2089 lang=cpp
 *
 * [2089] Find Target Indices After Sorting Array
 */

// @lc code=start
class Solution {
public:
    std::vector<int> targetIndices(std::vector<int> nums, int target) {
        std::vector<int> res;
        std::ranges::sort(nums);
        auto start = std::ranges::find(nums, target);

        while (start != nums.end() && *start == target) {
            res.push_back(start++ - nums.begin());
        }
        return res;
    }
};
// @lc code=end
