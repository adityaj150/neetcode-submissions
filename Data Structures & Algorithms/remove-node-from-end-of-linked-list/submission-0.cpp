/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            delete(head);
            return NULL;
        } 

        int count = 0;
        ListNode *p = head;
        while(p){
            count++;
            p = p->next;
        }

        if (count == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        p = head;
        ListNode *q = NULL;
        for(int i = 0; i < (count - n); i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        p->next = NULL;
        delete(p);
        return head;
    }
};