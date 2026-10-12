WITH temp AS (
         
    

    SELECT a.N, 'Root' AS Type
    FROM Tree a
    WHERE a.P IS NULL
      
      UNION

    SELECT a.N, 'Leaf' AS Type
    FROM Tree a
    LEFT JOIN Tree b
        ON a.N = b.P
    WHERE b.P IS NULL

    UNION

    SELECT a.N, 'Inner' AS Type
    FROM Tree a
    INNER JOIN Tree b
        ON a.N = b.P
    WHERE a.P IS NOT NULL

)
SELECT N, Type
FROM temp
GROUP BY N
ORDER BY N;