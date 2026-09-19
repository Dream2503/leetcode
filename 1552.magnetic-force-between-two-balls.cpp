/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution {
public:
    int maxDistance(std::vector<int>& position, const int m) {
        std::ranges::sort(position);
        int low = 1, high = position.back() - position.front();

        while (low <= high) {
            const int mid = (low + high) / 2;
            int balls = 1, last = position.front();

            for (const int pos : position) {
                if (pos - last >= mid) {
                    balls++;
                    last = pos;
                }
                if (balls >= m) {
                    break;
                }
            }
            if (balls >= m) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};
// @lc code=end
