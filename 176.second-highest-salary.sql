/*
 * @lc app=leetcode id=176 lang=pgsql
 *
 * [176] Second Highest Salary
 */

--leetcode submit region begin(Prohibit modification and deletion)
-- Write your PostgreSQL query statement below
SELECT (SELECT DISTINCT salary
        FROM employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET 1) "SecondHighestSalary";
--leetcode submit region end(Prohibit modification and deletion)
