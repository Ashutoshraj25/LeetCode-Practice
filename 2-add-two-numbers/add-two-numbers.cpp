class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* c = new ListNode(0);
        ListNode* tempc = c;
        ListNode* a = l1;
        ListNode* b = l2;

        int carry = 0;

        while (a || b || carry) {
            int sum = carry;

            if (a) {
                sum += a->val;
                a = a->next;
            }

            if (b) {
                sum += b->val;
                b = b->next;
            }

            carry = sum / 10;
            tempc->next = new ListNode(sum % 10);
            tempc = tempc->next;
        }

        return c->next;
    }
};