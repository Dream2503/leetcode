/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution {
public:
    bool canReach(const std::vector<int>& arr, const int start) {
        const int size = arr.size();
        std::vector<uint8_t> seen(size, false);
        std::queue<int> queue;
        queue.push(start);

        while (!queue.empty()) {
            const int index = queue.front();
            queue.pop();

            if (index < 0 || index >= size || seen[index]) {
                continue;
            }
            seen[index] = true;

            if (arr[index] == 0) {
                return true;
            }
            queue.push(index + arr[index]);
            queue.push(index - arr[index]);
        }
        return false;
    }
};
// @lc code=end
