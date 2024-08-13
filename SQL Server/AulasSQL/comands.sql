use aulasSqlNi


-------- criando as tabelas --------
-- #########################################
--create table sala(
--IDSala int primary key not null, 
--nome varchar(50) not null, 
--capacidade int not null);
-- go  -- uma parada

-------- inserindo valores --------
-- ##########################################

--insert into sala VALUES(5, 'sala ti 2', 20)

--iserir varias linhas

--insert into sala values (1, 'sala ti', 20),(2, 'sala de reunião', 30), (3, 'Sala de palestras 1', 80), (4, 'Sala de aula', 18);

-------- visualizando colunas e linhas --------
-- ###################################################

--select* from sala
--go
--select nome as 'nomeDaSala' from sala
--go
--select nome, capacidade from sala

-- ordenando

-- select* from sala order by capacidade --crescente
-- select* from sala order by capacidade desc -- decrescente
-- select* from sala order by capacidade desc, nome ASC -- decrescente, caso dois valores forem iguais por exemplo sala1 10 e sala2 10, ordene pelo nome

-------- ex -------- 
-- ###################################################

--CREATE TABLE Evento (
--  IDEvento INT NOT NULL PRIMARY KEY,
--  IDSalaEv INT NOT NULL FOREIGN KEY REFERENCES sala(IDSala),
--  Descricao VARCHAR(100) NOT NULL,
--  DtHrInicio DATETIME NOT NULL,
--  DtHrFim DATETIME NOT NULL
--);


--INSERT INTO Evento VALUES (
--    1,
--    1,
--    'Aula de IoT',
--    '26/03/2022 19:00',
--    '26/03/2022 22:30'
--);

-- retona o ultimo id:  o max(IDEvento)
-- cria um id automáticamente pois ir´pa inserir após a ultima coluna
--insert into Evento values(
--(select MAX(IDEvento) from Evento) + 1,
--1, 
--'aula de estrutura de dados',
-- '26/03/2022 19:00',
-- '26/03/2022 22:30' 
--)
-- e se não tiver nada na tablea?
--insert into Evento values(
--(select isNull(MAX(IDEvento), 0) from Evento) + 1,
--1, 
--'aula de estrutura de dados2',
-- '26/03/2022 19:00',
-- '26/03/2022 22:30' 
--)

select* from Evento

-------- comandos --------
-- #########################################
--drop table sala

--create database nomeDoDataBase
-- create squema nomeSquema
-- create table.nomeSquema.NometableQueDesejaCriar
-- drop nomeSquema
--ddl -> comandos de estruturas create, alter, truncate, drop rename
--dml -> insert, update
--dcl
 -- ldf guarda todos as ações e comandos que vc faz
 -- mdf guarda tds os dados
--create squema exercicio1
--create table exercicio1.evento(
--IDEvento primary key not null, 
--assunto varchar(255), not null, 
--descricao varchar, 
--dataHorarioInicio date time not null,
-- dataHorarioFim date time not null);

