WITH temp AS (
    SELECT seat_id
    FROM Cinema
    WHERE free = 1
)
SELECT DISTINCT c.seat_id
FROM temp c
JOIN temp p
    ON ABS(c.seat_id - p.seat_id) = 1
ORDER BY c.seat_id;