# Write your MySQL query statement below
SELECT p.Num as ConsecutiveNums
FROM (SELECT Num,
     if(@pre = (@pre := Num), @con:=@con+1, @con:=1) as val
     FROM Logs, (SELECT @con := 1, @pre := A) INIT ) as p
WHERE p.val >=3
GROUP BY p.Num;
