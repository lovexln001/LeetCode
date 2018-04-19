/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *pcur=head, *ppre=NULL;
    int i;
    for(i=1; pcur; ++i){
        if(i%2 == 1){
            ppre=pcur;
            pcur = pcur->next; 
        }else{
            struct ListNode *pt = pcur->next;
            if(head == ppre)head = head->next;
            pcur->next = ppre;
            pcur = pt; 
            if(pt && pt->next)
                ppre->next = pt->next;
            else
                ppre->next = pt;
        }
    }
    return head;
}