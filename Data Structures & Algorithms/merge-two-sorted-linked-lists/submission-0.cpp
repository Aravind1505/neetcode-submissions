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
         ListNode* nextptr = nullptr;
         ListNode* headptr = nullptr;
         ListNode* currptr = nullptr;

         if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
         
         while(list1 -> next != nullptr && list2 -> next != nullptr) {
            int val1 = list1 -> val;
            int val2 = list2 -> val;

            if (val1 <= val2) {
                nextptr = list1 -> next;
                if (headptr == nullptr)
                    headptr = list1;
                list1 -> next = list2;
                currptr = list1;
                list1 = nextptr;
            } else if ( val1 > val2) {
                nextptr = list2 -> next;
                if (headptr == nullptr) 
                    headptr = list2;
                list2 -> next = list1;
                currptr = list2;
                list2 = nextptr;
            } 
        }

        // if (list1) {
        //     currptr->next = list1;
        // } else {
        //     currptr->next = list2;
        // }

        return headptr;
    }
};
