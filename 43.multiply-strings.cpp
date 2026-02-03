/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    std::string multiply(const std::string& num1, const std::string& num2) {
        const int size1 = num1.size(), size2 = num2.size();
        int shift = 0, carry = 0;
        std::string res;

        for (int i = size2 - 1; i >= 0; i--) {
            int k = shift;

            while (k > res.size()) {
                res.push_back('0');
            }
            for (int j = size1 - 1; j >= 0; j--) {
                int prod = (num1[j] - '0') * (num2[i] - '0') + carry;

                if (k == res.size()) {
                    res.push_back(prod % 10 + '0');
                } else {
                    prod += res[k] - '0';
                    res[k] = prod % 10 + '0';
                }
                k++;
                carry = prod / 10;
            }
            while (carry) {
                if (k == res.size()) {
                    res.push_back(carry + '0');
                    carry = 0;
                } else {
                    carry += res[k] - '0';
                    res[k] = carry % 10 + '0';
                    carry /= 10;
                }
                k++;
            }
            while (!(res.empty() || res.back() - '0')) {
                res.pop_back();
            }
            shift++;
        }
        std::ranges::reverse(res);
        return res.empty() ? "0" : res;
    }
};
// @lc code=end
