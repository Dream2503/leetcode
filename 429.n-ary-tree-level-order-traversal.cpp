/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(const Node* root) {
        if (!root) {
            return {};
        }
        std::vector<std::vector<int>> res;
        std::vector current(1, root);

        while (!current.empty()) {
            std::vector<const Node*> next;
            std::vector<int> level;
            level.reserve(current.size());

            for (const Node* node : current) {
                for (const Node* child : node->children) {
                    next.push_back(child);
                }
                level.push_back(node->val);
            }
            std::swap(current, next);
            res.push_back(std::move(level));
        }
        return res;
    }
};
// @lc code=end
