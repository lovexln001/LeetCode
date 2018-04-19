/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p, *pre;
    while(l1 || l2){
        int t;
        struct ListNode *pt = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        pt->val = 0;
        pt->next = NULL;
        if(l1 && l2){
            if(l1->val < l2->val){
                t = l1->val;
                l1 = l1->next;
            }
            else{
                t = l2->val;
                l2 = l2->next;
            }
        }else if(l1){
            t = l1->val;
            l1 = l1->next;
        }else{
            t = l2->val;
            l2 = l2->next;
        }

        if(p){
            pt->val = t;
            pre->next = pt;
            pre = pt;
        }else{
            p = pt;
            p->val = t;
            pre=pt;
        }
    }
    return p;
}