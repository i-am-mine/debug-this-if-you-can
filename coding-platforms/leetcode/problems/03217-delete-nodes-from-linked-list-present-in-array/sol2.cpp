#include "../header/solution_interface.h"
using namespace std;

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> numSet(nums.begin(), nums.end());

    ListNode *pDel, *pPre, *pCurr;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    pPre = dummy;
    pCurr = head;

    while(pCurr){
        if (numSet.count(pCurr->val)){
            pDel = pCurr;
            pCurr = pCurr->next;
            pPre->next = pCurr;
            delete pDel;
            pDel = nullptr;
        }
        else {
            pPre = pCurr;
            pCurr = pCurr->next;
        }
    }

    ListNode *newHead = dummy->next;
    delete dummy;

    return newHead;
}
