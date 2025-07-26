-- 1. Table creation
CREATE TABLE Scores (
    Id INT PRIMARY KEY,
    Score DECIMAL(3,2)
);


-- 2. Sample data insertion (you can add or modify these values as you like)
INSERT INTO Scores (Id, Score) VALUES
(1, 3.50),
(2, 3.65),
(3, 4.00),
(4, 3.85),
(5, 4.00);


-- 3. Query to produce dense ranking (without window functions)
SELECT
  Score,
  (SELECT COUNT(DISTINCT Score) FROM Scores s2 WHERE s2.Score >= s1.Score) AS `Rank`
FROM Scores s1
ORDER BY Score DESC;
