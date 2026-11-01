/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
    std::vector<std::pair<int, int>> events;

public:
    MyCalendar() {}

    bool book(const int startTime, const int endTime) {
        const auto itr = std::ranges::lower_bound(events, startTime, {}, [](const std::pair<int, int>& event) -> int { return event.first; });

        if ((itr != events.begin() && std::prev(itr)->second > startTime) || (itr != events.end() && itr->first < endTime)) {
            return false;
        }
        events.emplace(itr, startTime, endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end
