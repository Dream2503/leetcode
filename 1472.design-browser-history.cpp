/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
    std::vector<std::string> history;
    int position, size;

public:
    BrowserHistory(const std::string& homepage) : history{homepage}, position(0), size(1) {}

    void visit(const std::string& url) {
        if (++position == history.size()) {
            history.push_back(url);
            size = history.size();
        } else {
            size = position + 1;
            history[position] = url;
        }
    }

    std::string back(const int steps) { return history[position = std::max(0, position - steps)]; }

    std::string forward(const int steps) { return history[position = std::min(size - 1, position + steps)]; }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
