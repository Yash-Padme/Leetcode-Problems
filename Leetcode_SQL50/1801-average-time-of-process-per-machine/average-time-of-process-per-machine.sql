# attempt 2 
SELECT
    a1.machine_id,
    ROUND(AVG(a2.timestamp - a1.timestamp), 3) as processing_time
FROM Activity a1
JOIN Activity a2
    ON a1.machine_id = a2.machine_id 
    AND a2.process_id = a2.process_id
WHERE a1.activity_type = 'start' AND a2.activity_type = 'end'
GROUP BY a1.machine_id

;


-- 🧠 The pattern to remember

-- When data looks like:

-- start row
-- end row

-- and you need:

-- (end - start)

-- think:

-- SELF JOIN
--    ↓
-- match same ID
--    ↓
-- start row + end row
--    ↓
-- end.timestamp - start.timestamp
--    ↓
-- GROUP BY
--    ↓
-- AVG()