SELECT eu.unique_id AS unique_id, name
FROM Employees e
LEFT JOIN EmployeeUNI eu 
ON e.id = eu.id;