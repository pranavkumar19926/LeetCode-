SELECT
    COALESCE(
        (SELECT s.id
         FROM Seat s
         WHERE s.id = CASE
             WHEN a.id % 2 = 1 THEN a.id + 1
             ELSE a.id - 1
         END),
        a.id
    ) AS id,
    a.student
FROM Seat a
ORDER BY id;