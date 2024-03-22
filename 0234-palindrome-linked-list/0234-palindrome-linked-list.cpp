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
private:
    ListNode* getmid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reversell(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* mid = getmid(head);

        ListNode* cur2 = mid->next;
        mid->next = NULL;

        ListNode* curr2 = reversell(cur2);

        while(curr && curr2) {
            if(curr->val != curr2->val) {
                return false;
            }
            curr = curr->next;
            curr2 = curr2->next;
        }

        return 1;
    }
};