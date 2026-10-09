# Write your MySQL query statement below


WITH temp AS( SELECT product_id , Width*Length*Height AS volume FROM Products ),

       
     temp1 AS(SELECT w.name , t.volume* w.units AS vol FROM Warehouse w LEFT JOIN temp t ON w.product_id = t.product_id )  

     SELECT name as warehouse_name , SUM(vol) AS volume  FROM temp1 GROUP BY name ;