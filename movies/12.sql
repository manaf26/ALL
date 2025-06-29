SELECT DISTINCT title
    FROM movies
        JOIN stars ON movies.id = stars.movie_id
        JOIN people ON people.id = stars.person_id
    WHERE people.name = 'Bradley Cooper' OR people.name = 'Jennifer Lawrence';
