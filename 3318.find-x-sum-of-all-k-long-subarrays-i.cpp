/*
 * @lc app=leetcode id=3318 lang=cpp
 *
 * [3318] Find X-Sum of All K-Long Subarrays I
 */

// @lc code=start
class Solution {
public:
    std::vector<int> findXSum(const std::vector<int>& nums, const int k, const int x) {
        const int size = nums.size();
        int window_sum = 0;
        std::vector<int> res;
        std::vector<std::pair<int, int>> window;
        std::unordered_map<int, int> hash;
        res.reserve(size - k + 1);

        for (int i = 0; i < k; i++) {
            hash[nums[i]]++;
            window_sum += nums[i];
        }
        for (int i = 0; i <= size - k; i++) {
            window.clear();

            for (const auto& [val, cnt] : hash) {
                if (cnt) {
                    window.emplace_back(cnt, val);
                }
            }
            if (window.size() < x) {
                res.push_back(window_sum);
            } else {
                std::ranges::sort(window, std::ranges::greater());
                res.push_back(std::transform_reduce(window.begin(), window.begin() + x, 0, std::plus(),
                                                    [](const std::pair<int, int>& p) -> int { return p.first * p.second; }));
            }
            if (i + k < size) {
                const int out = nums[i], in = nums[i + k];
                hash[out]--;
                hash[in]++;
                window_sum -= out;
                window_sum += in;
            }
        }
        return res;
    }
};
// @lc code=end
