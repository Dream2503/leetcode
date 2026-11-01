/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
    std::unordered_map<std::string, std::map<int, std::string>> time_map;

public:
    TimeMap() {}

    void set(const std::string& key, const std::string& value, const int timestamp) { time_map[key][timestamp] = value; }

    std::string get(const std::string& key, const int timestamp) {
        if (!time_map.contains(key)) {
            return "";
        }
        const auto& events = time_map.at(key);
        const auto itr = events.upper_bound(timestamp);

        if (itr == events.begin()) {
            return "";
        }
        return std::prev(itr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
