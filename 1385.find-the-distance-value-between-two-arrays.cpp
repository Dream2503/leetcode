/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

// @lc code=start

class Solution {
public:
    int findTheDistanceValue(const std::vector<int>& arr1, std::vector<int>& arr2, const int d) {
        int res = 0;
        std::ranges::sort(arr2);

        for (const int value : arr1) {
            auto itr = std::ranges::lower_bound(arr2, value - d);

            if (itr == arr2.end() || std::abs(*itr - value) > d) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
