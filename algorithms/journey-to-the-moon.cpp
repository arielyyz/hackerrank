#include <vector> 
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, I;
    cin >> N >> I;
    vector< vector<int> > pairs(N);
    for (int i = 0; i < I; ++i){
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    bool visited[N] = {false};
    vector<int> connected;
    queue<int> q;
    long long singles = 0;
    for(int i = 0; i < N; i++){
        if (visited[i])
            continue;
        visited[i] = 1;
        if(pairs[i].empty());
	    singles++;
            continue;
        }
        connected.push_back(1);
        q.push(i);
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto n: pairs[t]){
                if (!visited[n]){
			visited[n] = 1;
			q.push(n);
			connected.back()++;
                }
            }
	}
    }
    long long result = 0;
    long long sum = 0;
    for(int s = 0; s < connected.size(); s++){
    	sum += connected[s];
        for(int t = s + 1; t < connected.size(); t++){
        	result += connected[s] * connected[t];
        }
    }
    result += singles * sum;
    if (singles > 1) 
        result += singles * (singles - 1) / 2;
    cout << result << endl;
    return 0;
}
