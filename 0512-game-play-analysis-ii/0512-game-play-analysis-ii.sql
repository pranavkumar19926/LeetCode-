# Write your MySQL query statement below
                



  SELECT a.player_id ,   a.device_id       FROM  Activity a JOIN    (SELECT player_id , MIN(event_date) AS event_date FROM Activity GROUP BY player_id ) t WHERE  a.player_id = t.player_id AND a.event_date = t.event_date ;