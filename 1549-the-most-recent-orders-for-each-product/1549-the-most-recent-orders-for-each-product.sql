# Write your MySQL query statement below

     

 SELECT p.product_name , p.product_id , t.order_id , t.order_date  FROM Products p JOIN     (SELECT product_id , order_id , order_date ,RANK() OVER( PARTITION BY product_id ORDER BY order_date DESC) AS rnk FROM Orders )t  ON p.product_id=t.product_id WHERE t.rnk=1 ORDER BY p.product_name , p.product_id,order_id;