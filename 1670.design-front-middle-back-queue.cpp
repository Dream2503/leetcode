/*
 * @lc app=leetcode id=1670 lang=cpp
 *
 * [1670] Design Front Middle Back Queue
 */

// @lc code=start

class FrontMiddleBackQueue {
    int middle;
    std::list<int> queue;
    std::list<int>::iterator itr;

public:
    FrontMiddleBackQueue() : middle(-1), itr(queue.end()) {}

    void pushFront(const int val) {
        const int size = queue.size();
        queue.push_front(val);

        if (size == 0) {
            itr = queue.begin();
            middle = 0;
        } else if (size % 2 != 0) {
            --itr;
        } else {
            middle++;
        }
    }

    void pushMiddle(const int val) {
        if (const int size = queue.size(); size == 0) {
            queue.push_front(val);
            itr = queue.begin();
            middle = 0;
        } else if (size % 2 != 0) {
            itr = queue.insert(itr, val);
        } else {
            itr = queue.insert(std::next(itr), val);
            middle++;
        }
    }

    void pushBack(const int val) {
        const int size = queue.size();
        queue.push_back(val);

        if (size == 0) {
            itr = queue.begin();
            middle = 0;
        } else if (size % 2 == 0) {
            ++itr;
            middle++;
        }
    }

    int popFront() {
        if (queue.empty()) {
            return -1;
        }
        const int res = queue.front(), size = queue.size();

        if (size == 1) {
            queue.pop_front();
            itr = queue.end();
            middle = -1;
            return res;
        }
        if (size % 2 != 0) {
            middle--;
        } else {
            ++itr;
        }
        queue.pop_front();
        return res;
    }

    int popMiddle() {
        if (queue.empty()) {
            return -1;
        }
        const int res = *itr, size = queue.size();
        const auto current = itr;

        if (size == 1) {
            queue.erase(current);
            itr = queue.end();
            middle = -1;
            return res;
        }
        if (size % 2 != 0) {
            --itr;
            middle--;
        } else {
            ++itr;
        }
        queue.erase(current);
        return res;
    }

    int popBack() {
        if (queue.empty()) {
            return -1;
        }
        const int res = queue.back(), size = queue.size();

        if (size == 1) {
            queue.pop_back();
            itr = queue.end();
            middle = -1;
            return res;
        }
        if (size % 2 != 0) {
            --itr;
            middle--;
        }
        queue.pop_back();
        return res;
    }
};


/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end
