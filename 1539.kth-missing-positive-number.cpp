/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

// @lc code=start
class Solution {
public:
    int findKthPositive(const std::vector<int>& arr, int k) {
        const int size = arr.size();
        int i = 0, missing = 0, n = 0;

        while (i < size && missing < k) {
            n++;

            if (n == arr[i]) {
                i++;
            } else if (n < arr[i]) {
                missing++;
            }
        }
        if (missing < k) {
            return n + k - missing;
        }
        return n;
    }
};
// @lc code=end
