# Write your MySQL query statement below



 WITH temp AS(SELECT Wimbledon AS id , COUNT(Wimbledon) AS cnt   FROM Championships GROUP BY Wimbledon

           UNION ALL

 SELECT Fr_open AS id , COUNT(Fr_open) AS cnt   FROM Championships GROUP BY Fr_open

    UNION ALL

    SELECT US_open AS id , COUNT(US_open) AS cnt   FROM Championships GROUP BY US_open

    UNION ALL

   SELECT Au_open AS id , COUNT(Au_open) AS cnt   FROM Championships GROUP BY Au_open           
 ),

  temp2 AS(SELECT id , SUM(cnt) AS cnt FROM temp GROUP BY id)

   SELECT p.player_id ,p.player_name , c.cnt AS grand_slams_count FROM Players p INNER JOIN temp2 c ON p.player_id = c.id ;