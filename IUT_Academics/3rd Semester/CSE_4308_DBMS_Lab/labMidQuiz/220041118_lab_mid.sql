
-- no 3 --
SELECT * FROM
(SELECT COUNTRY, COUNT(museum.MUSEUM_ID) as number_Of_Museums
FROM museum 
GROUP BY COUNTRY
ORDER BY number_Of_Museums DESC
)
WHERE ROWNUM = 1;

-- no 4 --
-- question: is my answer correct since I used full_name
-- instead of artist_id?
-- what is the difference between w.STYLE and a.STYLE?
SELECT  a.FULL_NAME as ARTIST , w.STYLE AS STYLE_NAME, COUNT(w.WORK_ID) AS NUMBER_OF_WORK
FROM artists a, work w 
WHERE a.ARTIST_ID=w.ARTIST_ID
GROUP BY a.FULL_NAME, w.STYLE
ORDER BY NUMBER_OF_WORK;
-- chatgpt
SELECT artist_id, style, COUNT(*) AS num_works
FROM Work
-- WHERE style is not null
GROUP BY artist_id, style;

-- no 5 -- 
-- same as no 4, do I need museum_id instead of museum_name?
SELECT * FROM
(SELECT m.name AS MUSEUM_NAME, COUNT(DISTINCT w.ARTIST_ID) AS ARTIST_NUMBER
FROM museum m, work w
WHERE w.MUSEUM_ID=m.MUSEUM_ID
GROUP BY m.NAME
ORDER BY ARTIST_NUMBER DESC
)
WHERE ROWNUM=1;
-- chatgpt
SELECT * FROM
(SELECT museum_id, COUNT(DISTINCT artist_id) AS num_artists
FROM Work
WHERE museum_id is not null
GROUP BY museum_id
ORDER BY num_artists DESC
)
WHERE ROWNUM=1;

-- NO 8 --
-- WHERE NAME NOT LIKE '% % % %' kivabe use korbo???
SELECT a.FULL_NAME as Artist_name, AVG(LENGTH(w.NAME)) AS word_size_avg
FROM artists a, work w
WHERE a.ARTIST_ID = w.ARTIST_ID
GROUP BY a.FULL_NAME
HAVING  AVG(LENGTH(w.NAME))>=4
ORDER BY word_size_avg;
-- chatgpt
SELECT artist_id, AVG(LENGTH(name) - LENGTH(REPLACE(name, ' ', '')) + 1) AS avg_word_count
FROM Work
GROUP BY artist_id
HAVING AVG(LENGTH(name) - LENGTH(REPLACE(name, ' ', '')) + 1) > 4;


-- NO 6 --
SELECT * FROM
(SELECT m.NAME, COUNT(w.WORK_ID) AS CONTEMPORARY_WORK
FROM artists a, museum m, work w
WHERE a.ARTIST_ID = w.ARTIST_ID and w.MUSEUM_ID=m.MUSEUM_ID and a.BIRTH>1950
GROUP BY m.NAME
ORDER BY CONTEMPORARY_WORK DESC
)
WHERE ROWNUM=1;
-- chatgpt
SELECT w.museum_id, COUNT(*) AS num_contemporary_works
FROM Work w
JOIN Artist a ON w.artist_id = a.artist_id
WHERE a.birth > 1950
GROUP BY w.museum_id
ORDER BY num_contemporary_works DESC
FETCH FIRST 1 ROWS ONLY;


-- no 10 --
-- chatgpt
SELECT museum_id, COUNT(DISTINCT style) AS num_styles
FROM Work
GROUP BY museum_id
ORDER BY num_styles DESC
FETCH FIRST 1 ROWS ONLY;
-- me
SELECT * FROM
(
SELECT m.NAME AS MUSEUM_NAME, COUNT(DISTINCT w.STYLE) AS NUMBER_OF_ART_STYLE
FROM museum m, work w
WHERE m.MUSEUM_ID=w.MUSEUM_ID
GROUP BY m.NAME
ORDER BY NUMBER_OF_ART_STYLE DESC
)
WHERE ROWNUM=1;


-- no 2 --
-- I simply did not understand the question
-- chatgpt
SELECT (COUNT(DISTINCT museum_id) * 100 / COUNT(*)) AS percentage_displayed
FROM Work;

-- no 7 --
-- chatgpt
-- this is a very nice question and the answer is also elegant
SELECT style, 
    MIN(birth) AS first_appearance, 
    MAX(birth) AS last_appearance
FROM ARTISTS
GROUP BY style
-- HAVING MAX(birth) - MIN(birth) > 0  --I don't think this is necessary 
ORDER BY last_appearance;

-- no 9 --
--chatgpt
-- very elegant
SELECT nationality AS NATIONALITY, 
    MIN(birth) AS first_artist_year, 
    MAX(birth) AS last_artist_year
FROM Artists
GROUP BY nationality
ORDER BY first_artist_year;






