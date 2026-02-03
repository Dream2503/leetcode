/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        std::ranges::reverse(students);
        std::ranges::reverse(sandwiches);
        int stuck = 0;

        while (!students.empty() && stuck < students.size()) {
            if (students.back() == sandwiches.back()) {
                students.pop_back();
                sandwiches.pop_back();
                stuck = 0;
            } else {
                students.insert(students.begin(), students.back());
                students.pop_back();
                stuck++;
            }
        }
        return students.size();
    }
};
// @lc code=end
