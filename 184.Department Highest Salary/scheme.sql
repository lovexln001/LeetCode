# Write your MySQL query statement below
SELECT d.Name as Department, e.Name as Employee, e.Salary as Salary
FROM Employee e JOIN Department d ON e.DepartmentId = d.Id and Salary IN 
(SELECT MAX(Salary) FROM Employee c WHERE c.DepartmentId = e.DepartmentId )
