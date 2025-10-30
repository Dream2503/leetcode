/*
 * @lc app=leetcode id=1566 lang=cpp
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */

// @lc code=start
class Solution {
public:
    bool containsPattern(const std::vector<int>& arr, const int m, const int k) {
        const int size = arr.size();

        for (int i = 0; i < size; i++) {
            bool flag = true;
            int res = 1, j = i + m;

            while (j <= size - m) {
                for (int l = 0; l < m; l++) {
                    if (arr[i + l] != arr[j + l]) {
                        flag = false;
                        break;
                    }
                }
                if (flag && j + m <= size) {
                    res++;
                    j += m;
                } else {
                    break;
                }
                if (res == k) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
