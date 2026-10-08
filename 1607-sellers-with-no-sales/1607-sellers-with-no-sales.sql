# Write your MySQL query statement below

    


      WITH temp AS ( SELECT DISTINCT(s.seller_name ) AS seller_name FROM Seller s INNER JOIN Orders o ON s.seller_id = o.seller_id  WHERE o.sale_date >= '2020-01-01' AND o.sale_date <='2020-12-31' ) 
         


      SELECT s.seller_name FROM Seller s WHERE s.seller_name NOT IN ( SELECT t.seller_name FROM temp t) ORDER BY s.seller_name ASC ;  