#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int C,T,m,n;
char c;
int p,q;
vector<int> dat(maxn);
vector<int> rrr(11);
int minn=0x3f3f3f3f;

struct opr
{
    int op,a,b;
}ttt[maxn];

bool cmp(opr a,opr b)
{
    return a.op<b.op;
}

int ctoi(char ch)
{
    switch(ch)
    {
    case 'T':
        return 1;
    case 'F':
        return 2;
    case 'U':
        return 0;
    }
}

inline void dfs(int i)
{
    if(i==n+1)
    {
        for(int ii=1;ii<=n;ii++)
        {
            rrr[ii]=dat[ii];
        }
        for(int ii=1;ii<=m;ii++)
        {
            if(ttt[ii].op=='+')
            {
                rrr[ttt[ii].a]=rrr[ttt[ii].b];
            }
            else if(ttt[ii].op=='-')
            {
                if(!rrr[ttt[ii].b])
                    rrr[ttt[ii].a]=0;
                else
                    rrr[ttt[ii].a]=3-rrr[ttt[ii].b];
            }
            else
            {
                rrr[ttt[ii].a]=ttt[ii].op;
            }
        }
        int cnt=0;
        for(int ii=1;ii<=n;ii++)
        {
            if(rrr[ii]!=dat[ii])
                return;
            if(!dat[ii]) cnt++;
        }
        if(cnt<minn)
            minn=cnt;
        return;
    }
    for(int k=0;k<3;k++)
    {
        dat[i]=k;
        dfs(i+1);
    }
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);

    cin>>C>>T;

    if(C==4||C==3)
    {
        while(T--)
        {
            fill(dat.begin(),dat.begin()+n+2,3);
            cin>>n>>m;
            while(m--)
            {
                cin>>c>>p;
                dat[p]=ctoi(c);
            }
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(!dat[i]) cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    else if(C==1||C==2)
    {
        while(T--)
        {
            minn=0x3f3f3f3f;
            cin>>n>>m;

            for(int i=1;i<=m;i++)
            {
                cin>>c>>p;
                if(c=='+'||c=='-')
                {
                    ttt[i].op=c;
                    cin>>q;
                    ttt[i].a=p;
                    ttt[i].b=q;
                }
                else    ttt[i].op=ctoi(c),ttt[i].a=p;
            }
            dfs(1);
            cout<<minn<<endl;
        }

    }

    else if(C==5||C==6)
    {
        while(T--)
        {
            minn=0x3f3f3f3f;
            fill(dat.begin(),dat.begin()+n+2,3);
            cin>>n>>m;

            for(int i=1;i<=m;i++)
            {
                cin>>c>>p;
                if(c=='+')
                {
                    ttt[i].op=9;
                    cin>>q;
                    ttt[i].a=p;
                    ttt[i].b=q;
                }
                else    ttt[i].op=0,ttt[i].a=p;
            }

            sort(ttt+1,ttt+m+1,cmp);

            int i=1;
            for(;i<=m;i++)
            {
                if(ttt[i].op)   break;
                dat[ttt[i].a]=0;
            }
            for(;i<=m;i++)
            {
                if(dat[ttt[i].a]==0)
                {
                    dat[ttt[i].b]=0;
                }
                else if(dat[ttt[i].b])
                {
                    dat[ttt[i].a]=3;
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(!dat[i]) cnt++;
            }
            cout<<cnt<<endl;
        }
    }


    return 0;
}
