-- Drop tables if they already exist (optional)
DROP TABLE IF EXISTS Address;
DROP TABLE IF EXISTS Person;

-- 1. Create Person table
CREATE TABLE Person (
    personId INT PRIMARY KEY,
    firstName VARCHAR(50),
    lastName VARCHAR(50)
);

-- 2. Create Address table
CREATE TABLE Address (
    addressId INT PRIMARY KEY AUTO_INCREMENT,
    personId INT,
    city VARCHAR(50),
    state VARCHAR(50),
    FOREIGN KEY (personId) REFERENCES Person(personId)
);

-- 3. Insert sample data into Person
INSERT INTO Person (personId, firstName, lastName) VALUES
(1, 'John', 'Doe'),
(2, 'Jane', 'Smith'),
(3, 'Alice', 'Brown');

-- 4. Insert sample data into Address
INSERT INTO Address (personId, city, state) VALUES
(1, 'New York', 'NY'),
(3, 'Los Angeles', 'CA');

-- 5. Run the LEFT JOIN query

//Leetcode
SELECT 
    Person.firstName,
    Person.lastName,
    Address.city,
    Address.state
FROM Person
LEFT JOIN Address
ON Person.personId = Address.personId;
