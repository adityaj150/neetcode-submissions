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
        ListNode *head1 = head;
        int nodes = 0;
        while(head1){
            head1 = head1->next;
            nodes++;
        }

        head1 = head;
        int pivot = nodes - n;
        if(pivot == 0){
            return head->next;
        }

        for(int i = 0; i < nodes - 1; i++){
            if((i + 1) == pivot){
                head1->next = head1->next->next;
                break;
            }
            head1 = head1->next;
        }

        return head;
        
    }
};
