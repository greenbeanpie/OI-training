// const string tsh="forever friends"
// rp++;
// return "退役";

#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fo(_var,_a,_b) for(int _var=_a;_var<=_b;_var++)
#define fr(_var,_a,_b) for(int _var=_a;_var>=_b;_var--)
#define foo(_var,_a,_b,_c) for(int _var=_a;_var<=_b;_var+=_c)
#define frr(_var,_a,_b,_c) for(int _var=_a;_var>=_b;_var-=_c)

int C,T;
int n,m,k,d;
struct node
{
    int x,y,v,c;
}a[100010];

void init()
[
    return ;
]

void solve()
{
    scanf("%d%d%d%d",&n,&m,&k,&d);
    init();
    int p=1;
    fo(i,1,m)
    {
        int x,y,v,c;
        scanf("%d%d%d",&x,&y,&v);
        c=y*d;
        if(y>k||c>=v)
        {
            continue;
        }
        a[p].x=x;
        a[p].y=y;
        a[p].v=v;
        a[p].c=c;
        p++;
    }
    m=p;
    fo(i,1,n)
    {
        fo(j,1,m)
        {
            dp[i][j]=dp[i][j-1];
            fo(K,0,k-a[j].y)
            {
                dp[i][j]=max(dp[i][j][a[j].y],dp[i][j][a[j].y+K])
            }
        }
    }
    
    return ;
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--)
    {
        solve();
    }
    

    // 多测要清空、要换行
    return 0;
}
