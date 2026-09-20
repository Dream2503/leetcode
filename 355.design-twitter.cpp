/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
    std::vector<std::pair<int, int>> posts;
    std::unordered_map<int, std::unordered_set<int>> follows;

public:
    Twitter() {}

    void postTweet(const int userId, const int tweetId) { posts.push_back({userId, tweetId}); }

    std::vector<int> getNewsFeed(const int userId) {
        std::unordered_set<int>& users = follows[userId];
        users.insert(userId);

        return posts | std::views::reverse |
            std::views::filter([&users](const std::pair<int, int>& element) -> bool { return users.contains(element.first); }) |
            std::views::take(10) | std::views::values | std::ranges::to<std::vector<int>>();
    }

    void follow(const int followerId, const int followeeId) { follows[followerId].insert(followeeId); }

    void unfollow(const int followerId, const int followeeId) { follows[followerId].erase(followeeId); }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
