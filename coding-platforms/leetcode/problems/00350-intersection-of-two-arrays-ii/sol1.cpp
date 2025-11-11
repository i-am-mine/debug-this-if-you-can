#include "../header/solution_interface.h"
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int, int> freqA;
    unordered_map<int, int> freqB;
    vector<int> res;

    for (int i: nums1) freqA[i]++;
    for (int i: nums2) freqB[i]++;

    for (auto num: freqA){
        num.second = min(num.second, freqB[num.first]);
        while (num.second > 0){
            res.push_back(num.first);
            num.second--;
        }
    }

    return res;
}
