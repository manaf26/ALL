SELECT DISTINCT name
    FROM people
        JOIN directors ON people.id = directors.person_id
        --JOIN movies ON movies.movie_id = directors
        JOIN ratings ON directors.movie_id = ratings.movie_id
    WHERE rating >= '9';
