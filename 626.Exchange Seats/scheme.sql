# Write your MySQL query statement below
SELECT @i := @i + 1 as id, t.student
FROM (SELECT id, student,IF(id&1, id+1, id-1) as weight FROM seat ORDER BY weight) as t ,(SELECT @i := 0) as tmp
