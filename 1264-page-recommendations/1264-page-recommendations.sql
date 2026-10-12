# Write your MySQL query statement below


  WITH temp AS(SELECT user2_id AS user_id FROM Friendship WHERE user1_id=1 

     UNION ALL

   SELECT user1_id AS user_id FROM Friendship WHERE user2_id =1 


       )  

  SELECT DISTINCT(l.page_id )AS recommended_page FROM LIKES l INNER JOIN temp t ON l.user_id=t.user_id WHERE l.page_id NOT IN(SELECT page_id FROM Likes WHERE user_id =1 ) ;
