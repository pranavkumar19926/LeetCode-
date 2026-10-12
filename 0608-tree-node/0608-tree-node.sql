# Write your MySQL query statement below

WITH temp AS (
         
    

    SELECT a.id, 'Root' AS Type
    FROM Tree a
    WHERE a.p_id IS NULL
      
      UNION

    SELECT a.id, 'Leaf' AS Type
    FROM Tree a
    LEFT JOIN Tree b
        ON a.id = b.p_id
    WHERE b.p_id IS NULL

    UNION

    SELECT a.id, 'Inner' AS Type
    FROM Tree a
    INNER JOIN Tree b
        ON a.id = b.p_id
    WHERE a.p_id IS NOT NULL

)
SELECT  id, Type
FROM temp
GROUP BY id
ORDER BY id;