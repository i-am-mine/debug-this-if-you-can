#include "../header/solution_interface.h"
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> map;
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    int res = 0;

    for (size_t i=0; i < s.size()-1; i++){

        if (map[s[i]] < map[s[i+1]]) res -= map[s[i]];
        else res += map[s[i]];

    }

    res += map[s[s.size()-1]];

    return res;
}
