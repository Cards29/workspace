DROP TABLE pokemon_attacks;
DROP TABLE powner;
DROP TABLE trainer;
DROP TABLE attacks;
DROP TABLE pokemon;

-- Create pokemon table
CREATE TABLE pokemon (
    pokemon_id NUMBER(10) PRIMARY KEY,
    name VARCHAR2(50) NOT NULL,
    type VARCHAR2(20) NOT NULL,
    hp NUMBER(10) CONSTRAINT chk_hp CHECK (hp > 0),
    attack NUMBER(10) CONSTRAINT chk_attack CHECK (attack > 0),
    defense NUMBER(10) CONSTRAINT chk_defense CHECK (defense > 0),
    speed NUMBER(10) CONSTRAINT chk_speed CHECK (speed > 0)
);

-- Insert data into pokemon table (increased pokemon data)
INSERT INTO pokemon VALUES (1, 'Bulbasaur', 'Grass', 45, 49, 49, 45);
INSERT INTO pokemon VALUES (2, 'Ivysaur', 'Grass', 60, 62, 63, 60);
INSERT INTO pokemon VALUES (3, 'Venusaur', 'Grass', 80, 82, 83, 80);
INSERT INTO pokemon VALUES (4, 'Charmander', 'Fire', 39, 52, 43, 65);
INSERT INTO pokemon VALUES (5, 'Charmeleon', 'Fire', 58, 64, 58, 80);
INSERT INTO pokemon VALUES (6, 'Charizard', 'Fire', 78, 84, 78, 100);
INSERT INTO pokemon VALUES (7, 'Squirtle', 'Water', 44, 48, 65, 43);
INSERT INTO pokemon VALUES (8, 'Wartortle', 'Water', 59, 63, 80, 58);
INSERT INTO pokemon VALUES (9, 'Blastoise', 'Water', 79, 83, 100, 78);
INSERT INTO pokemon VALUES (10, 'Pikachu', 'Electric', 35, 55, 40, 90);
INSERT INTO pokemon VALUES (11, 'Raichu', 'Electric', 60, 90, 55, 110);
INSERT INTO pokemon VALUES (12, 'Caterpie', 'Bug', 45, 30, 35, 45);
INSERT INTO pokemon VALUES (13, 'Metapod', 'Bug', 50, 20, 55, 30);
INSERT INTO pokemon VALUES (14, 'Butterfree', 'Bug', 60, 45, 50, 70);
INSERT INTO pokemon VALUES (15, 'Weedle', 'Bug', 40, 35, 30, 50);
INSERT INTO pokemon VALUES (16, 'Kakuna', 'Bug', 45, 25, 50, 35);
INSERT INTO pokemon VALUES (17, 'Beedrill', 'Bug', 65, 90, 40, 75);
INSERT INTO pokemon VALUES (18, 'Pidgey', 'Normal', 40, 45, 40, 56);
INSERT INTO pokemon VALUES (19, 'Pidgeotto', 'Normal', 63, 60, 55, 71);
INSERT INTO pokemon VALUES (20, 'Pidgeot', 'Normal', 83, 80, 75, 101);
-- Adding more pokemon
INSERT INTO pokemon VALUES (21, 'Sandshrew', 'Ground', 50, 75, 85, 40);
INSERT INTO pokemon VALUES (22, 'Sandslash', 'Ground', 75, 100, 110, 65);
INSERT INTO pokemon VALUES (23, 'Nidoran', 'Poison', 55, 47, 52, 41);
INSERT INTO pokemon VALUES (24, 'Nidorina', 'Poison', 70, 62, 67, 56);
INSERT INTO pokemon VALUES (25, 'Nidoqueen', 'Poison', 90, 92, 87, 76);

-- Create trainer table
CREATE TABLE trainer (
    trainer_id NUMBER(10) PRIMARY KEY,
    first_name VARCHAR2(30) NOT NULL,
    last_name VARCHAR2(30) NOT NULL,
    city VARCHAR2(30) NOT NULL
);

