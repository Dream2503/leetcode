/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
class Solution {
public:
    int numberOfBeams(const std::vector<std::string>& bank) {
        const int size = bank.size();
        int i = 0, prev = 0, res = 0;

        while (i < size && !prev) {
            prev = std::ranges::count(bank[i], '1');
            i++;
        }
        while (i < size) {
            int current = 0;

            while (i < size && !current) {
                current = std::ranges::count(bank[i], '1');
                i++;
            }
            res += prev * current;
            prev = current;
        }
        return res;
    }
};
// @lc code=end
