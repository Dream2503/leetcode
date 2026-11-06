/*
 * @lc app=leetcode id=175 lang=pgsql
 *
 * [175] Combine Two Tables
 */

--leetcode submit region begin(Prohibit modification and deletion)
-- Write your PostgreSQL query statement below
SELECT firstname, lastname, city, state
FROM person
         LEFT JOIN address ON person.personid = address.personid;
--leetcode submit region end(Prohibit modification and deletion)
