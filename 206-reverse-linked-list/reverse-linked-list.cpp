class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* NEXT = head;
        while(curr){
            NEXT = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NEXT;
        }
        return prev;
    }
};