// 206. Reverse Linked List [E]
// LeetCode reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        stack<ListNode*> st;
        while(head != nullptr) {
            st.push(head);
            head = head->next;
        }
        ListNode* cur = st.top();
        st.pop();
        ListNode* newHead = cur;
        while(!st.empty()) {
            cur->next = st.top();
            st.pop();
            cur = cur->next;
        }
        cur->next = nullptr;
        return newHead;
    }
};