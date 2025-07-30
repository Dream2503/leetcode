/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
class Solution {
public:
    int distanceBetweenBusStops(const std::vector<int>& distance, const int start, const int destination) {
        const int size = distance.size();
        int i = start, j = start, distance1 = 0, distance2 = 0;

        while (i != destination || j != destination) {
            if (i != destination) {
                distance1 += distance[i];
                i = (i + 1) % size;
            }
            if (j != destination) {
                j = (j + size - 1) % size;
                distance2 += distance[j];
            }
        }
        return std::min(distance1, distance2);
    }
};
// @lc code=end
