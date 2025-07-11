-- Create the Employee table
CREATE TABLE Employee (
    empId INT PRIMARY KEY,
    name VARCHAR(100),
    salary INT
);

-- Create the Bonus table
CREATE TABLE Bonus (
    empId INT,
    bonus INT
);

-- Insert sample data into Employee
INSERT INTO Employee (empId, name, salary) VALUES
(1, 'Alice', 5000),
(2, 'Bob', 6000),
(3, 'Charlie', 5500),
(4, 'David', 7000);

-- Insert sample data into Bonus
INSERT INTO Bonus (empId, bonus) VALUES
(1, 800),
(2, 1200),
(4, NULL);

-- Run the query
SELECT Employee.name, Bonus.bonus
FROM Employee
LEFT JOIN Bonus
ON Employee.empId = Bonus.empId
WHERE Bonus.bonus < 1000 OR Bonus.bonus IS NULL;
