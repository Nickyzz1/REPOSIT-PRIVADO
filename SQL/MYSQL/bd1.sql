CREATE DATABASE FLORICULTURA;
USE FLORICULTURA;

CREATE TABLE ESTOQUES(
IDESTOQUE INT NOT NULL PRIMARY KEY auto_increment,
QUANTIDADE INT NOT NULL
);

CREATE TABLE PRODUTOS(
IDPRODUTO INT NOT NULL PRIMARY KEY auto_increment,
TIPO VARCHAR(60) NOT NULL,
IDESTOQUE INT NOT NULL,
PRECO FLOAT,
foreign key(IDESTOQUE) REFERENCES ESTOQUES(IDESTOQUE)
);

CREATE TABLE CLIENTES(
IDCLIENTE INT NOT NULL PRIMARY KEY auto_increment,
NOME VARCHAR(60) NOT NULL,
ENDEREÇO VARCHAR(255) NOT NULL,
TEL VARCHAR(60)NOT NULL,
CARGO VARCHAR(60) NOT NULL,
DATACONTRATACAO DATETIME NOT NULL
);

CREATE TABLE FUNCIONARIO(
IDFUNCIONARIO INT NOT NULL PRIMARY KEY auto_increment,
RG varchar(60) NOT NULL,
NOME VARCHAR(60) NOT NULL,
ENDEREÇO VARCHAR(255) NOT NULL,
TEL VARCHAR(60)NOT NULL,
CARGO VARCHAR(60) NOT NULL,
DATACONTRATACAO DATETIME NOT NULL
);

CREATE TABLE PEDIDOS(
IDPEDIDO INT NOT NULL PRIMARY KEY auto_increment,
TIPO VARCHAR(60) NOT NULL,
QUANTIDADE INT,
IDPRODUTO INT,
IDCLIENTE INT NOT NULL,
IDFUNCIONARIO INT NOT NULL,
DATACOMPRA DATETIME NOT NULL,
VALOR FLOAT NOT NULL,
foreign key(IDPRODUTO) REFERENCES PRODUTOS(IDPRODUTO),
foreign key(IDCLIENTE) REFERENCES CLIENTES(IDCLIENTE),
foreign key(IDFUNCIONARIO) REFERENCES FUNCIONARIO(IDFUNCIONARIO)
);

SHOW TABLES;


