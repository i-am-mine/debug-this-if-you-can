#include "../header/solution_interface.h"
using namespace std;

int strStr(string haystack, string needle) {
    int h = haystack.size(), n = needle.size();
    if (h < n) return -1;
    else if (h == n) {
        if (haystack == needle) return 0;
        else return -1;
    }
    else if (n == 1) {
        int pos = haystack.find(needle[0]);
        if (pos != string::npos) return pos;
        else return -1;
    }

    int left{0};
    while (left < h) {
        if (haystack[left] == needle[0] && left+n <= h) {
            if (haystack.compare(left+1, n-1, needle, 1, n-1) == 0) return left;
        }

        left++;
    }

    return -1;
}
