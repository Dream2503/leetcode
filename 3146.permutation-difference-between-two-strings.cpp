/*
 * @lc app=leetcode id=3146 lang=cpp
 *
 * [3146] Permutation Difference between Two Strings
 */

// @lc code=start
class Solution {
public:
    int findPermutationDifference(const std::string& s, const std::string& t) {
        const int size = s.size();
        std::array<int, 26> s_hash{}, t_hash{};

        for (int i = 0; i < size; i++) {
            s_hash[s[i] - 'a'] = t_hash[t[i] - 'a'] = i;
        }
        return std::ranges::fold_left(std::views::zip(s_hash, t_hash), 0, [](const int lhs, const std::tuple<int&, int&>& rhs) -> int {
            return lhs + std::abs(std::get<0>(rhs) - std::get<1>(rhs));
        });
    }
};
// @lc code=end
