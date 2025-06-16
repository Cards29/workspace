-- 1
SELECT name, max(hp) 
FROM pokemon
GROUP BY name;


-- 3
SELECT attack_name FROM attacks
WHERE attack_name >= '% %';

-- 4
SELECT t.first_name
-- FROM attacks a, pokemon_attacks pa
FROM trainer t, powner po, pokemon p, pokemon_attacks pa, attacks a
WHERE t.trainer_id(+) = po.trainer_id and po.pokemon_id(+) = p.pokemon_id and p.pokemon_id(+) = pa.pokemon_id and pa.attack_id(+) = a.attack_id and
-- WHERE pa.attack_id (+) = a.attack_id  and
    a.attack_power > 50
GROUP BY t.first_name;

-- 7
CREATE OR REPLACE PROCEDURE addNewTnP(tid NUMBER, pid NUMBER) 
BEGIN 
    INSERT INTO powner VALUES (tid, pid);
END addNewTnP;
/

-- 8
CREATE OR REPLACE FUNCTION calculateAvg(namee VARCHAR2(20)) RETURN NUMBER IS
    ap NUMBER;
BEGIN 
    SELECT avg(hp+attack+defense+speed) INTO ap
    FROM pokemon
    WHERE namee = name;
    RETURN ap;
END calculateAvg;
/

-- 10
CREATE OR REPLACE PROCEDURE delete_pokemon_with_low_stats(namee NUMBER) 
BEGIN 
    DELETE FROM pokemon 
    HAVING avg(hp+attack+defense+speed) < namee;
END delete_pokemon_with_low_stats;
/

