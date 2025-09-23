select class from Courses
group by class
having count(student)>4;


-- OR


-- SELECT class
-- FROM Courses
-- GROUP BY class
-- HAVING COUNT(DISTINCT student) >= 5;


-- GROUP BY class → groups rows by each class.

-- COUNT(DISTINCT student) → counts the unique students per class.

-- HAVING COUNT(...) >= 5 → filters only those classes with 5 or more students.