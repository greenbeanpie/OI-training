#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("P1135.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
    int n,start,end;
    cin >> n >> start >> end;
    int k[n+1];
    for(int i=1;i<=n;i++){
        cin >> k[i];
    }
    int t[n+1];
    memset(t,-1,sizeof(t));
    t[start]=0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(now+k[now]<=n&&(t[now+k[now]]>t[now]+1||t[now+k[now]]==-1)){
            t[now+k[now]]=t[now]+1;
            q.push(now+k[now]);
        }
        if(now-k[now]>=0&&(t[now-k[now]]>t[now]+1||t[now-k[now]]==-1)){
            t[now-k[now]]=t[now]+1;
            q.push(now-k[now]);
        }
    }
    cout << t[end];
	return 0;
}