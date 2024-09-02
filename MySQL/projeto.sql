delimiter //
create procedure viewProfit()
begin
start transaction;
if !=userExiste 
commit
else
rollback;
end if
end;
// delimiter ;

delimiter //
create procedure createAdress(pc_cep int, pc_numero int, pc_complemento varchar(255))
begin
start transaction;

set @adressExists = (
	select
    cep,
    numero
    from endereco
    where cep = pc_cep and numero = pc_numero
    limit 1
);

insert into endereco () values ();

if @adressExists != null then
commit;
else
rollback;
end if
end;
// delimiter ;
