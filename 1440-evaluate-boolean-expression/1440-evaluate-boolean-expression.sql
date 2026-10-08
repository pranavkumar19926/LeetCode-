WITH temp AS (SELECT 
    e.left_operand,
    e.operator,
    e.right_operand,
    CASE
        WHEN e.operator = '<' THEN l.value < r.value
        WHEN e.operator = '>' THEN l.value > r.value
        WHEN e.operator = '=' THEN l.value = r.value
    END AS value
FROM Expressions e
JOIN Variables l
    ON e.left_operand = l.name
JOIN Variables r
    ON e.right_operand = r.name )

    SELECT left_operand , operator , right_operand , CASE WHEN value=1 THEN 'true' ELSE 'false' END

    AS value FROM temp ; 
