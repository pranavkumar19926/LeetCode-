SELECT s.id, s.name
FROM Students s
WHERE NOT EXISTS (
    SELECT 1
    FROM Departments d
    WHERE d.id = s.department_id
);