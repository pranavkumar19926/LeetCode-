# Write your MySQL query statement below



WITH temp AS(SELECT CASE WHEN from_id > to_id THEN to_id ELSE from_id END AS person1 , CASE WHEN from_id<to_id THEN 
                        to_id ELSE from_id END AS person2 , duration FROM Calls )



               SELECT person1 , person2 ,COUNT(*) AS call_count   , SUM(duration) AS total_duration FROM temp GROUP BY person1,person2 ;         