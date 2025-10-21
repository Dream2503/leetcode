#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : ListNode(0, nullptr) {}
    ListNode(const int val) : ListNode(val, nullptr) {}
    ListNode(const int val, ListNode* next) : val(val), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : TreeNode(0, nullptr, nullptr) {}
    TreeNode(const int val) : TreeNode(val, nullptr, nullptr) {}
    TreeNode(const int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

// class Node {
// public:
//     int val;
//     Node *next, random;
//
//     Node(const int val) : val(val), next(nullptr), random(nullptr) {}
// };

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() = default;
    Node(const int val) : val(val) {}
    Node(const int val, const std::vector<Node*>& children) : val(val), children(children) {}
};


ListNode* create(const std::vector<int>& vec) {
    [[unlikely]] ListNode *head = new ListNode(vec[0]), *current = head;

    for (const int num : vec) {
        current->next = new ListNode(num);
        current = current->next;
    }
    return head->next;
}

void free(const ListNode* head) {
    while (head) {
        const ListNode* next = head->next;
        delete head;
        head = next;
    }
}

void print(const ListNode* head) {
    std::cout << '[';

    while (head->next) {
        std::cout << head->val << ", ";
        head = head->next;
    }
    std::cout << head->val << ']';
}

class Solution {
public:
    std::vector<int> relativeSortArray(std::vector<int> arr1, const std::vector<int> arr2) {
        std::unordered_map<int, int> hash;
        int i = 0;
        hash.reserve(arr2.size());

        for (const int element : arr2) {
            hash.emplace(element, i++);
        }
        std::sort(arr1.begin(), arr1.end(), [&hash](const int a, const int b) {
            const auto itr_a = hash.find(a), itr_b = hash.find(b);

            if (itr_a == hash.end()) {
                return false;
            }
            if (itr_b == hash.end()) {
                return true;
            }
            return hash[a] < hash[b];
        });
        const int last = arr2.back();
        i = arr1.size() - 1;

        while (i >= 0 && arr1[i] != last) {
            i--;
        }
        if (i < arr1.size() - 1) {
            std::sort(arr1.begin() + i + 1, arr1.end());
        }
        return arr1;
    }
};

int main() {
    Solution sol;
    const std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();

    sol.relativeSortArray({28, 6, 22, 8, 44, 17}, {22, 28, 8, 6});

    const std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();
    return 0;
}

#include "all_in_one.hpp"
