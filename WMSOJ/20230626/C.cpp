#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> e[100010];
signed main()
{
    #ifdef CODESPACE
        freopen("C.in","r",stdin);
    #endif
    #ifndef CODESPACE
        freopen("tree.in","r",stdin);
        freopen("tree.out","w",stdout);
    #endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    int u,v;
    for(int i=1;i<n;i++){
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int sum=0;
    for(int start=1;start<=n;start++){
        queue<int> q;
        int dis[n+5];
        bool vis[100005]={0};
        dis[start]=0;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            for(auto i:e[now]){
                if(!vis[i]){
                    vis[i]=1;
                    dis[i]=dis[now]+1;
                    q.push(i);
                }
            }
        }
        for(int i=start;i<=n;i++){
            sum+=dis[i]/k+dis[i]%k;
        }
    }
    cout << sum;
	return 0;
}