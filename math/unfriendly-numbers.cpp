#include <unordered_set>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

long long gcd(long long a, long long b){
    while (b != 0) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }


int unfriendlyNumbers(vector < long long int > &a, long long int k) {
    unordered_set<long long> gd;
    for(auto it: a){
        gd.insert(gcd(it, k));
    }
    set<long long> kd;
    for(long long i = 1; i <= sqrt(k); i++){
        if(k % i == 0){
            kd.insert(i);
            kd.insert(k/i);
        }
    }
    for(auto i: gd){
        for(long long l = 1; l <= sqrt(i); l++){
            if(i % l == 0){
                kd.erase(l);
                kd.erase(i/l);
            }
       }
    }
    return kd.size();
}

/* Tail starts here */
int main() {
    int res;

    int _a_size;
    long long int _k;
    cin >> _a_size>>_k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<long long int> _a;
    long long int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }

    res = unfriendlyNumbers(_a,_k);
    cout << res;

    return 0;
}
