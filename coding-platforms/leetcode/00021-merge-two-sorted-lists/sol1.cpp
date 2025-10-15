#include "../header/solution_interface.h"
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    ListNode *head {nullptr}, *tail {nullptr};

    if (list1->val < list2->val) {
        head = tail = list1;
        list1 = list1->next;
    }
    else {
        head = tail = list2;
        list2 = list2->next;
    }

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) tail->next = list1;
    else tail->next = list2;

    return head;
}
