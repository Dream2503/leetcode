/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        std::vector level = {root};

        while (!level.empty()) {
            std::vector<Node*> next;
            const int size = level.size();

            for (int i = 0; i < size - 1; i++) {
                if (level[i]->left) {
                    next.push_back(level[i]->left);
                }
                if (level[i]->right) {
                    next.push_back(level[i]->right);
                }
                level[i]->next = level[i + 1];
            }
            if (level[size - 1]->left) {
                next.push_back(level[size - 1]->left);
            }
            if (level[size - 1]->right) {
                next.push_back(level[size - 1]->right);
            }
            level[size - 1]->next = nullptr;
            level = std::move(next);
        }
        return root;
    }
};
// @lc code=end
