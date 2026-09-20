/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 */

// @lc code=start
class Solution {
public:
    std::vector<int> getAverages(const std::vector<int>& nums, const int k) {
        if (k == 0) {
            return nums;
        }
        const int size = nums.size(), diameter = 2 * k + 1;

        if (diameter > size) {
            return std::vector(size, -1);
        }
        std::vector<int> res(size);

        for (int i = 0; i < k; i++) {
            res[i] = res[size - i - 1] = -1;
        }
        uint64_t sum = std::ranges::fold_left(nums | std::views::take(diameter), 0ull, std::plus());

        for (int i = k; i < size - k; i++) {
            res[i] = sum / diameter;
            sum -= nums[i - k];

            if (i + k + 1 < size) {
                sum += nums[i + k + 1];
            }
        }
        return res;
    }
};
// @lc code=end
