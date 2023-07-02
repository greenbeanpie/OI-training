#include <bits/stdc++.h>
using namespace std;
//#define int long long

struct node{
    int x,y,dis;
};
bool operator<(node a,node b){
    return a.dis<b.dis;
}
int wk[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    bool mp[n + 1][n + 1];
    char c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == '1')
            {
                mp[i][j] = 1;
            }
            else
            {
                mp[i][j] = 0;
            }
        }
    }
    priority_queue<node> pq;
    vector<pair<int,int> > liantong[2500];
    bool vis[n+1][n+1];
    int tot=0;
    int startlt,endlt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]){
                continue;
            }
            queue<pair<int,int> > q;
            q.push({i,j});
            liantong[++tot].push_back({0,0});
            liantong[tot].push_back({i,j});
            while(q.size()){
                auto now=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int tx=now.first+wk[i][0];
                    int ty=now.second+wk[i][1];
                    if(tx>0&&tx<=n&&ty>0&&ty<=n){
                        q.push({tx,ty});
                        liantong[tot].push_back({tx,ty});
                    }
                }
                if(now.first==sx&&now.second==sy){
                    startlt=tot;
                }
                if(now.first==ex&&now.second==ey){
                    endlt=tot;
                }
            }
        }
    }
    int min_dis[tot+1][tot+1];
    memset(min_dis,0x3f3f3f,sizeof(min_dis));
    for(int i=1;i<tot;i++){
        for(int j=i+1;j<=tot;j++){
            for(auto start:liantong[i]){
                for(auto end:liantong[j]){
                    min_dis[i][j]=min(min_dis[i][j],(int)pow(abs(start.first-end.first),2)+(int)pow(abs(start.second-end.second),2));
                }
            }
            min_dis[j][i]=min_dis[i][j];
        }
    }
    for(int i=1;i<tot;i++){
        for(int j=i;j<=tot;j++){
            for(int k=1;k<=tot;k++){
                min_dis[i][j]=min(min_dis[i][j],min_dis[i][k]+min_dis[k][j]);
            }
        }
    }
    cout << min_dis[startlt][endlt];
    return 0;
}