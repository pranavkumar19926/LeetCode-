# Write your MySQL query statement below


SELECT 
    query_name,

    ROUND(
        SUM(rating / position) / 
        (SELECT COUNT(*) 
         FROM Queries q2
         WHERE q2.query_name = q1.query_name),
        2
    ) AS quality,

    ROUND(
        (SELECT COUNT(*)
         FROM Queries q3
         WHERE q3.query_name = q1.query_name
           AND q3.rating < 3) * 100 /
        (SELECT COUNT(*)
         FROM Queries q4
         WHERE q4.query_name = q1.query_name),
        2
    ) AS poor_query_percentage

FROM Queries q1
GROUP BY query_name;