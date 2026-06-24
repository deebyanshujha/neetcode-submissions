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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        while(temp1 != nullptr && temp2 != nullptr){
            int sum = temp1->val + temp2->val;
            if(carry){
                sum++;
                carry = 0;
            }
            if(sum > 9){
                carry = 1;
                sum = sum % 10;
            }
            curr->next = new ListNode(sum);
            curr = curr->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1 != nullptr){
            int value = temp1->val;
            if(carry){
                value++;
                carry = 0;
            }
            if(value > 9){
                carry = 1;
                value = value % 10;
            }
            curr->next = new ListNode(value);
            curr = curr->next;
            temp1 = temp1->next;
        }
        while(temp2 != nullptr){
            int value = temp2->val;
            if(carry){
                value++;
                carry = 0;
            }
            if(value > 9){
                carry = 1;
                value = value % 10;
            }
            curr->next = new ListNode(value);
            curr = curr->next;
            temp2 = temp2->next;
        }
        if(carry){
            curr->next = new ListNode(1);
        }
        return ans->next;
    }
};
