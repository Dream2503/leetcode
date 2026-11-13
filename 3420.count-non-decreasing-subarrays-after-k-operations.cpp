/*
 * @lc app=leetcode id=3420 lang=cpp
 *
 * [3420] Count Non-Decreasing Subarrays After K Operations
 */

// @lc code=start
class Solution {
public:
    int64_t countNonDecreasingSubarrays(const std::vector<int>& nums, const int k) {
        const int size = nums.size();
        std::deque<int> deque;
        int64_t cost = 0, res = 0;
        int j = size - 1;

        for (int i = size - 1; i >= 0; i--) {
            while (!deque.empty() && nums[deque.back()] < nums[i]) {
                const int left = deque.back();
                deque.pop_back();
                const int right = deque.empty() ? j + 1 : deque.back();
                cost += static_cast<int64_t>(right - left) * (nums[i] - nums[left]);
            }
            deque.push_back(i);

            while (cost > k) {
                cost -= nums[deque.front()] - nums[j];

                if (deque.front() == j) {
                    deque.pop_front();
                }
                j--;
            }
            res += j - i + 1;
        }
        return res;
    }
};
// @lc code=end
