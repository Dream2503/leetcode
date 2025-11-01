/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
    int i;
    std::stack<std::pair<int, int>> stack;

public:
    StockSpanner() : i(0) {}

    int next(int price) {
        while (!stack.empty() && price >= stack.top().second) {
            stack.pop();
        }
        const int res = stack.empty() ? i + 1 : i - stack.top().first;
        stack.emplace(i++, price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
