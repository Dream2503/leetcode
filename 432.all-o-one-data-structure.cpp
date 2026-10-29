/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class AllOne {
    struct Bucket {
        int count;
        std::unordered_set<std::string> keys;
        Bucket *prev = nullptr, *next = nullptr;

        explicit Bucket(const int c) : count(c) {}
    } *head, *tail;
    std::unordered_map<std::string, Bucket*> hash;

    void insert_after(Bucket* position, Bucket* node) {
        node->prev = position;
        node->next = position->next;
        position->next->prev = node;
        position->next = node;
    }
    void remove_before(const Bucket* bucket) {
        bucket->prev->next = bucket->next;
        bucket->next->prev = bucket->prev;
        delete bucket;
    }

public:
    AllOne() : head(new Bucket(0)), tail(new Bucket(0)) {
        head->next = tail;
        tail->prev = head;
    }

    ~AllOne() {
        while (head) {
            Bucket* next = head->next;
            delete head;
            head = next;
        }
    }

    void inc(const std::string& key) {
        const auto itr = hash.find(key);

        if (itr == hash.end()) {
            Bucket* target = head->next;

            if (target == tail || target->count != 1) {
                target = new Bucket(1);
                insert_after(head, target);
            }
            target->keys.insert(key);
            hash.emplace(key, target);
            return;
        }
        Bucket *current = itr->second, *target = current->next;

        if (target == tail || target->count != current->count + 1) {
            target = new Bucket(current->count + 1);
            insert_after(current, target);
        }
        target->keys.insert(key);
        itr->second = target;
        current->keys.erase(key);

        if (current->keys.empty()) {
            remove_before(current);
        }
    }

    void dec(const std::string& key) {
        const auto itr = hash.find(key);

        if (itr == hash.end()) {
            return;
        }
        Bucket* current = itr->second;

        if (current->count == 1) {
            current->keys.erase(key);
            hash.erase(itr);

            if (current->keys.empty()) {
                remove_before(current);
            }
            return;
        }
        Bucket* target = current->prev;

        if (target == head || target->count != current->count - 1) {
            target = new Bucket(current->count - 1);
            insert_after(current->prev, target);
        }
        target->keys.insert(key);
        itr->second = target;
        current->keys.erase(key);

        if (current->keys.empty()) {
            remove_before(current);
        }
    }

    std::string getMaxKey() { return tail->prev == head ? "" : *tail->prev->keys.begin(); }

    std::string getMinKey() { return head->next == tail ? "" : *head->next->keys.begin(); }
};


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
