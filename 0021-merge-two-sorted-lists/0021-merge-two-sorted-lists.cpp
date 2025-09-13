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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
         ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;  // Tail pointer for the new list

        // Traverse both lists until one gets exhausted
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                temp->next = list1;   // attach t1 node
                temp = list1;         // move tail forward
                list1 = list1->next;     // move t1 ahead
            } else {
                temp->next = list2;   // attach t2 node
                temp = list2;         // move tail forward
                list2 = list2->next;     // move t2 ahead
            }
        }

        // Attach the remaining nodes (only one of t1 or t2 will be non-null)
        if (list1) temp->next = list1;
        else temp->next = list2;

        // The merged list starts after dummyNode
        return dummyNode->next;
    }
};