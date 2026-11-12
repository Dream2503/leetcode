/*
 * @lc app=leetcode id=4048 lang=cpp
 *
 * [4048] Count Values With Equally Spaced Occurrences I
 */

// @lc code=start
class Solution {
public:
    int countSpecialIntegers(const std::vector<int>& nums) {
        const int size = nums.size();
        int res = 0;
        std::unordered_map<int, std::vector<int>> hash;

        for (int i = 0; i < size; i++) {
            hash[nums[i]].push_back(i);
        }
        return std::ranges::count_if(hash | std::views::values, [](const std::vector<int>& value) -> bool {
            return value.size() == 3 && value[1] - value[0] == value[2] - value[1];
        });
    }
};
// @lc code=end
