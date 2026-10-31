/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
class Solution {
    void generate(const int num, const int n, std::vector<int>& res) {
        if (num > n) {
            return;
        }
        if (num != 0) {
            res.push_back(num);
        }
        for (int i = num == 0; i < 10; i++) {
            generate(num * 10 + i, n, res);
        }
    }

public:
    std::vector<int> lexicalOrder(const int n) {
        std::vector<int> res;
        res.reserve(n);
        generate(0, n, res);
        return res;
    }
};
// @lc code=end
