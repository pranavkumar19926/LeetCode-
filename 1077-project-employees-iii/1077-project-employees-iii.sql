# Write your MySQL query statement below

WITH temp AS(SELECT p.project_id , p.employee_id , e.experience_years FROM Project p INNER JOIN Employee e ON p.employee_id = e.employee_id  ),

     temp1 AS(SELECT project_id , employee_id , RANK() OVER(PARTITION BY project_id ORDER BY experience_years DESC ) AS rnk FROM temp  )

     SELECT project_id , employee_id FROM temp1 WHERE rnk=1 ;