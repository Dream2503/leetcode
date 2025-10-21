/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
    void traverse(const Node* root, std::vector<int>& res) {
        if (root) {
            for (const Node* node : root->children) {
                traverse(node, res);
            }
            res.push_back(root->val);
        }
    }

public:
    std::vector<int> postorder(const Node* root) {
        std::vector<int> res;
        traverse(root, res);
        return res;
    }
};
// @lc code=end
