#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int n = 100000000;   // size of the array
    const int k = 6000000;     // rotation amount
    ofstream fout("arrays_100M.txt");

    if (!fout) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Write original array
    fout << "Original array:\n";
    for (int i = 1; i <= n; i++) {
        fout << i;
        if (i != n) fout << ",";
    }
    fout << "\n\n";

    // Write rotated array
    fout << "Rotated array (k=" << k << "):\n";
    for (int i = n - k + 1; i <= n; i++) {
        fout << i << ",";
    }
    for (int i = 1; i <= n - k; i++) {
        fout << i;
        if (i != n - k) fout << ",";
    }
    fout << "\n";

    fout.close();
    cout << "arrays_100M.txt generated successfully!" << endl;
    return 0;
}
