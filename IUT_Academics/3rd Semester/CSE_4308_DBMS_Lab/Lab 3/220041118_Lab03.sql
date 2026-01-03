CREATE TABLE restaurant 
(
    rest_id NUMBER,
    name VARCHAR(50),
    city VARCHAR(30),
    cuisine VARCHAR(30),
    CONSTRAINT pk_rest PRIMARY KEY (rest_id)
);

CREATE TABLE dish
(
    dish_id NUMBER,
    name VARCHAR(50),
    cuisine VARCHAR(30),
    price NUMBER(5,2),
    taste VARCHAR(20),
    rest_id NUMBER,
    CONSTRAINT pk_dish PRIMARY KEY (dish_id),
    CONSTRAINT fk_rest FOREIGN KEY (rest_id)
    REFERENCES restaurant(rest_id) ON DELETE CASCADE
);

CREATE TABLE customer
(
    cust_id NUMBER,
    first_name VARCHAR(30),
    last_name VARCHAR(30),
    city VARCHAR(30),
    CONSTRAINT pk_cust PRIMARY KEY (cust_id)
);

INSERT INTO RESTAURANT VALUES (1,'Bella Italia','New York','Italian');
INSERT INTO RESTAURANT VALUES (2,'Dragon Palace','San Francisco','Chinese');
INSERT INTO RESTAURANT VALUES (3,'Spice Route','Chicago','Indian');
INSERT INTO RESTAURANT VALUES (4,'Sushi World','Los Angeles','Japanese');
INSERT INTO RESTAURANT VALUES (5,'Taco Fiesta','Houston','Mexican');

INSERT INTO DISH VALUES (1,'Margherita Pizza','Italian',12.99, 'Savory', 1);
INSERT INTO DISH VALUES (2, 'Spaghetti Carbonara','Italian' ,14.99, 'Savory', 1);
INSERT INTO DISH VALUES (3, 'Sweet and Sour Pork','Chinese', 10.99,'Sweet', 2);
INSERT INTO DISH VALUES (4, 'Kung Pao Chicken', 'Chinese', 11.99 ,'Spicy', 2);
INSERT INTO DISH VALUES (5, 'Butter Chicken', 'Indian' ,13.50 ,'Spicy', 3);
INSERT INTO DISH VALUES (6, 'Tandoori Chicken', 'Indian' ,14.00 ,'Spicy', 3);
INSERT INTO DISH VALUES (7, 'California Roll', 'Japanese', 8.99 ,'Savory', 4);
INSERT INTO DISH VALUES (8, 'Salmon Sashimi', 'Japanese', 15.99 ,'Savory', 4);
INSERT INTO DISH VALUES (9, 'Chicken Tacos', 'Mexican' ,9.99 ,'Spicy', 5);
INSERT INTO DISH VALUES (10, 'Beef Burrito', 'Mexican', 11.50 ,'Spicy', 5);

INSERT INTO CUSTOMER VALUES (1, 'John', 'Smith', 'New York');
INSERT INTO CUSTOMER VALUES (2, 'Mary', 'Johnson', 'Los Angeles');
INSERT INTO CUSTOMER VALUES (3, 'Robert', 'Brown', 'Chicago');
INSERT INTO CUSTOMER VALUES (4, 'Linda', 'Davis', 'Houston');
INSERT INTO CUSTOMER VALUES (5, 'Michael', 'Miller', 'Phoenix');

--* queries
SELECT DISTINCT cuisine FROM DISH;
SELECT * FROM DISH WHERE PRICE BETWEEN 10 AND 15;
SELECT * FROM DISH WHERE name LIKE 'Chicken%';
SELECT * FROM DISH WHERE name LIKE '%Roll%';
SELECT * FROM DISH WHERE name LIKE '% % %' AND name NOT LIKE '% % % %';
SELECT (FIRST_NAME||' '||LAST_NAME) AS FULL_NAME, city FROM customer;
SELECT * FROM dish ORDER BY CUISINE asc, PRICE desc;

CREATE TABLE customer_dish
(
    cust_id NUMBER,
    dish_id NUMBER,
    order_date DATE
);

ALTER TABLE customer_dish ADD CONSTRAINT fk_cust1 FOREIGN KEY (cust_id) REFERENCES customer(cust_id);
ALTER TABLE customer_dish ADD CONSTRAINT fk_dish1 FOREIGN KEY (dish_id) REFERENCES dish(dish_id);


