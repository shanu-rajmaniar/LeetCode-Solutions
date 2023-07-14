# Write your MySQL query statement below
SELECT MAX(SALARY) as SecondHighestSalary
FROM Employee
WHERE Salary NOT IN (SELECT MAX(Salary)
FROM Employee)