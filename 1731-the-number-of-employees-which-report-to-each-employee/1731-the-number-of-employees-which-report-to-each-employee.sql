SELECT 
    e.employee_id,
    e.name,
    COUNT(d.employee_id) AS reports_count,
    ROUND(AVG(d.age), 0) AS average_age
FROM Employees e
JOIN Employees d
    ON e.employee_id = d.reports_to
GROUP BY e.employee_id, e.name

ORDER BY e.employee_id ;