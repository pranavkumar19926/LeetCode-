# Write your MySQL query statement below


WITH temp AS(SELECT product_id , order_date , SUM(unit) AS unit FROM Orders WHERE YEAR(order_date)='2020' AND MONTH(order_date)='02' GROUP BY product_id HAVING SUM(unit) >=100 )


SELECT p.product_name , t.unit FROM Products  p INNER JOIN temp t ON p.product_id = t.product_id ;