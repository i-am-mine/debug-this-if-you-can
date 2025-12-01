#include "../header/solution_interface.h"
using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;

    if (head->val == head->next->val) {
        head->next = deleteDuplicates(head->next);
    }
    else deleteDuplicates(head->next);

    return head;
}
