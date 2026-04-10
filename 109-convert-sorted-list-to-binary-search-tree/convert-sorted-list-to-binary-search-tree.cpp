class Solution {
public:
    TreeNode* helper(ListNode* head){
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;

        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (temp) temp->next = NULL;

        TreeNode* root = new TreeNode(slow->val);

        root->left = helper(head);
        root->right = helper(slow->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};