# Write your MySQL query statement below
SELECT w1.Id
FROM Weather AS w1 INNER JOIN Weather AS w2
WHERE TO_DAYS(w1.Date)=TO_DAYS(w2.Date) +1 and w1.Temperature > w2.Temperature;
