/*
 * @lc app=leetcode id=2326 lang=cpp
 *
 * [2326] Spiral Matrix IV
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    std::vector<std::vector<int>> spiralMatrix(const int m, const int n, const ListNode* head) {
        enum class Direction { LEFT, UP, DOWN, RIGHT } direction = Direction::RIGHT;
        int i = 0, j = 0;
        std::array edge = {0, 1, m, n}; // {left, up, down, right}
        const ListNode* current = head;
        std::vector res(m, std::vector(n, -1));

        while (current) {
            res[i][j] = current->val;
            current = current->next;

            switch (direction) {
            case Direction::RIGHT:
                if (j + 1 < edge[3]) {
                    j++;
                } else {
                    direction = Direction::DOWN;
                    edge[3]--;
                    i++;

                    if (i == edge[2]) {
                        return res;
                    }
                }
                break;

            case Direction::DOWN:
                if (i + 1 < edge[2]) {
                    i++;
                } else {
                    direction = Direction::LEFT;
                    edge[2]--;
                    j--;

                    if (j == edge[0] - 1) {
                        return res;
                    }
                }
                break;

            case Direction::LEFT:
                if (j - 1 >= edge[0]) {
                    j--;
                } else {
                    direction = Direction::UP;
                    edge[0]++;
                    i--;

                    if (i == edge[1] - 1) {
                        return res;
                    }
                }
                break;

            default:
                if (i - 1 >= edge[1]) {
                    i--;
                } else {
                    direction = Direction::RIGHT;
                    edge[1]++;
                    j++;

                    if (j == edge[3]) {
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
