--Create schema Reunião;
--go
--Create table reunião.Sala(
--  IDSala INT NOT NULL PRIMARY KEY,
--  nome VARCHAR(100) NOT NULL,
--  capacidade int not null
-- );
-- go
 
--Create table reunião.Evento(
--  IDEvento INT NOT NULL PRIMARY KEY,
--  IDSalaEv INT NOT NULL FOREIGN KEY REFERENCES Sala(IDSala),
--  Descricao VARCHAR(100) NOT NULL,
--  DtHrInicio DATETIME NOT NULL,
--  DtHrFim DATETIME NOT NULL
--  );
--  go

  --Create table reunião.Pessoa(
  --IDPessoa INT NOT NULL PRIMARY KEY,
  --nome VARCHAR(50) NOT NULL,
  --funcao VARCHAR(50) not null
  --);

  
  --Create table reunião.Equipamento(
  --IDEquipamento INT NOT NULL PRIMARY KEY,
  --IDSalaEq INT,
  --nome VARCHAR(50) NOT NULL,
  --tipo VARCHAR(50) not null
  --);


  --Create table reunião.eventoEquipamento(
  --IDEvEq INT NOT NULL PRIMARY KEY,
  --IDEvento INT NOT NULL FOREIGN KEY REFERENCES Evento(IDEvento),
  --IDEquipamento INT NOT NULL FOREIGN KEY REFERENCES reunião.Equipamento(IDEquipamento)
  --);

  Create table reunião.eventoPessoa(
  IDEvPe INT NOT NULL PRIMARY KEY,
  IDEvento INT NOT NULL FOREIGN KEY REFERENCES Evento(IDEvento),
  IDPessoa INT NOT NULL FOREIGN KEY REFERENCES Pessoa(IDPessoa),
  papelEvento varchar(90) not null,
  presenca bit not null

  );


