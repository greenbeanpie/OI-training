#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Task{
    ll l,r;
    ll v;
    bool operator<(const Task& rhs) const{
        return l<rhs.l;
    }
};
vector<Task> tasks;
void init()
{
    tasks.clear();
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,t;
    cin >> c >> t;
    ll n,m,k,d;
    while(t--) {
        init();
        cin >> n >> m >> k >> d;
        for(int i=1; i<=m; i++) {
            ll x,y,v;
            cin >> x >> y >> v;
            tasks.push_back({x-y+1,x,v});
        }
        sort(tasks.begin(),tasks.end());
        ll ans=0;
        ll maxR=0;
        for(auto it:tasks) {
            maxR=max(maxR,it.l);
            if(it.v-(it.r-maxR+1)*d>0) {
                ans+=it.v-(it.r-maxR+1)*d;
                maxR=max(maxR,it.r);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
