#include "../header/solution_interface.h"
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res = nullptr, *ptr1 = l1, *ptr2 = l2;
    int sum = 0;

    while (ptr1 || ptr2){

        if (ptr1) sum += ptr1->val;

        if (ptr2) sum += ptr2->val;

        if (ptr1){
            ptr1->val = sum % 10;
            ptr1 = ptr1->next;
            res = l1;
        }

        if (ptr2){
            ptr2->val = sum % 10;
            ptr2 = ptr2->next;
            res = l2;
        }

        sum /= 10;
    }

    if (sum > 0) {
        if (!res->next) res->next = new ListNode(sum);
        else{
            ptr1 = res->next;
            while (ptr1->next != nullptr) ptr1 = ptr1->next;
            ptr1->next = new ListNode(sum);
        }

    }


    return res;
}
