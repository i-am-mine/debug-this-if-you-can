#include "../header/solution_interface.h"
using namespace std;

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    vector<pair<char, string>> res;
    res.reserve(isActive.size());

    unordered_set<string> cat = {"electronics", "grocery", "pharmacy", "restaurant"};

    for(size_t i = 0; i < isActive.size(); ++i){
        if (!isActive[i]) continue;
        if (!cat.contains(businessLine[i])) continue;

        const string & s = code[i];
        if(!s.empty() && all_of(s.begin(), s.end(), [](char c) {
            return (c >= 'a' && c <= 'z') ||
                   (c >= 'A' && c <= 'Z') ||
                   (c >= '0' && c <= '9') ||
                   (c == '_');
        })) {
            res.push_back({businessLine[i][0], s});
        }
    }

    sort(res.begin(), res.end());

    vector<string> resStr;
    resStr.reserve(res.size());
    for(auto &p: res){
        resStr.push_back(move(p.second));
    }

    return resStr;
}
