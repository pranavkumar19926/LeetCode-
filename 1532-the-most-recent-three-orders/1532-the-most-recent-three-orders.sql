# Write your MySQL query statement below

           

 SELECT c.name AS Customer_name,c.customer_id , t.order_id , t.order_date FROM Customers c JOIN     (SELECT order_id, customer_id ,order_date , DENSE_RANK() OVER( PARTITION BY customer_id ORDER BY order_date DESC) AS rnk FROM Orders ) t ON c.customer_id = t.customer_id WHERE t.rnk<=3 ORDER BY Customer_name , c.customer_id  ASC , t.order_date DESC ; 