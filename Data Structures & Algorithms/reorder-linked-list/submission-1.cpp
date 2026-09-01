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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next){ 
            return;
        }

        ListNode* last = head;
        ListNode* middle = head;

        while(last->next && last->next->next){
            last = last->next->next;
            middle = middle->next;
        }

    
        ListNode* sec = head->next;

        while(head != middle){
            ListNode* lastprev = head;
            while(lastprev->next->next){
                lastprev = lastprev->next;
            }
            last = lastprev->next;
            lastprev->next = nullptr;

            head->next = last;
            last->next = sec;
            
            head = sec;
            sec = head->next;
        }

    }
};
