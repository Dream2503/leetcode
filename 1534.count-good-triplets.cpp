/*
 * @lc app=leetcode id=1534 lang=cpp
 *
 * [1534] Count Good Triplets
 */

// @lc code=start
class Solution {
public:
    int countGoodTriplets(const std::vector<int>& arr, const int a, const int b, const int c) {
        const int size = arr.size();
        int res = 0;

        for (int i = 0; i < size - 2; i++) {
            for (int j = i + 1; j < size - 1; j++) {
                if (std::abs(arr[i] - arr[j]) <= a) {
                    for (int k = j + 1; k < size; k++) {
                        res += std::abs(arr[j] - arr[k]) <= b && std::abs(arr[i] - arr[k]) <= c;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
