# Write your MySQL query statement below



 WITH temp AS(SELECT managerId FROM Employee GROUP BY managerId HAVING COUNT(managerID) >= 5 )

      SELECT name FROM Employee WHERE id  IN(SELECT managerId FROM temp ) ;