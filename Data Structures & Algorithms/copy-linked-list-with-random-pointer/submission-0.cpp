/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) 
            return NULL;

        Node *ptr = head;

        while(ptr != NULL){
            Node *dupNode = new Node(ptr->val);
            dupNode->random = ptr->random;
            dupNode->next = ptr->next;
            ptr->next = dupNode;

            ptr = ptr->next->next;
        }

        //
        ptr = head;
        while(ptr != NULL){
            if(ptr->random != NULL){
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }

        Node* newHead = head->next;  
        Node* ptrOriginal = head;    
        Node* ptrCopy = newHead;     
       
        while (ptrOriginal != NULL) {
            ptrOriginal->next = ptrOriginal->next->next;

            if (ptrCopy->next != NULL) {
                ptrCopy->next = ptrCopy->next->next;
            }

            ptrOriginal = ptrOriginal->next;
            ptrCopy = ptrCopy->next;
        }

        return newHead;  

    }
};
