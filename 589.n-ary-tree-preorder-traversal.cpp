/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
            res.push_back(root->val);

            for (const Node* node : root->children) {
                traverse(node, res);
            }
        }
    }

public:
    std::vector<int> preorder(const Node* root) {
        std::vector<int> res;
        traverse(root, res);
        return res;
    }
};
// @lc code=end
