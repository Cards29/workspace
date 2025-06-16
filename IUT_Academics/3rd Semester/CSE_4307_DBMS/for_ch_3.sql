create table instructor (
	name varchar2(10),
	id   number
);

create table teaches (
	name varchar2(10),
	id   number,
    CONSTRAINT raichu_id Foreign key(id) references instructor
);

INSERT INTO INSTRUCTOR VALUES('Raihan',110);
INSERT INTO INSTRUCTOR VALUES('Sabbir',111);
INSERT INTO INSTRUCTOR VALUES('Faisal',112);

INSERT INTO TEACHES VALUES('DS',111);
INSERT INTO TEACHES VALUES('DBMS',110);
INSERT INTO TEACHES VALUES('OOP',112);

ALTER TABLE instructor add constraint pikachu_id primary key (id);

DROP TABLE TEACHES;

select i.NAME instructorname, t.NAME courseid
    from instructor i, teaches t
    where i.ID = t.ID;

SELECT i.name, t.name
FROM INSTRUCTOR i
JOIN TEACHES t ON i.ID = t.ID;
