/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    while(p1){
        if(p2)p2 = p2->next;else return false;
        if(p2)p2 = p2->next;else return false;
        p1 = p1->next;
        if(p1 == p2) return true;
    }
    return false;
}