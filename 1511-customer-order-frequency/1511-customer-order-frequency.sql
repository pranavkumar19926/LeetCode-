# Write your MySQL query statement below


WITH temp AS(SELECT o.customer_id , SUM(p.price * o.quantity) AS cost , MONTH(o.order_date) AS mon  FROM Orders o INNER JOIN Product p 
                                     ON o.product_id = p.product_id WHERE o.order_date>='2020-06-01' AND o.order_date<='2020-07-31'  GROUP BY o.customer_id,mon HAVING cost >=100 ),




    t1 AS (SELECT customer_id,cost FROM temp WHERE cost>=100  AND mon=6 ),

    t2 AS(SELECT customer_id,cost FROM temp WHERE cost>=100 AND mon=7),


   final AS (SELECT a.customer_id FROM t1 a INNER JOIN t2 b ON a.customer_id=b.customer_id WHERE a.cost>=100 AND b.cost>=100 )

   SELECT f.customer_id , c.name FROM final f INNER JOIN Customers c ON f.customer_id = c.customer_id ;