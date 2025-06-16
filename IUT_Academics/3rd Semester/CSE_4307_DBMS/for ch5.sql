-- BEGIN DBMS_OUTPUT.PUT_LINE ('HELLO WORLD!');
-- END;
-- /
-- DECLARE v_salary NUMBER;
-- v_bonus NUMBER:=1000;
-- BEGIN
-- SELECT
--     salary INTO v_salary
-- FROM
--     employees
-- WHERE
--     employee_id=101;
-- IF v_salary>5000 THEN v_salary:=v_salary+v_bonus;
-- END IF;
-- DBMS_OUTPUT.PUT_LINE ('Updated salary: '||v_salary);
-- EXCEPTION WHEN NO_DATA_FOUND THEN DBMS_OUTPUT.PUT_LINE ('Employee not found.');
-- WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE ('An error occurred.');
-- END;
-- /
-- no 1
SELECT
    p.name,
    p.type
FROM
    pokemon p
WHERE
    p.hp=(
        SELECT
            MAX(hp)
        FROM
            pokemon
        WHERE
            type=p.type
    )
ORDER BY
    p.type;

BEGIN DBMS_OUTPUT.PUT_LINE ('');

END;

/
-- no 2
SELECT
    name,
    hp+attack+defense+speed AS "Battle Potential"
FROM
    pokemon;

-- no 3
SELECT
    a.attack_name
FROM
    attacks a,
    pokemon_attacks pa
WHERE
    a.attack_id=pa.attack_id 
    AND INSTR(a.attack_name, ' ')>0 
GROUP BY
    a.attack_id,
    a.attack_name 
HAVING
    COUNT(DISTINCT pa.pokemon_id)>=2;

-- Filter for attacks known by 2 or more distinct Pokémon