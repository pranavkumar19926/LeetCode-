# Write your MySQL query statement below


WITH temp AS(SELECT product_id , order_date , SUM(unit) AS unit FROM Orders WHERE order_date REGEXP '^2020-02-[0-9]{2}$' GROUP BY product_id HAVING SUM(unit) >=100 )


SELECT p.product_name , t.unit FROM Products  p INNER JOIN temp t ON p.product_id = t.product_id ;