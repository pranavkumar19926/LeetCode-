# Write your MySQL query statement below


WITH temp AS(SELECT p.x , ABS(p.x - q.x) AS dist FROM Point p CROSS JOIN ( SELECT x FROM Point )q WHERE ABS(p.x-q.x) != 0  ORDER BY dist ASC ) 


  SELECT dist AS shortest FROM temp LIMIT 1 ;

  