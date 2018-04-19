/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *new_head = head;
    int i, max = 0;
    while(new_head){
        ++max;
        new_head = new_head->next;
    }
    new_head = head;
    for(i=1; i<=max-n-1; i++){
        new_head = new_head->next;
    }
    if(max == n){
        head = head->next;
    }
    else if(new_head->next){
        new_head->next = new_head->next->next;
    }
    return head;
}