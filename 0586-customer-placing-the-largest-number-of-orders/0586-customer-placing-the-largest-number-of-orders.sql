WITH temp AS (
    SELECT
        customer_number,
        COUNT(order_number) AS counts
    FROM Orders
    GROUP BY customer_number
),
tata AS (
    SELECT MAX(counts) AS max_count
    FROM temp
)
SELECT customer_number
FROM temp
WHERE counts = (SELECT max_count FROM tata);