SELECT
    d1.visited_on,
    SUM(d2.amount) AS amount,
    ROUND(SUM(d2.amount) / 7, 2) AS average_amount
FROM (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) d1
JOIN (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) d2
    ON DATEDIFF(d1.visited_on, d2.visited_on) BETWEEN 0 AND 6
GROUP BY d1.visited_on
HAVING COUNT(*) = 7
ORDER BY d1.visited_on;