/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
class Solution {
    std::vector<std::string> allParenthesis(const std::vector<int>& nums, const int start, const int end) {
        std::vector<std::string> result;

        if (start == end) {
            result.push_back(std::to_string(nums[start]));
        } else {
            for (int i = start; i < end; ++i) {
                std::vector<std::string> left = allParenthesis(nums, start, i);
                std::vector<std::string> right = allParenthesis(nums, i + 1, end);

                for (auto& l : left) {
                    for (auto& r : right) {
                        result.push_back("(" + l + " + " + r + ")");
                    }
                }
            }
        }
        return result;
    }

public:
    std::vector<int> diffWaysToCompute(std::string expression) {
        std::vector<int> nums;
        std::vector<std::string> exprs = allParenthesis(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
