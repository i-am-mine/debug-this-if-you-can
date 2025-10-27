#include "../header/solution_interface.h"
using namespace std;

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;

    string str = to_string(x);
    int left = 0, right = str.size()-1;

    while(left < right){
        if (str[left] != str[right]) return false;
        left++;
        right--;
    }

    return true;
}
