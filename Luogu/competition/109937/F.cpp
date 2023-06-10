#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> paper[2005];
bool emp[2005];
bool cmp(vector<int> a,vector<int> b){
    return a.size()<b.size();
}
signed main(){
    #ifndef ONLINE_JUDGE
        freopen("F.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        
        int a;
        cin >> a;
        paper[i].push_back(i);
        if(a==0){
            
            int t;
            cin >> t;
            if(t==-1){
                continue;
            }
            emp[t]=true;
            paper[i].push_back(t);
            continue;
        }
        
        for(int j=0;j<max(1ll,a);j++){
            int t;
            cin >> t;
            paper[i].push_back(t);
        }
    }
    int head[2005]={0},start=1;
    
    for(int i=1;i<=n;i++){
        if(!head[i]){
            head[i]=i;
            for(int j:paper[i]){
                head[j]=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!emp[head[i]]){
            start=*paper[head[i]].begin();
        }
    }
    auto a=paper[start].begin();
    int now=start;
    while(now>0){
        cout << *a << " ";
        if(a!=--paper[now].end()){
            a++;
        }
        else{
            now=*(++paper[*--paper[now].end()].begin());
            a=paper[now].begin();
        }
    }
    return 0;
}