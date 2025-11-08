/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(const std::vector<std::vector<int>>& rooms) {
        const int size = rooms.size();
        std::vector<uint8_t> visited(size, 0);
        std::queue<int> queue;

        for (const int key : rooms.front()) {
            queue.push(key);
        }
        visited.front() = true;

        while (!queue.empty()) {
            const int current = queue.front();
            queue.pop();
            visited[current] = true;

            for (const int key : rooms[current]) {
                if (!visited[key]) {
                    queue.push(key);
                }
            }
        }
        return std::ranges::count(visited, 1) == size;
    }
};
// @lc code=end
