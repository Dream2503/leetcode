/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
    struct Bucket {
        int frequency = 0;
        std::list<std::pair<int, int>> entries;
        Bucket *prev = nullptr, *next = nullptr;
    } *head, *tail;
    int capacity;
    std::unordered_map<int, std::pair<Bucket*, std::list<std::pair<int, int>>::iterator>> hash;

    void insertAfter(Bucket* position, Bucket* node) {
        node->prev = position;
        node->next = position->next;
        position->next->prev = node;
        position->next = node;
    }

    void removeBucket(const Bucket* bucket) {
        bucket->prev->next = bucket->next;
        bucket->next->prev = bucket->prev;
        delete bucket;
    }

    void promote(std::pair<Bucket*, std::list<std::pair<int, int>>::iterator>& loc) {
        Bucket *current = loc.first, *target = current->next;

        if (target == tail || target->frequency != current->frequency + 1) {
            target = new Bucket(current->frequency + 1);
            insertAfter(current, target);
        }
        target->entries.splice(target->entries.begin(), current->entries, loc.second);
        loc.first = target;

        if (current->entries.empty()) {
            removeBucket(current);
        }
    }

public:
    LFUCache(const int capacity) : head(new Bucket()), tail(new Bucket()), capacity(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    ~LFUCache() {
        while (head) {
            Bucket* next = head->next;
            delete head;
            head = next;
        }
    }

    int get(const int key) {
        const auto itr = hash.find(key);

        if (itr == hash.end()) {
            return -1;
        }
        const int value = itr->second.second->second;
        promote(itr->second);
        return value;
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }
        if (const auto itr = hash.find(key); itr != hash.end()) {
            itr->second.second->second = value;
            promote(itr->second);
            return;
        }
        if (hash.size() >= capacity) {
            Bucket* least = head->next;
            hash.erase(least->entries.back().first);
            least->entries.pop_back();

            if (least->entries.empty()) {
                removeBucket(least);
            }
        }
        Bucket* bucket = head->next;

        if (bucket == tail || bucket->frequency != 1) {
            bucket = new Bucket(1);
            insertAfter(head, bucket);
        }
        bucket->entries.push_front({key, value});
        hash.emplace(key, std::pair{bucket, bucket->entries.begin()});
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
