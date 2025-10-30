/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
class Solution {
public:
    std::vector<int> mostVisited(const int n, const std::vector<int>& rounds) {
        int current = rounds[0] - 1;
        std::vector<int> track(n);

        for (const int round : rounds) {
            while (current != (round - 1)) {
                track[current++]++;
                
                if (current == n) {
                    current = 0;
                }
            }
        }
        track[current]++;
        const int max = *std::ranges::max_element(track);
        std::vector<int> res;

        for (int i = 0; i < n; i++) {
            if (track[i] == max) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end
