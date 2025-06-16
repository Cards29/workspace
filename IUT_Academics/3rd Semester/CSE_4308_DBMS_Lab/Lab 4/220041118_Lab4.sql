CREATE TABLE vehicle (
    vehicle_id NUMBER,
    model VARCHAR2(50),
    type VARCHAR2(50),
    horsepower NUMBER,
    torque NUMBER,
    weight NUMBER,
    speed NUMBER,
    CONSTRAINT pk_vehi_id PRIMARY KEY (vehicle_id)
);

CREATE TABLE owner(
    owner_id NUMBER,
    first_name VARCHAR2(30),
    last_name VARCHAR2(30),
    city VARCHAR2(30),
    CONSTRAINT pk_ow_id PRIMARY KEY (owner_id)
);

INSERT INTO vehicle VALUES (1 ,'Toyota Corolla', 'Sedan', 132, 128, 2800, 112);
INSERT INTO vehicle VALUES (2, 'Honda Civic', 'Sedan', 158, 138, 2760, 125);
INSERT INTO vehicle VALUES (3, 'Ford Fusion', 'Sedan', 175, 175, 3431, 125);
INSERT INTO vehicle VALUES (4, 'Ford Mustang', 'Sports',310, 350, 3532, 155);
INSERT INTO vehicle VALUES (5, 'Chevrolet Camaro', 'Sports', 275, 295, 3354, 155);
INSERT INTO vehicle VALUES (6, 'Dodge Challenger', 'Sports', 305, 268, 3894, 155);
INSERT INTO vehicle VALUES (7, 'Honda CR-V','SUV', 190, 179, 3337, 112);
INSERT INTO vehicle VALUES (8, 'Toyota RAV4', 'SUV', 203, 184, 3370, 114);
INSERT INTO vehicle VALUES (9, 'Ford Explorer', 'SUV', 300, 310, 4345, 143);
INSERT INTO vehicle VALUES (10,'Tesla Model 3', 'Electric', 283, 307, 3554, 140);
INSERT INTO vehicle VALUES (11,'Tesla Model S', 'Electric', 762, 723, 4647, 155);

INSERT INTO owner VALUES (1, 'John', 'Smith', 'New York');
INSERT INTO owner VALUES (2, 'Sarah' ,'Johnson' ,'Los Angeles');
INSERT INTO owner VALUES (3, 'Michael', 'Williams', 'Chicago');
INSERT INTO owner VALUES (4, 'Emily','Brown', 'New York');
INSERT INTO owner VALUES (5, 'David', 'Jones', 'Houston');

CREATE TABLE owner_vehicle(
    owner_id NUMBER,
    vehicle_id NUMBER,
    CONSTRAINT fk_ow_id FOREIGN KEY (owner_id) REFERENCES owner(owner_id),
    CONSTRAINT fk_vehi_id FOREIGN KEY (vehicle_id) REFERENCES vehicle(vehicle_id)
);

INSERT INTO OWNER_VEHICLE VALUES (1,4);
INSERT INTO OWNER_VEHICLE VALUES (1,5);
INSERT INTO OWNER_VEHICLE VALUES (1,7);
INSERT INTO OWNER_VEHICLE VALUES (1,10);
INSERT INTO OWNER_VEHICLE VALUES (2,8);
INSERT INTO OWNER_VEHICLE VALUES (2,9);
INSERT INTO OWNER_VEHICLE VALUES (3,4);
INSERT INTO OWNER_VEHICLE VALUES (4,1);
INSERT INTO OWNER_VEHICLE VALUES (4,5);

SELECT AVG(horsepower) FROM vehicle;
SELECT TYPE, AVG(HORSEPOWER) FROM vehicle GROUP BY TYPE;  
SELECT TYPE,COUNT(*) FROM vehicle GROUP BY TYPE ;
SELECT * FROM VEHICLE WHERE WEIGHT> (SELECT AVG(VEHICLE.WEIGHT) FROM vehicle);

