WITH temp AS (
    SELECT content_id, title
    FROM Content
    WHERE content_type = 'Movies'
      AND kids_content = 'Y'
)
SELECT DISTINCT t.title
FROM TVProgram p
INNER JOIN temp t
    ON p.content_id = t.content_id
WHERE MONTH(p.program_date) = 6 AND YEAR(p.program_date)=2020;