-- Insert data into trainer table (increased trainer data)
INSERT INTO trainer VALUES (1, 'Ash', 'Ketchum', 'Pallet Town');
INSERT INTO trainer VALUES (2, 'Misty', 'Williams', 'Cerulean City');
INSERT INTO trainer VALUES (3, 'Brock', 'Harrison', 'Pewter City');
INSERT INTO trainer VALUES (4, 'Gary', 'Oak', 'Pallet Town');
INSERT INTO trainer VALUES (5, 'Erika', 'Green', 'Celadon City');
INSERT INTO trainer VALUES (6, 'Jessie', 'Rocket', 'Viridian City');
INSERT INTO trainer VALUES (7, 'James', 'Rocket', 'Viridian City');
INSERT INTO trainer VALUES (8, 'Giovanni', 'Sakaki', 'Viridian City');
INSERT INTO trainer VALUES (9, 'Lance', 'Dragon', 'Blackthorn City');
INSERT INTO trainer VALUES (10, 'Steven', 'Stone', 'Mossdeep City');
-- Adding more trainers
INSERT INTO trainer VALUES (11, 'Cynthia', 'Henson', 'Celestic Town');
INSERT INTO trainer VALUES (12, 'Koga', 'Ishihara', 'Fuchsia City');
INSERT INTO trainer VALUES (13, 'Roxanne', 'McHugh', 'Rustboro City');
INSERT INTO trainer VALUES (14, 'Wallace', 'Norris', 'Sootopolis City');
INSERT INTO trainer VALUES (15, 'Clair', 'Klein', 'Blackthorn City');

-- Create attacks table
CREATE TABLE attacks (
    attack_id NUMBER(10) PRIMARY KEY,
    attack_name VARCHAR2(50) NOT NULL,
    attack_type VARCHAR2(20) NOT NULL,
    attack_power NUMBER(10) CONSTRAINT chk_attack_power CHECK (attack_power > 0)
);

-- Insert data into attacks table (increased attack data)
INSERT INTO attacks VALUES (1, 'Tackle', 'Normal', 40);
INSERT INTO attacks VALUES (2, 'Vine Whip', 'Grass', 45);
INSERT INTO attacks VALUES (3, 'Flamethrower', 'Fire', 90);
INSERT INTO attacks VALUES (4, 'Water Gun', 'Water', 40);
INSERT INTO attacks VALUES (5, 'Thunderbolt', 'Electric', 90);
INSERT INTO attacks VALUES (6, 'Bug Bite', 'Bug', 60);
-- Adding more attacks
INSERT INTO attacks VALUES (7, 'Earthquake', 'Ground', 100);
INSERT INTO attacks VALUES (8, 'Poison Sting', 'Poison', 15);
INSERT INTO attacks VALUES (9, 'Rock Slide', 'Rock', 75);
INSERT INTO attacks VALUES (10, 'Ice Beam', 'Ice', 90);
INSERT INTO attacks VALUES (11, 'Dragon Claw', 'Dragon', 80);

-- Create powner table (trainer owning pokemons)
CREATE TABLE powner (
    trainer_id NUMBER(10),
    pokemon_id NUMBER(10),
    CONSTRAINT pk_powner PRIMARY KEY (trainer_id, pokemon_id),
    CONSTRAINT fk_powner_trainer FOREIGN KEY (trainer_id) REFERENCES trainer(trainer_id),
    CONSTRAINT fk_powner_pokemon FOREIGN KEY (pokemon_id) REFERENCES pokemon(pokemon_id)
);

