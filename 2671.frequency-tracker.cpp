/*
 * @lc app=leetcode id=2671 lang=cpp
 *
 * [2671] Frequency Tracker
 */

// @lc code=start
class FrequencyTracker {
    std::unordered_map<int, int> freq;
    std::unordered_map<int, std::unordered_set<int>> inverse;

public:
    FrequencyTracker() {}

    void add(const int number) {
        const int prev = freq[number];

        if (prev != 0) {
            inverse[prev].erase(number);
        }
        inverse[++freq[number]].insert(number);
    }

    void deleteOne(const int number) {
        const int prev = freq[number];

        if (prev > 0) {
            inverse[prev].erase(number);
            inverse[--freq[number]].insert(number);
        }
    }

    bool hasFrequency(const int frequency) { return !inverse[frequency].empty(); }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end
