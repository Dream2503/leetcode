/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */
// @lc code=start
class Solution {
public:
    int findSpecialInteger(const std::vector<int>& arr) {
        const int size = arr.size(), split = size / 4;

        if (size < 4) {
            return arr[0];
        }
        for (int i = 0; i < size - split; i++) {
            if (arr[i] == arr[i + split]) {
                return arr[i];
            }
        }
        return -1;
    }
};
// @lc code=end
