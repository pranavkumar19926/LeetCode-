# Write your MySQL query statement below



WITH temp AS(SELECT product_id , CASE WHEN store1 IS NOT NULL THEN 'store1' END  AS store , CASE WHEN store1 IS NOT NULL THEN store1 END AS price FROM Products  
               
               UNION ALL

     SELECT product_id , CASE WHEN store2 IS NOT NULL THEN 'store2' END AS store , CASE WHEN store2 IS NOT NULL THEN store2 END AS price FROM Products  

       UNION ALL
                               
     SELECT product_id , CASE WHEN store3 IS NOT NULL THEN 'store3' END AS store , CASE WHEN store3 IS NOT NULL THEN store3 END AS price FROM Products )                         


      SELECT product_id , store , price FROM temp  WHERE store IS NOT NULL OR price IS NOT NULL;