/*
 * @lc app=leetcode id=1656 lang=cpp
 *
 * [1656] Design an Ordered Stream
 */

// @lc code=start
class OrderedStream {
    int ptr, size;
    std::vector<std::string> container;

public:
    OrderedStream(const int n) : ptr(0), size(n), container(size) {}

    std::vector<std::string> insert(const int idKey, const std::string& value) {
        std::vector<std::string> res;
        container[idKey - 1] = value;

        while (ptr < size && !container[ptr].empty()) {
            res.push_back(container[ptr++]);
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end
