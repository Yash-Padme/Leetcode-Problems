# attempt 2 
-- SELECT w2.id
-- FROM Weather w1
-- JOIN Weather w2 
--     ON w1.id + 1 = w2.id
-- WHERE w1.temperature  < w2.temperature 
-- ;

SELECT w2.id
FROM Weather w1
JOIN Weather w2
    ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
WHERE w2.temperature > w1.temperature;

-- SQL pattern you're learning here:

-- Self JOIN
--    ↓
-- Compare current row with previous row
--    ↓
-- Filter based on comparison