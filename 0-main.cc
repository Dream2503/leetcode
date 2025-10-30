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
    std::vector<int> numberOfAlternatingGroups(std::vector<int> colors, const std::vector<std::vector<int>>& queries) {
        const int size = colors.size();
        std::vector<int> res;

        for (const std::vector<int>& query : queries) {
            if (query[0] == 1) {
                int count = 0;

                for (int i = 0; i < size; i++) {
                    bool complete = true;
                    int j = 1;

                    for (j = 1; j < query[1]; j++) {
                        if (colors[(i + j - 1) % size] == colors[(i + j) % size]) {
                            complete = false;
                            break;
                        }
                    }
                    if (complete) {
                        count++;
                    } else {
                        i += j - 1;
                    }
                }
            } else {
                colors[query[1]] = query[2];
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    const std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();

    sol.numberOfAlternatingGroups({0, 1, 1, 0, 0}, {{2, 1, 0}, {1, 4}});

    const std::chrono::duration<double> time = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Total time taken: " << time.count();
    return 0;
}

#include "all_in_one.hpp"
