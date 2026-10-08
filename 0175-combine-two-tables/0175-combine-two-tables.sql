# Write your MySQL query statement below


SELECT p.firstName , p.lastName , COALESCE(a.city,Null) AS city , COALESCE(a.state,Null) AS state FROM Person p LEFT JOIN Address a ON p.personId = a.personID ; 