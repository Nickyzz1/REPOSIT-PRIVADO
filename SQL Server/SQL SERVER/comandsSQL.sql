use nicolle

--create table colaborators (EDV int primary key, Names varchar(60), Age int, Salary float);
--dbo
--INSERT INTO colaborators(EDV, Names, Age, salary) values (12345, 'nicolle', 18, 1900.0)
--INSERT INTO colaborators(EDV, Names, Age, salary) values (789944, 'Sasa', 19, 1900.0)
--INSERT INTO colaborators(EDV, Names, Age, salary) values (189944, 'queila', 23, 1900.0)
--INSERT INTO colaborators(EDV, Names, Age, salary) values (289944, 'Andrey', 19, 1900.0)
--INSERT INTO colaborators(EDV, Names, Age, salary) values (389944, 'Karlla', 16, 1900.0)

SELECT *from colaborators;
SELECT Names, Age from colaborators WHERE Age < 19;
SELECT Names, Age from colaborators ORDER BY Age;
SELECT Names, Age, salary from colaborators ORDER BY salary;
--UPDATE colaborators SET Names = 'Nicolas' WHERE EDV = 456789;
--UPDATE colaborators SET Age = 20 WHERE EDV = 456789;
--UPDATE colaborators SET Age = 19 WHERE EDV = 90876;

--UPDATE colaborators SET salary = 3500 WHERE EDV = 456789;
--UPDATE colaborators SET salary = 60001 WHERE EDV = 189944;
--UPDATE colaborators SET salary = 40000 WHERE EDV = 12345;
--Delete from colaborators WHERE EDV = 456789;

Delete colaborators

