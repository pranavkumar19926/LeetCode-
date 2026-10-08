SELECT 
    t.team_id,
    t.team_name,
    COALESCE(d.points, 0) AS num_points
FROM Teams t
LEFT JOIN (
    SELECT 
        team_id,
        SUM(points) AS points
    FROM (
        SELECT
            host_team AS team_id,
            CASE
                WHEN host_goals > guest_goals THEN 3
                WHEN host_goals = guest_goals THEN 1
                ELSE 0
            END AS points
        FROM Matches

        UNION ALL

        SELECT
            guest_team AS team_id,
            CASE
                WHEN guest_goals > host_goals THEN 3
                WHEN guest_goals = host_goals THEN 1
                ELSE 0
            END AS points
        FROM Matches
    ) temp
    GROUP BY team_id
) d
ON t.team_id = d.team_id
ORDER BY num_points DESC, t.team_id ASC;