/*
 * @lc app=leetcode id=284 lang=cpp
 *
 * [284] Peeking Iterator
 */

// @lc code=start
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    std::optional<int> next_cache;

    PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
        if (Iterator::hasNext()) {
            next_cache = Iterator::next();
        }
    }

    int peek() { return next_cache.value(); }

    int next() {
        const int temp = next_cache.value();
        next_cache = Iterator::hasNext() ? Iterator::next() : std::optional<int>();
        return temp;
    }

    bool hasNext() const { return next_cache.has_value(); }
};
// @lc code=end
