# attempt 2 
SELECT
    v.customer_id,
    COUNT(*) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t
    ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL 
GROUP BY v.customer_id
;

-- SQL logically processes this as:

-- FROM
--  ↓
-- LEFT JOIN
--  ↓
-- WHERE
--  ↓
-- GROUP BY
--  ↓
-- SELECT



-- Visits
-- +----------+-------------+
-- | visit_id | customer_id |
-- +----------+-------------+
-- | 4        | 30          | 1
-- | 6        | 96          | 1
-- | 7        | 54          | 1a
-- | 8        | 54          | 1b
-- +----------+-------------+

-- Transactions
-- +----------------+----------+--------+
-- | transaction_id | visit_id | amount |
-- +----------------+----------+--------+
-- | 2              | 5        | 310    |
-- | 3              | 5        | 300    |
-- | 9              | 5        | 200    |
-- | 12             | 1        | 910    |
-- | 13             | 2        | 970    |
-- +----------------+----------+--------+

