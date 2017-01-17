#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    bool answer = false;
    for(int i = 0; i < n; i++){
        cin >> s;
        answer = next_permutation(s.begin(), s.end());
        s = answer ? s : "no answer";
        cout << s << endl;
    }
    return 0;
}
