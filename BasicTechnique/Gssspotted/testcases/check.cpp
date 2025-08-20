#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 1; i <= 10; ++i) {
        string filename = "BasicTechnique/Gssspotted/testcases/"+to_string(i)+".in";
        ifstream fin(filename);
        if (!fin) {
            cerr << "Cannot open " << filename << endl;
            continue;
        }
        int h_count = 0, t_count = 0;
        int n;
        fin >> n;
        string line;
        fin >> line;
        for(char c:line) c=='H' ? h_count++ : t_count++;
        fin.close();
        cout << n << "| " << ": H=" << h_count << " T=" << t_count << endl;
    }
    return 0;
}