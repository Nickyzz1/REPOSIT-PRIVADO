use db_senai;

/*create database db_senai;
show databases;
show tables;*/

drop table aluno;

create table aluno(
IDAluno int not null primary key auto_increment,
nome varchar(60) not null,
sobrenome varchar(60) not null
)DEFAULT CHARSET utf8mb4;

create table professor(
IDProfessor int not null primary key auto_increment,
nome varchar(60) not null,
sobrenome varchar(60) not null
)DEFAULT CHARSET utf8mb4;

create table turma(
IDTurma int primary key auto_increment not null,
IDAluno int,
IDProfessor int,
FOREIGN KEY (IDAluno) REFERENCES aluno(IDAluno),
FOREIGN KEY (IDProfessor) REFERENCES professor(IDProfessor)
)default charset utf8mb4
