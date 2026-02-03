/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
        const int size = boxTypes.size();
        int i = 0, res = 0;
        std::ranges::sort(boxTypes, std::ranges::greater(), [](const std::vector<int>& box) -> int { return box[1]; });

        while (i < size && truckSize) {
            if (boxTypes[i][0] < truckSize) {
                truckSize -= boxTypes[i][0];
                res += boxTypes[i][0] * boxTypes[i][1];
            } else {
                res += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
