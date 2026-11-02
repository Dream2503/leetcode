/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */

// @lc code=start
class DetectSquares {
    std::map<std::pair<int, int>, int> grid;

public:
    DetectSquares() {}

    void add(const std::vector<int>& point) { grid[{point[0], point[1]}]++; }

    int count(const std::vector<int>& point) {
        int res = 0;

        for (const auto [x, y] : grid | std::views::keys) {
            if (abs(point[0] - x) != 0 && abs(point[0] - x) == abs(point[1] - y)) {
                const auto a = grid.find({point[0], y}), b = grid.find({x, point[1]});

                if (a != grid.end() && b != grid.end()) {
                    res += grid.at({x, y}) * a->second * b->second;
                }
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end
