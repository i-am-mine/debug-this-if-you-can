#include "../header/solution_interface.h"
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> res;
    res.reserve(n);

    int i = 1;
    while(i <= n){
        if (i % 15 == 0) res.push_back("FizzBuzz");
        else if (i % 3 == 0) res.push_back("Fizz");
        else if (i % 5 == 0) res.push_back("Buzz");
        else res.push_back(to_string(i));

        i++;
    }

    return res;
}
