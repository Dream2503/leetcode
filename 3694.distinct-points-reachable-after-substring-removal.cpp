/*
 * @lc app=leetcode id=3694 lang=cpp
 *
 * [3694] Distinct Points Reachable After Substring Removal
 */

// @lc code=start
class Solution {
public:
    int distinctPoints(std::string& s, const int k) {
        const int size = s.size();
        std::unordered_set<uint64_t> seen;
        seen.insert(0);
        int x = 0, y = 0;

        for (int i = k; i < size; i++) {
            if (s[i] == 'U') {
                y++;
            }
            if (s[i] == 'D') {
                y--;
            }
            if (s[i] == 'L') {
                x++;
            }
            if (s[i] == 'R') {
                x--;
            }
            if (s[i - k] == 'U') {
                y--;
            }
            if (s[i - k] == 'D') {
                y++;
            }
            if (s[i - k] == 'L') {
                x--;
            }
            if (s[i - k] == 'R') {
                x++;
            }
            seen.insert((static_cast<uint64_t>(x) << 32) + y);
        }
        return seen.size();
    }
};
// @lc code=end
