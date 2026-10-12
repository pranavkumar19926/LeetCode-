# Write your MySQL query statement below


SELECT  ABS(p.x - q.x) AS shortest FROM Point p CROSS JOIN ( SELECT x FROM Point )q WHERE ABS(p.x-q.x) != 0  ORDER BY shortest ASC LIMIT 1 ; 


 

  