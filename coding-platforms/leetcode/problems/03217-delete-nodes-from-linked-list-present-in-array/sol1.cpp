#include "../header/solution_interface.h"
using namespace std;

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> numSet(nums.begin(), nums.end());

    ListNode *pDel, *pPre, *pCurr;

    while(head && numSet.count(head->val)){
        pDel = head;
        head = head->next;
        delete pDel;
        pDel = nullptr;
    }

    if (!head) return nullptr;

    pPre = head;
    pCurr = head->next;
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

    return head;
}
