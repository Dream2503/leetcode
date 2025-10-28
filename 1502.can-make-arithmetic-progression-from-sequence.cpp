/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        std::ranges::sort(arr);
        const int size = arr.size(), difference = arr[1] - arr[0];

        for (int i = 1; i < size - 1; i++) {
            if (arr[i + 1] - arr[i] != difference) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
