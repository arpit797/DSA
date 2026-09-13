# Write your MySQL query statement below

select un.unique_id,em.name 
from employees em
left join employeeuni un
on em.id=un.id;