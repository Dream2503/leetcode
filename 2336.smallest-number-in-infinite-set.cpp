/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
    std::set<int> numbers;

public:
    SmallestInfiniteSet() : numbers(std::views::iota(1, 1001) | std::ranges::to<std::set<int>>()) {}

    int popSmallest() {
        const int res = *numbers.begin();
        numbers.erase(numbers.begin());
        return res;
    }

    void addBack(const int num) { numbers.insert(num); }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
