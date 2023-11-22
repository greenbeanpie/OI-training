// const string tsh="forever friends"
// rp++;
// return "退役";
// g++ -Wall -O2 -std=c++14 tribool.cpp -o tribool_exec
// ./tribool_exec

#include<bits/stdc++.h>
using namespace std;
#define il inline
#define fo(_var,_a,_b) for(int _var=_a;_var<=_b;_var++)
#define fr(_var,_a,_b) for(int _var=_a;_var>=_b;_var--)
#define foo(_var,_a,_b,_c) for(int _var=_a;_var<=_b;_var+=_c)
#define frr(_var,_a,_b,_c) for(int _var=_a;_var>=_b;_var-=_c)

int val[100010];
int fnl[11];
int C,T;
int n,m;
int ans;
int a1[11];
struct node0
{
    char op;
    int u,v;
}ops[11];

void init1()
{
    ans=0;
    fo(i,1,n)
    {
        val[i]=1;
    }
    return ;
}
void solve1()
{
    while(m--)
    {
        char op;
        cin>>op;
        if(op=='U')
        {
            int u;
            cin>>u;
            val[u]=0;
        }
        else if(op=='F')
        {
            int u;
            cin>>u;
            val[u]=-1;
        }
        else if(op=='T')
        {
            int u;
            cin>>u;
            val[u]=1;
        }
    }
    fo(i,1,n)
    {
        if(val[i]==0)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return ;
}

void init0()
{
    ans=114514;
    return ;
}
void dfs(int dep)
{
    if(dep==n+1)
    {
        int cnt=0,flag=1;
        fo(i,1,n)
        {
            fnl[i]=val[i];
        }
        fo(i,1,m)
        {
            if(ops[i].op=='+')
            {
                fnl[ops[i].u]=fnl[ops[i].v];
            }
            else if(ops[i].op=='-')
            {
                fnl[ops[i].u]=-fnl[ops[i].v];
            }
            else if(ops[i].op=='U')
            {
                fnl[ops[i].u]=0;
            }
            else if(ops[i].op=='F')
            {
                fnl[ops[i].u]=-1;
            }
            else if(ops[i].op=='T')
            {
                fnl[ops[i].u]=1;
            }
        }
        fo(i,1,n)
        {
            if(fnl[i]==0)
            {
                cnt++;
            }
            if(fnl[i]!=val[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            // fo(i,1,n)
            // {
            //     cout<<val[i]<<' ';
            // }cout<<endl;
            ans=min(ans,cnt);
        }
        return ;
    }
    fo(i,-1,1)
    {
        val[dep]=i;
        dfs(dep+1);
    }
    return ;
}
void solve0()
{
    fo(i,1,m)
    {
        cin>>ops[i].op;
        if(ops[i].op=='+')
        {
            cin>>ops[i].u>>ops[i].v;
        }
        else if(ops[i].op=='-')
        {
            cin>>ops[i].u>>ops[i].v;
        }
        else if(ops[i].op=='U')
        {
            cin>>ops[i].u;
        }
        else if(ops[i].op=='F')
        {
            cin>>ops[i].u;
        }
        else if(ops[i].op=='T')
        {
            cin>>ops[i].u;
        }
    }
    dfs(1);
    printf("%d\n",ans);
    return ;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(C==1||C==2)
        {
            init0();
            solve0();
        }
        if(C==3||C==4)
        {
            init1();
            solve1();
        }
    }
    // 多测要清空、要换行
    return 0;
}
