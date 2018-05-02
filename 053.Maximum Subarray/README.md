# 思路

1.动态规划，定义当前值cur_val, 最大值max_val, 组合值mix_val = cur_val + max_val。 每次遍历都将从将从这三个值中选取最大值,并赋值给max_val。遍历结束后得到最大值max_val。


## Python

实现了思路1
