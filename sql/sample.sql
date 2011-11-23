drop table user;
drop table collections;

/*create database db;*/
create table user (
    id int primary key,
    name char(10),
    gender boolean,
    age tinyint
);

insert into user(id,name,gender,age) values(1, "whoomin", 0, 20);
insert into user values(2, "amoblin", 1, 21);

insert into user values(3, "amoblin", 1, 21);
/* select * from user where age > any(10, 20); */
update user set age = age - 1 where id=1;
delete from user where id=2;
/* select * from user ; */

/* 修改表结构 */
/*alter table user add birth date;
/* alter table user drop gender; */
/*update user set birth="1988-09-27" where id=1;
insert into user(id, name, gender, age) values(3, "csip", 1, 18);
/* select gender, sum(age) from user group by gender; */
/* select count(*) from user group by gender; */

create table collections(
    id int primary key,
    name char(20),
    owner int,
    description varchar(50)
);

insert into collections values(1, "G1", 1, "");
insert into collections values(2, "5320XM", 2, "");
insert into collections values(3, "Air", 1, "");
insert into collections values(4, "CQ40", 2, "");

select * from collections c left join user u on c.owner = u.id;
/* select * from collections c, user u where c.owner > 0; */
/* where c.owner = u.id; */
