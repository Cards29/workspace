CREATE TABLE ResearchGroup (
    group_name VARCHAR(50) ,
    lab VARCHAR(50) NOT NULL,
    budget DECIMAL(10, 2),
    group_head VARCHAR(100),
    CONSTRAINT pk_name PRIMARY KEY (group_name)
);

CREATE TABLE Member (
    member_id INT,
    name VARCHAR(100) NOT NULL,
    contact_number VARCHAR(15),
    research_lab VARCHAR(50),
    CONSTRAINT pk_id_1 PRIMARY KEY (member_id),
    CONSTRAINT fk_mem FOREIGN KEY (research_lab) REFERENCES ResearchGroup(group_name)
);

CREATE TABLE Group_Faculty (
    faculty_id INT PRIMARY KEY,
    FOREIGN KEY (faculty_id) REFERENCES Member(member_id)
);

CREATE TABLE Group_Student (
    student_id INT PRIMARY KEY,
    supervisor_id INT,
    FOREIGN KEY (student_id) REFERENCES Member(member_id),
    FOREIGN KEY (supervisor_id) REFERENCES Faculty(faculty_id)
);

