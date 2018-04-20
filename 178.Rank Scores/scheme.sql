# Write your MySQL query statement below
SELECT Score,
@rank := @rank + (@pre<>(@pre := Score)) Rank
FROM Scores,(SELECT @rank := 0, @pre := -1) INIT
ORDER BY Score DESC;
