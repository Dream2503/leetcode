/*
 * @lc app=leetcode id=178 lang=pgsql
 *
 * [178] Rank Scores
 */

--leetcode submit region begin(Prohibit modification and deletion)
-- Write your PostgreSQL query statement below
SELECT score,
       DENSE_RANK() OVER (ORDER BY score DESC) AS "rank"
FROM scores;
--leetcode submit region end(Prohibit modification and deletion)
