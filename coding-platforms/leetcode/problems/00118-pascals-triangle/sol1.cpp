#include "../header/solution_interface.h"
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    int line{1};

    while (line <= numRows){

        if (line == 1) ans.push_back({1});
        else if (line == 2) ans.push_back({1,1});
        else if (line > 2){
            vector<int> row;
            row.push_back(1);
            for(int i = 1; i < line-1; i++){
                row.push_back( ans[line-2][i-1] + ans[line-2][i] );
            }
            row.push_back(1);
            ans.push_back(row);
        }

        line++;
    }
    return ans;
}
