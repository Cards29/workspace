CREATE OR REPLACE PROCEDURE highRatedMovies(N NUMBER) IS
    total_movies NUMBER;
BEGIN
    SELECT COUNT(DISTINCT MOV_ID) INTO total_movies FROM RATING;
        -- GROUP BY M.MOV_TITLE, M.MOV_YEAR, M.MOV_LANGUAGE, M.MOV_RELEASEDATE, M.MOV_COUNTRY;
    DBMS_OUTPUT.PUT_LINE(N);
    DBMS_OUTPUT.PUT_LINE(total_movies);
END;
/
DECLARE
    v_num NUMBER := 5;

BEGIN
    highRatedMovies(v_num);
END;
/

CREATE OR REPLACE FUNCTION status(MOV_ID NUMBER) RETURN VARCHAR2 IS
    st NUMBER;
BEGIN
    SELECT COUNT(DISTINCT ACT_ID) INTO st 
    FROM MOVIE M 
    JOIN CASTS C ON M.MOV_ID = C.MOV_ID;

    IF st = 1 THEN 
        RETURN 'SOLO';
    ELSE 
        RETURN 'ENSEMBLE';
    END IF;
END status;
/

DECLARE
    STT VARCHAR(20);
BEGIN
    stt := status(901);
    DBMS_OUTPUT.PUT_LINE(STT);
END;
/




-- -- a
-- BEGIN
--     DBMS_OUTPUT.PUT_LINE('RAHINUR_220041118');
-- END;
-- /
-- -- b
-- DECLARE
--     a NUMBER;
--     b NUMBER;
-- BEGIN
--     a := 4;
--     b := 6;
--     DBMS_OUTPUT.PUT_LINE(a*b);
-- END;
-- /
-- -- c
-- DECLARE
--     a NUMBER := 66;
--     b NUMBER := 66.666;
-- BEGIN
--     IF FLOOR(a) = a THEN
--     DBMS_OUTPUT.PUT_LINE(a || ' IS A WHOLE NUMBER');
--     ELSE
--     DBMS_OUTPUT.PUT_LINE(a || ' IS A FRACTIONAL NUMBER');
--     END IF;

--     IF FLOOR(b) = b THEN
--     DBMS_OUTPUT.PUT_LINE(b || ' IS A WHOLE NUMBER');
--     ELSE
--     DBMS_OUTPUT.PUT_LINE(b || ' IS A FRACTIONAL NUMBER');
--     END IF;
-- END;
-- /





