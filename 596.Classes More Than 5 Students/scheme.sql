# Write your MySQL query statement below
SELECT class FROM (SELECT DISTINCT * FROM courses) as c
GROUP BY class HAVING COUNT( * ) >= 5;
