
## Part 1

1. Make a list of data you think that Telenor needs to store.
2. Show how these data can be stored in tables
(draw 3-5 tables and fill in 3 rows of  example data for each table.
3. Check if any of the tables depend on each other (explain)
and underline possible unique identificators in each table.
4. Draw a simple map of the relations as shown in the figure, if any relation between the tables.
Draw a line between the tables and columns that are related.


Customer
- id PRIMARY
- name
- email
- address

PhonePlan
- id PRIMARY
- price
- data_limit
- description

PhoneSubscription
- id PRIMARY
- phonenumber
- starts_at
- ends_at
- plan : PhonePlan
- customer : Customer

Payment
- id PRIMARY
- kid UNIQUE
- due_date
- paid_date
- subscription : PhoneSubscription


## Part 2

1. Make the database "University" and write the command you used.

2. Import university.sql
Write a short description of the way it was done and the commands used.
Show the output from the commande utskriften  SHOW TABLES; in the university database.

3. What is  a primary key and
which primary keys exist in the tables of this database?

4. What is a foreign key and
which foreign keys exists in this database?

5. Registrer data in some tables. (Write the SQL commands you are using). 

    a. Register yourself as a   student in the student table. 
    b. Register your home commune in the location table.
    c. Register IMT in the  department table.
    d. Register INF230 in the course table.
    e. Register Ingunn Burud as instructor in the  instructor table.

6. What is possible to do?
Write what you have tried and what happends.
Write up some conclusions on this.

    a. Is it possible to register yourself in the enrollment table now ? Why/why not?
    b. Is it possible to register  Ingunn as qualified  instructor in INF230 in the qualified               table now ? Why/why not ?
    c. What do you do with students and instructors that have a middle name ? 
    d. Can you register a course in the course table that does not have a course                         description ?     Why/why not ?

    e. What are the limitations on the loc_country in the location table ?