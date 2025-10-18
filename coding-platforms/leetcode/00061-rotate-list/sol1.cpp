#include "../header/solution_interface.h"
using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if (k == 0) return head;
    if (!head || !head->next) return head;

    int nNodes{0};
    ListNode* preHead = head;
    while(preHead->next){
        nNodes++;
        preHead = preHead->next;
    }
    nNodes++;

    k %= nNodes;
    if (k == 0) return head;
    preHead->next = head;

    int steps = nNodes - k;
    while (steps > 0){
        preHead = head;
        head = head->next;
        steps--;
    }
    preHead->next = nullptr;


    return head;
}
