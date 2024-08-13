create database vmotion; 
use vmotion;

create table cadastro(
id int not null primary key identity,
nome varchar(60) not null
);

insert into cadastros (nome) values('nii');

select * from cadastros;
