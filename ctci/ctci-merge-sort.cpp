#include <vector>
#include <iostream>

using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b, long long &inv){
    int n = a.size();
    int m =  b.size();
    vector<int> ans(n + m);
    int ai = 0, bi = 0, i = 0;
    while(ai < n && bi < m){
        if(a[ai] > b[bi]){
            inv += n - i + bi;
            ans[i++] = b[bi++];
        }
        else
            ans[i++] = a[ai++];
    }
    while(ai < n){
        ans[i++] = a[ai++];
    }
    while(bi < m){
        ans[i++] = b[bi++];
    }
    return ans;
}

vector<int> merge_sort(vector<int> &arr, int start, int fin, long long &inv){
    if(start >= fin)
        return { arr[start] };
    int middle = (fin + start) / 2;
    vector<int> left = merge_sort(arr, start, middle, inv);
    vector<int> right = merge_sort(arr, middle + 1, fin, inv);
    return merge(left, right, inv);
}

long long count_inversions(vector<int> &arr) {
    long long inv = 0;
    vector<int> a = merge_sort(arr, 0, arr.size() - 1, inv);
    return inv;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        cout << count_inversions(arr) << endl;
    }
    return 0;
}