-- Insert data into powner table (increased trainer-pokemon pownership data)
INSERT INTO powner VALUES (1, 1);  -- Ash owns Bulbasaur
INSERT INTO powner VALUES (1, 4);  -- Ash owns Charmander
INSERT INTO powner VALUES (2, 7);  -- Misty owns Squirtle
INSERT INTO powner VALUES (3, 18); -- Brock owns Pidgey
INSERT INTO powner VALUES (4, 6);  -- Gary owns Charizard
INSERT INTO powner VALUES (5, 3);  -- Erika owns Venusaur
-- Adding more pownerships
INSERT INTO powner VALUES (6, 20); -- Jessie owns Pidgeot
INSERT INTO powner VALUES (7, 8);  -- James owns Wartortle
INSERT INTO powner VALUES (8, 9);  -- Giovanni owns Blastoise
INSERT INTO powner VALUES (9, 5);  -- Lance owns Charmeleon
INSERT INTO powner VALUES (10, 10); -- Steven owns Pikachu
-- Additional pownerships
INSERT INTO powner VALUES (11, 14); -- Cynthia owns Butterfree
INSERT INTO powner VALUES (12, 23); -- Koga owns Nidoran
INSERT INTO powner VALUES (13, 21); -- Roxanne owns Sandshrew
INSERT INTO powner VALUES (14, 22); -- Wallace owns Sandslash
INSERT INTO powner VALUES (15, 25); -- Clair owns Nidoqueen

-- Create pokemon_attacks table (many-to-many relationship between pokemon and attacks)
CREATE TABLE pokemon_attacks (
    pokemon_id NUMBER(10),
    attack_id NUMBER(10),
    CONSTRAINT pk_pokemon_attacks PRIMARY KEY (pokemon_id, attack_id),
    CONSTRAINT fk_pokemon_attacks_pokemon FOREIGN KEY (pokemon_id) REFERENCES pokemon(pokemon_id),
    CONSTRAINT fk_pokemon_attacks_attack FOREIGN KEY (attack_id) REFERENCES attacks(attack_id)
);

-- Insert data into pokemon_attacks table (increased pokemon-attacks data, ensuring each pokemon has at least one attack)
INSERT INTO pokemon_attacks VALUES (1, 2);  -- Bulbasaur can use Vine Whip
INSERT INTO pokemon_attacks VALUES (1, 6);  -- Bulbasaur can use Bug Bite
INSERT INTO pokemon_attacks VALUES (4, 3);  -- Charmander can use Flamethrower
INSERT INTO pokemon_attacks VALUES (4, 5);  -- Charmander can use Thunderbolt
INSERT INTO pokemon_attacks VALUES (7, 4);  -- Squirtle can use Water Gun
INSERT INTO pokemon_attacks VALUES (7, 9);  -- Squirtle can use Rock Slide
INSERT INTO pokemon_attacks VALUES (6, 5);  -- Charizard can use Thunderbolt
INSERT INTO pokemon_attacks VALUES (6, 7);  -- Charizard can use Earthquake
INSERT INTO pokemon_attacks VALUES (12, 8); -- Caterpie can use Poison Sting
INSERT INTO pokemon_attacks VALUES (14, 2); -- Butterfree can use Vine Whip
INSERT INTO pokemon_attacks VALUES (17, 6); -- Beedrill can use Bug Bite
INSERT INTO pokemon_attacks VALUES (20, 3); -- Pidgeot can use Flamethrower
INSERT INTO pokemon_attacks VALUES (25, 11); -- Nidoqueen can use Dragon Claw
-- Additional Pokémon with more attacks
INSERT INTO pokemon_attacks VALUES (2, 5);  -- Ivysaur can use Thunderbolt
INSERT INTO pokemon_attacks VALUES (9, 10); -- Blastoise can use Ice Beam
INSERT INTO pokemon_attacks VALUES (13, 7); -- Metapod can use Earthquake
INSERT INTO pokemon_attacks VALUES (18, 1); -- Pidgey can use Tackle
INSERT INTO pokemon_attacks VALUES (22, 9); -- Sandslash can use Rock Slide

COMMIT;