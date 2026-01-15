# Write your MySQL query statement below
SELECT
d.name AS Department,
e.name AS Employee,
e.salary AS Salary
FROM Employee e
LEFT JOIN Department d
ON e.departmentId = d.id
WHERE
 (E.departmentId, E.salary) IN (
    SELECT departmentId, MAX(salary) FROM Employee Group BY departmentId
 );