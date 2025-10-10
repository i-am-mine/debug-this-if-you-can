#include "../header/solution_interface.h"
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int stu0count {0}, stu1count{0};

    for(int stu: students){
        if (stu == 0) {
            stu0count++;
        }
        else {
            stu1count++;
        }
    }

    for(int i = 0; i < sandwiches.size(); ++i){
        if (sandwiches[i] == 0 && stu0count >= 0) {
            stu0count--;
            if (stu0count == -1) {
                return sandwiches.size() - i;
            }
        }
        else if (sandwiches[i] == 1 && stu1count >= 0) {
            stu1count--;
            if (stu1count == -1) {
                return sandwiches.size() - i;
            }
        }
    }

    return 0;
}
