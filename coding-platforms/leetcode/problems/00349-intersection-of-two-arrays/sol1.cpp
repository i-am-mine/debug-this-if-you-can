#include "../header/solution_interface.h"
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    unordered_set<int> nums(nums1.begin(), nums1.end());
    unordered_set<int> unique;
    vector<int> res;

    for(int i: nums2){
        if(nums.count(i)) unique.insert(i);
    }

    for(auto i: unique) res.push_back(i);


    return res;
}
