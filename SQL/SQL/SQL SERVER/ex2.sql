use Aula

----- ex 5 -----
--SELECT
--E.Descricao AS "Evento",
--S.Nome AS "Sala",
--S.Capacidade,
--COUNT(EP.IDPessoa) AS "Quantidade Participantes",  -- conta quantos ids uma reunião tem. comnta quantas linhas de acordo com o agrupamento já feito
--CASE WHEN S.Capacidade < COUNT(EP.IDPessoa) THEN 'Ultrapassou o Limite!' -- quando a capacidade vor menor que a quantidade de pessoas convidadas o limite é ultrapassado
--ELSE 'Limite OK' END AS "Avaliação da Capacidade"  -- cria uma coluna  chamada av. de capacidade para exibir os resultados
--FROM EventoPessoa EP
--INNER JOIN Evento E
--ON EP.IDEvento = E.IDEvento -- define as informações realcionáveis
--INNER JOIN Sala S
--ON S.IDSala = E.IDSala  -- define as informações realcionáveis
---- junta tds as infos para podermos usar depois
--GROUP BY E.Descricao, S.Nome, S.Capacidade, E.IDEvento
---- requisitos, se as linhas foremn iguais vão se juntar


----- ex 7 -----

--SELECT
--    E.Descricao AS "Evento",
--    S.Nome      AS "Sala",
--    S.Capacidade,
--	COUNT(EP.IDPessoa) as 'Convidados',
--    SUM(CONVERT(int, EP.Presenca)) AS "Quantidade Participantes",
-- --somo as presenças como int, depois de dividir por id evento e conta quatas pessoas p/cada evento
--CASE WHEN S.Capacidade > SUM(CONVERT(int, EP.Presenca)) and COUNT(EP.IDEvento) > S.Capacidade THEN 'Ultrapassaria o Limite!'
--ELSE 'Limite OK' END AS "Avaliação da Capacidade"
 
--FROM EventoPessoa EP
--INNER JOIN Evento E
--    ON EP.IDEvento = E.IDEvento
--INNER JOIN Sala S
--    ON S.IDSala = E.IDSala  -- alinhando todas as informações que preciso numa mesma linha -- todos os eventos porém eles ainda se repetem
--GROUP BY E.Descricao, S.Nome, S.Capacidade, E.IDEvento

-- após o groupo by eles não se repentem mais pois linhas iguais são agrupadas
-- o count é feito para cada idevento igual
-- sem o group by as linhas iguais se repetem


--- teste -----
--SELECT *
----E.Descricao AS "Evento",
----S.Nome AS "Sala",
----S.Capacidade
--FROM EventoPessoa EP
--INNER JOIN Evento E
--ON EP.IDEvento = E.IDEvento -- define as informações realcionáveis
--INNER JOIN Sala S
--ON S.IDSala = E.IDSala  -- define as informações relacionáveis
---- junta tds as infos para podermos usar depois
----where E.IDEvento = 'GRD7YKCKFTHF' -- conferindo se as linha siguais se repetem
---- com o group by as linhas iguais são agrupadas
----GROUP BY E.Descricao, S.Nome, S.Capacidade, E.IDEvento
---- requisitos, se as linhas foremn iguais vão se juntar

-- tabelas sozinhas
--select * from Evento
--select * from EventoPessoa
--select * from Sala

----- 8 -----

-- CRIANDO FUNÇÃO
--CREATE FUNCTION fMesAno (@Data DateTime)
--RETURNS VARCHAR(7) AS
--BEGIN
--RETURN(SUBSTRING(CONVERT(VARCHAR(10), @Data, 103), 4, 10))
--END
--Utilizar
--SELECT
--dbo.fMesAno(DtHrInicio) AS MesAno,
--COUNT(*) AS Eventos
--FROM Evento
--GROUP BY dbo.fMesAno(DtHrInicio)

--declare @var int
--set @var = 20
--create fuction fExemplo(@data dateTime) -- @indica que ´pe uma variável

--select 

--11 Crie uma função cujo o retorno deverá ser um único select e retornar uma
--tabela com:
--1- Quantidade de pessoas presentes no primeiro evento (mais antigo) que ocorreu.
--2- Nome da sala em que esse evento ocorreu.
--3- A Função será chamada com um parâmetro de busca. Como Aula, Palestra ou Reunião.
--Nome Evento, Nome Sala, Qtd Pessoas, Data Início, Hora Início.
--Desafio

CREATE FUNCTION fTables(@var varchar(50))
RETURNS TABLE AS
	RETURN
	(
	Select TOP 1
	CONVERT(varchar(10), E.DtHrInicio, 103) as 'data',
	E.Descricao
	FROM Evento as E
	where Descricao LIKE '%'+@var+'%'
	order by E.DtHrInicio asc
	)

SELECT *
FROM dbo.fTables('Aula')



