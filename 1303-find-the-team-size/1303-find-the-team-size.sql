SELECT employee_id, cnt AS team_size
FROM (
    SELECT employee_id, team_id,
           COUNT(*) OVER (PARTITION BY team_id) AS cnt
    FROM Employee
) AS t;