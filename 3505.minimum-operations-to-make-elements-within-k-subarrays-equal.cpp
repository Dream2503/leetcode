/*
 * @lc app=leetcode id=3505 lang=cpp
 *
 * [3505] Minimum Operations to Make Elements Within K Subarrays Equal
 */

// @lc code=start
class Solution {
    void prune(auto& heap, std::unordered_map<int, int>& delayed) {
        while (!heap.empty()) {
            if (delayed[heap.top()]) {
                --delayed[heap.top()];
                heap.pop();
            } else {
                break;
            }
        }
    }

public:
    long long minOperations(const std::vector<int>& nums, const int x, const int k) {
        const int size = nums.size();
        std::priority_queue<int> left;
        std::priority_queue<int, std::vector<int>, std::greater<int>> right;
        std::unordered_map<int, int> delayed;
        int left_size = 0, right_size = 0;
        std::vector<int64_t> ops(size);
        int64_t sum_left = 0, sum_right = 0;

        auto balance = [&]() -> void {
            if (left_size > right_size + 1) {
                const int num = left.top();
                right.push(num);
                sum_right += num;
                sum_left -= num;
                left.pop();
                right_size++;
                left_size--;
                prune(left, delayed);
            } else if (right_size > left_size) {
                const int num = right.top();
                left.push(num);
                sum_left += num;
                sum_right -= num;
                right.pop();
                left_size++;
                right_size--;
                prune(right, delayed);
            }
        };
        for (int i = 0; i < size; i++) {
            if (left.empty() || nums[i] <= left.top()) {
                left.push(nums[i]);
                left_size++;
                sum_left += nums[i];
            } else {
                right.push(nums[i]);
                right_size++;
                sum_right += nums[i];
            }
            balance();

            if (i >= x) {
                if (const int num = nums[i - x]; num <= left.top()) {
                    left_size--;
                    delayed[num]++;
                    sum_left -= num;

                    if (num == left.top()) {
                        prune(left, delayed);
                    }
                } else {
                    right_size--;
                    delayed[num]++;
                    sum_right -= num;

                    if (num == right.top()) {
                        prune(right, delayed);
                    }
                }
                balance();
            }
            if (i >= x - 1) {
                ops[i] = sum_right - sum_left + left.top() * (left_size - right_size);
            }
        }
        std::vector dp(size, std::vector(k + 1, INT64_MAX));

        for (int i = 0; i < size; i++) {
            dp[i][0] = 0;
        }
        for (int j = 1; j <= k; j++) {
            if (j == 1) {
                dp[x - 1][j] = ops[x - 1];
            } else {
                dp[j * x - 1][j] = dp[(j - 1) * x - 1][j - 1] + ops[j * x - 1];
            }
        }
        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i < size; i++) {
                dp[i][j] = std::min(dp[i - x][j - 1] + ops[i], dp[i - 1][j]);
            }
        }
        return dp[size - 1][k];
    }
};
// @lc code=end
