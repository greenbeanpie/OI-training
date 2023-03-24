#include <bits/stdc++.h>
using namespace std;

pair<int,int> t[(long long)10e6+5];
int maxinum=-1;

int dfs(int cur,int depth){
    if(t[cur].first==0){
        maxinum=max(maxinum,depth+1);
    }
    else{
        maxinum=dfs(t[cur].first,depth+1);
    }
    if(t[cur].second==0){
        maxinum=max(maxinum,depth+1);
    }
    else{
        maxinum=dfs(t[cur].second,depth+1);
    }
    return maxinum;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("P4913.in","r",stdin);
    #endif
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t[i+1].first >> t[i+1].second;
    }
    cout << dfs(1,0);
    return 0;
}