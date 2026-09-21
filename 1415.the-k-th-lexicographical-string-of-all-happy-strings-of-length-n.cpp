/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 */

// @lc code=start
class Solution {
    void generate(std::string& res, int n, int k, int& count) {
        if (res.size() == n) {
            count++;
            return;
        }
        for (const char ch : {'a', 'b', 'c'}) {
            if (res.empty() || res.back() != ch) {
                res.push_back(ch);
                generate(res, n, k, count);

                if (count == k) {
                    return;
                }
                res.pop_back();
            }
        }
    }

public:
    std::string getHappyString(const int n, const int k) {
        int count = 0;
        std::string res;
        generate(res, n, k, count);
        return res;
    }
};
// @lc code=end
