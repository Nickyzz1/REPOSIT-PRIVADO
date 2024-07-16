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
-- ##########################################


--ORDER BY Capacidade DESC





