# Write your MySQL query statement below

WITH country AS (
    SELECT p.id, c.name
    FROM Person p
    LEFT JOIN Country c
        ON SUBSTRING(p.phone_number, 1, 3) = c.country_code
),

val AS (
    SELECT AVG(duration) AS value
    FROM Calls
),

temp1 AS (
    SELECT
        co.name,
        SUM(c.duration) AS dur,
        COUNT(c.duration) AS cnt
    FROM country co
    INNER JOIN Calls c
        ON co.id = c.caller_id
    GROUP BY co.name

    UNION ALL

    SELECT
        co.name,
        SUM(c.duration) AS dur,
        COUNT(c.duration) AS cnt
    FROM country co
    INNER JOIN Calls c
        ON co.id = c.callee_id
    GROUP BY co.name
),

temp4 AS (
    SELECT
        name,
        SUM(dur) / SUM(cnt) AS dur
    FROM temp1
    GROUP BY name
)

SELECT name AS country
FROM temp4
WHERE dur > (SELECT value FROM val);