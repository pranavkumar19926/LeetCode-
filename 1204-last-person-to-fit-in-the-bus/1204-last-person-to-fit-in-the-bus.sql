# Write your MySQL query statement below

SELECT person_name FROM (SELECT person_name , SUM(weight) OVER (ORDER BY turn) AS cummulative_sum , turn FROM Queue) q WHERE
                        
                        cummulative_sum <=1000 ORDER BY turn DESC LIMIT 1;