WITH temp AS (
    SELECT c.com_id, o.sales_id
    FROM Company c
    INNER JOIN Orders o
        ON c.com_id = o.com_id
    WHERE c.name = 'RED'
)

SELECT s.name
FROM SalesPerson s
LEFT JOIN temp t
    ON s.sales_id = t.sales_id
WHERE t.sales_id IS NULL;