/* O( n^(1/2) ) solution */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string isPrime(int n){
    bool prime = true;
    if(n == 2)
        return "Prime";
    if(n % 2 == 0 || n == 1)
        return "Not prime";    
    for(int i = 3; i <= sqrt(n); i += 2){
        if(n % i == 0){
            prime = false;
            break;
        }
    }
    return prime ? "Prime" : "Not prime";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;      
        cout << isPrime(n) << endl;
    }
    return 0;
}

