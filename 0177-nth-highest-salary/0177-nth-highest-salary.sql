CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE result INT;
  DECLARE M INT;
  SET M = N - 1;
  
  SET result = (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET M
  );
  
  RETURN result;
END