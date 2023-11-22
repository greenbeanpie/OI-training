#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 100010;
int type[MAX_N*2];
bool vis[MAX_N];
struct Ques {
    char type;
    int xi,xj;
};
vector<Ques> ques;
//Union Find Set
int par[MAX_N*2];
void init()
{
    memset(type,0,sizeof(type));
    memset(vis,0,sizeof(vis));
    ques.clear();
    for(int i=0; i<(MAX_N<<1); i++) {
        par[i]=i;
    }
}
int findpar(int x)
{
    return par[x]==x?x:par[x]=findpar(par[x]);
}
void unite(int x, int y)
{
    x=findpar(x);
    y=findpar(y);
    if(x!=y) {
        par[x]=y;
    }
}
void divide(int x, int y)
{
    if(findpar(x)==findpar(y)) {
        par[x]=x;
        par[y]=y;
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--) {
        init();
        if(c==3||c==4) {
            int n,m;
            cin >> n >> m;
            for(int i=1; i<=m; i++) {
                char v;
                int x;
                cin >> v >> x;
                if(v=='T') {
                    type[x]=1;
                } else if(v=='F') {
                    type[x]=2;
                } else {
                    type[x]=3;
                }
            }
            int cnt=0;
            for(int i=1; i<=n; i++) {
                if(type[i]==3) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        } else if(c==5||c==6) {
            int n,m;
            cin >> n >> m;
            for(int i=1; i<=m; i++) {
                char v;
                cin >> v;
                int xi,xj;
                if(v=='U') {
                    cin >> xi;
                    ques.push_back({'U',xi,0});
                } else {
                    cin >> xi >> xj;
                    ques.push_back({'+',xi,xj});
                }
            }
            for(int i=m-1; i>=0; i--) {
                if(!vis[ques[i].xi]) {
                    if(ques[i].type=='U') {
                        type[findpar(ques[i].xi)]=3;
                    } else if(ques[i].type=='+') {
                        type[findpar(ques[i].xi)]=type[findpar(ques[i].xj)];
                        unite(ques[i].xi,ques[i].xj);
                    }
                    vis[ques[i].xi]=true;
                }
            }
            int cnt=0;
            for(int i=1; i<=n; i++) {
                if(type[findpar(i)]==3) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        } else if(c==7||c==8) {
            int n,m;
            cin >> n >> m;
            for(int i=1; i<=m; i++) {
                char v;
                int xi,xj;
                cin >> v >> xi >> xj;
                ques.push_back({v,xi,xj});
            }
            for(int i=m-1; i>=0; i--) {
                int xi=ques[i].xi;
                int xj=ques[i].xj;
                if(!vis[xi]) {
                    if(ques[i].type=='+') {
                        unite(xi,xj);
                        unite(xi+n,xj+n);
                    } else if(ques[i].type=='-') {
                        unite(xi,xj+n);
                        unite(xi+n,xj);
                    }
                    vis[xi]=true;
                }
            }
            int cnt=0;
            for(int i=1; i<=n; i++) {
                if(findpar(i)==findpar(i+n)) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
