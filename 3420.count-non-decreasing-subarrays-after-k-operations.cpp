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
        int64_t res = 0, operations = 0;
        std::priority_queue<std::pair<int, int>> heap;
        std::vector<std::vector<int>> count(size);
        std::vector position(size, size);
        std::stack<int> stack;

        for (int left = 0, right = 0; right < size; right++) {
            while (!stack.empty() && nums[right] >= nums[stack.top()]) {
                position[stack.top()] = right;
                stack.pop();
            }
            if (!stack.empty()) {
                count[stack.top()].push_back(right);
            }
            stack.push(right);
            heap.emplace(nums[right], right);
            operations += std::max(0, heap.top().first - nums[right]);

            while (operations > k) {
                for (const int i : count[left]) {
                    operations -= static_cast<int64_t>(nums[left] - nums[i]) * (std::min(position[i], right + 1) - i);
                }
                left++;
            }
            while (!heap.empty() && heap.top().second < left) {
                heap.pop();
            }
            res += right - left + 1;
        }
        return res;
    }
};
// @lc code=end
