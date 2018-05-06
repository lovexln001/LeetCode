# 思路

1.前序顺序，排列链表。重点root->left的节点全部在root->right的节点之前。那么怎么处理呢，只要将root->right挂在root->left最后一个节点上，然后将root->left挂在原来root->right，即可。

## C

实现了思路1

