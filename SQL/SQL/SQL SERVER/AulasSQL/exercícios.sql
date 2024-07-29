use Aula
-- verificando se tds os itens foram inseridos:
--select * from Evento

--select * from Evento as E
--	left join Sala as S  -- join junta id com id das tabelas
--	on E.IDSala = S.IDSala -- apelido para a tabela

--select * from Sala

-------- filtrando dados --------
-- ##########################################
--select 
--E.descricao as 'Nome do Evento', -- da tabela evento eu quero a coluna descrição
--S.Nome as 'sala',
--S.Capacidade
--from Evento E
--	left join Sala S

-------- convertendo dados --------
-- ##########################################

--SELECT
--	-- apelido para a coluna
--    CONVERT(VARCHAR(10), GETDATE(), 103) AS Data, --dá um apelido para as colunas mesmo que nãos ej ao nome dela será exig=bido assim, 103 converte a data para brasil
--    CONVERT(VARCHAR(5), GETDATE(), 108) AS Horas -- converte as horas para horas normais e mostra apoenas hora e segundo pois 5


-------- como alterar uma tabela --------
-- ##########################################

---- Adicionando coluna
--ALTER TABLE NomeTabela
--ADD NomeColuna Tipo;
 
---- Excluindo coluna
--ALTER TABLE NomeTabela
--DROP COLUMN NomeColuna;
 
---- Renomeando coluna
--ALTER TABLE NomeTabela
--RENAME COLUMN AntigoNome to NovoNome;
 
---- Alterando tipo da coluna
--ALTER TABLE NomeTabela
--ALTER COLUMN NomeColuna Tipo;

-- crud = create, read, update, delete

-- necessa´rio entener join
-------- ex 1 --------
-- ##########################################
--SELECT
--    E.IDEvento,
--    E.Descricao AS "Descrição do Evento",
--    CONVERT(VARCHAR(10), E.DtHrInicio, 103) AS "Data Início",
--    CONVERT(VARCHAR(5), E.DtHrInicio, 108) AS "Hora Início",
--    CONVERT(VARCHAR(10), E.DtHrFim, 103) AS "Data Fim",
--    CONVERT(VARCHAR(5), E.DtHrFim, 108) AS "Hora Fim",
--    S.Nome AS "Nome da Sala"
-- FROM Evento E
-- LEFT JOIN Sala S
--    ON E.IDSala = S.IDSala

--WHERE GetDate() BETWEEN DtHrInicio AND DtHrFim

--UPDATE Evento
--SET DtHrInicio = '16/07/2024 08:00', --Coloque a data e a hora de hoje
--    DtHrFim = '16/07/2024 12:00'
--WHERE IDEvento = '414BDC9NB11N'


-------- ex 2-------
-- ##########################################
-- exibir as informações como solicitado
-- encontrar as 3 salas com maior capacidade
--select top 3 Capacidade

--from Sala
--order by Capacidade desc

-- ou

--SELECT TOP 3
--    Nome 'Nome da Sala',
--    Capacidade
--FROM Sala


-------- ex 3 -------
-- relaciona nome da pessoa com o id do evento
--select 
--P.Nome,
--EvPe.IDEvento
--FROM Pessoa P
--LEFT JOIN EventoPessoa EvPe
--ON EvPe.IDPessoa = P.IDPessoa

-- ########################

--SELECT
--    P.Nome as 'Responsáveis',
--    E.Descricao,
--    E.DtHrInicio as 'Data evento',
--    S.Nome as 'Nome Sala'
--FROM Pessoa P
--LEFT JOIN EventoPessoa EvPe
--    ON EvPe.IDPessoa = P.IDPessoa
--LEFT JOIN Evento E
--    ON EvPe.IDEvento = E.IDEvento
--LEFT JOIN Sala as S
--    ON E.IDSala = S.IDSala
----WHERE EvPe.PapelEvento = 'Responsaveis';

--select * from EventoPessoa

SELECT
P.Nome as 'Responsáveis',  -- define as colunas que eu quero mostrar
E.Descricao,
E.DtHrInicio as 'Data evento',
S.Nome as 'Nome Sala'
FROM Pessoa P
LEFT JOIN EventoPessoa EvPe -- juntei Pessoa com EventoPessoa para relacionar a pessoa responsável com o nome do evento pelo qual ela é pelo id
ON EvPe.IDPessoa = P.IDPessoa
LEFT JOIN Evento E -- juntei o evento que tem a descrição com o EvPe para saber dessas pessoas respoinsáveis qual a descrição do evento delas
On EvPe.IDEvento = E.IDEvento --juntei a sala do evento com o Id DA SALA dessas eventos filtrados para mostrar o nome da sala
LEFT JOIN Sala as S 
on E.IDSala = S.IDSala
WHERE EvPe.PapelEvento = 'Responsavel';

-- comenatários:

--SELECT
--P.Nome as 'Responsáveis',  -- Seleciona a coluna 'Nome' da tabela 'Pessoa' e a renomeia como 'Responsáveis'
--E.Descricao,               -- Seleciona a coluna 'Descricao' da tabela 'Evento'
--E.DtHrInicio as 'Data evento', -- Seleciona a coluna 'DtHrInicio' da tabela 'Evento' e a renomeia como 'Data evento'
--S.Nome as 'Nome Sala'      -- Seleciona a coluna 'Nome' da tabela 'Sala' e a renomeia como 'Nome Sala'
--FROM Pessoa P              -- Especifica a tabela 'Pessoa' com o alias 'P'
--LEFT JOIN EventoPessoa EvPe 
--ON EvPe.IDPessoa = P.IDPessoa -- Realiza um LEFT JOIN entre 'Pessoa' (P) e 'EventoPessoa' (EvPe) com base na coluna 'IDPessoa'
--LEFT JOIN Evento E 
--On EvPe.IDEvento = E.IDEvento -- Realiza um LEFT JOIN entre 'EventoPessoa' (EvPe) e 'Evento' (E) com base na coluna 'IDEvento'
--LEFT JOIN Sala as S 
--on E.IDSala = S.IDSala        -- Realiza um LEFT JOIN entre 'Evento' (E) e 'Sala' (S) com base na coluna 'IDSala'
--WHERE EvPe.PapelEvento = 'Responsavel'; -- Filtra os resultados onde a coluna 'PapelEvento' na tabela 'EventoPessoa' é igual a 'Responsavel'

















--SELECT
--    E.IDEvento,
--    E.Descricao AS "Descrição do Evento",
--    CONVERT(VARCHAR(10), E.DtHrInicio, 103) AS "Data Início",
--    CONVERT(VARCHAR(5), E.DtHrInicio, 108) AS "Hora Início",
--    CONVERT(VARCHAR(10), E.DtHrFim, 103) AS "Data Fim",
--    CONVERT(VARCHAR(5), E.DtHrFim, 108) AS "Hora Fim",
--    S.Nome AS "Nome da Sala"
-- FROM Evento E
-- LEFT JOIN Sala S
--    ON E.IDSala = S.IDSala

--WHERE GetDate() BETWEEN DtHrInicio AND DtHrFim

--UPDATE Evento
--SET DtHrInicio = '16/07/2024 08:00', --Coloque a data e a hora de hoje
--    DtHrFim = '16/07/2024 12:00'
--WHERE IDEvento = '414BDC9NB11N'





