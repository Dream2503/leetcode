/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    std::string countAndSay(const int n) {
        std::string res = "1";

        for (int i = 1; i < n; i++) {
            std::string temp;
            const int size = res.size();
            int k = 0;

            while (k < size) {
                int j = 1;

                while (k + j < size && res[k] == res[k + j]) {
                    j++;
                }
                temp.push_back('0' + j);
                temp.push_back(res[k]);
                k += j;
            }
            std::swap(res, temp);
        }
        return res;
    }
};
// @lc code=end
