# Write your MySQL query statement below


SELECT p.product_id , COALESCE(t.new_price, 10)AS price FROM Products p
                                      
                                      LEFT JOIN ( SELECT product_id , new_price FROM 
                                      
                                        Products WHERE change_date<='2019-08-16' AND (product_id , change_date) IN (SELECT product_id , MAX(change_date) FROM
                                        
                                          Products WHERE change_date<='2019-08-16' GROUP BY product_id  ) ) t ON p.product_id =t.product_id GROUP BY p.product_id  ;