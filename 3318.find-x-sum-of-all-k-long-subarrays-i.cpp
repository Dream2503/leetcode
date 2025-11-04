/*
 * @lc app=leetcode id=3318 lang=cpp
 *
 * [3318] Find X-Sum of All K-Long Subarrays I
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findXSum(const std::vector<int>& nums, int k, int x) {
        const int size = nums.size();
        std::array<int, 51> hash = {};
        std::vector<int> res;
        std::vector<std::pair<int, int>> window;
        res.reserve(size - k + 1);
        window.reserve(51);

        for (int i = 0; i < k; i++) {
            hash[nums[i]]++;
        }
        for (int i = 0; i <= size - k; i++) {
            int window_sum = 0;
            window.clear();

            for (int j = 1; j <= 50; j++) {
                if (hash[j] > 0) {
                    window.emplace_back(hash[j], j);
                    window_sum += hash[j] * j;
                }
            }
            if (window.size() < x) {
                res.push_back(window_sum);
            } else {
                std::ranges::sort(window, std::ranges::greater());
                res.push_back(std::transform_reduce(window.begin(), window.begin() + x, 0, std::plus(),
                                                    [](const std::pair<int, int>& pair) -> int { return pair.first * pair.second; }));
            }
            if (i + k < size) {
                hash[nums[i]]--;
                hash[nums[i + k]]++;
            }
        }
        return res;
    }
};
// @lc code=end
