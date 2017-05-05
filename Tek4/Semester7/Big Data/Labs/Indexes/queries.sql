/* QUESTION 1 - 13 rows */
SELECT a.first_name, a.last_name 
FROM movies m 
JOIN roles r ON r.movie_id = m.id 
JOIN actors a ON a.id = r.actor_id 
WHERE m.name = 'Officer 444';

/* QUESTION 2 - 86 rows */
SELECT d.last_name, m.name, m.year 
FROM movies m 
JOIN movies_genres mg ON movie_id = m.id 
JOIN movies_directors md ON md.movie_id = m.id 
JOIN directors d ON d.id = md.director_id 
WHERE mg.genre = 'Film-Noir' 
AND m.year % 4 = 0;

/* QUESTION 3 - 23 rows */
SELECT DISTINCT a.first_name, a.last_name
FROM actors a
INNER JOIN roles r ON r.actor_id = a.id
INNER JOIN movies m ON m.id = r.movie_id
WHERE m.year < 1900 AND r.actor_id IN(
  SELECT r.actor_id
  FROM roles r
  INNER JOIN movies m ON m.id = r.movie_id
  WHERE m.year > 2000
);
/* Actors displayed are actors that have been indirectly acting in > 2000's movies like documentaries */


SELECT c.first_name, c.last_name
FROM Customer c
JOIN Subscription s ON s.CustomerID = c.ID
JOIN FitnessClass fc ON fc.Id = s.ClassId
WHERE fc.ClassName = 'Beginner Sumba';

SELECT *
FROM FitnessClass fc
JOIN Instructor i ON i.Id = fc.InstructorId
WHERE i.FirstName = 'Fiona' AND i.LastName = 'Smith' AND fc.Cost <= 7;

SELECT i.Id, i.LastName, AVG(fc.Cost)
FROM Instructor i
JOIN FitnessClass fc ON fc.InstructorId = i.Id
GROUP BY i.Id;

SELECT fc.Id, fc.ClassName
FROM FitnessClass fc
HAVING (MIN(fc.Cost) + 0.5) > fc.Cost