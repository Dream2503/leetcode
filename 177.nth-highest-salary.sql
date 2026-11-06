/*
 * @lc app=leetcode id=177 lang=pgsql
 *
 * [177] Nth Highest Salary
 */

--leetcode submit region begin(Prohibit modification and deletion)
CREATE OR REPLACE FUNCTION nthhighestsalary(n INT)
    RETURNS TABLE (
        salary INT
    )
AS
$$
BEGIN
    IF n IS NULL OR n <= 0 THEN
        RETURN QUERY SELECT NULL::INT;
        RETURN;
    END IF;

    RETURN QUERY
        SELECT (SELECT DISTINCT e.salary
                FROM employee AS e
                ORDER BY e.salary DESC
                LIMIT 1 OFFSET (n - 1));
END;
$$ LANGUAGE plpgsql;
--leetcode submit region end(Prohibit modification and deletion)
