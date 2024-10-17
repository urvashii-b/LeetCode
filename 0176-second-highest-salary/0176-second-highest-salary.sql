SELECT MAX(salary) as SecondHighestSalary
From Employee
WHERE salary NOT IN (
    SELECT MAX(salary)
    FROM Employee
)