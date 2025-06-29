SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE m.id IN (
    SELECT m.id
    FROM people p2
    JOIN stars s2 ON p2.id = s2.person_id
    JOIN movies m ON s2.movie_id = m.id
    WHERE p2.name = 'Kevin Bacon'
);
