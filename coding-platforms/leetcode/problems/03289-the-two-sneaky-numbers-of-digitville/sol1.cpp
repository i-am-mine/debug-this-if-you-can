#include "../header/solution_interface.h"
using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
    unordered_set<int> freq;
    vector<int> res;

    for (int &num: nums){
        if (freq.count(num)) {
            res.push_back(num);
            if (res.size() == 2) return res;
        }
        freq.insert(num);
    }

    return res;
}
