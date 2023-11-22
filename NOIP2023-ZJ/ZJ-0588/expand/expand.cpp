#include <bits/stdc++.h>
#define re register
using namespace std;
#define int long long
const int maxn=5e5+5;

int c,n,m,q;
vector<int> x(maxn),y(maxn);
vector<int> xx(maxn),yy(maxn);

int mry[2001][2001];

int dfs(int i,int j,int k)
{
    //cout<<"f "<<i<<" "<<j<<" "<<k<<" "<<endl;
    if(mry[i][j]!=-1)
    {
        return mry[i][j];
    }
    if(i>n&&j>m)
    {
        return 1;
    }
    if(i==0||j==0)
    {
        return 0;
    }
    if(i>n)
    {
        int jj=j;
        while(jj<=m)
        {
            if((xx[n]-yy[j])*k<=0)
            {
                mry[i][j]=0;
                return 0;
            }
            jj++;
        }
        mry[i][j]=1;
        return 1;
    }
    if(j>m)
    {
        int ii=i;
        while(ii<=n)
        {
            if((xx[i]-yy[m])*k<=0)
            {
                mry[i][j]=0;
                return 0;
            }
            ii++;
        }
        mry[i][j]=1;
        return 1;
    }
    if((xx[i]-yy[j])*k>0)
    {
        return dfs(i+1,j+1,k);
    }
    int ii=i,jj=j;
    while(--ii>0)
    {
        if((xx[ii]-yy[j])*k>0)
            if(dfs(ii,j,k))
            {
                mry[i][j]=1;
                return 1;
            }
            else
                break;
    }
    while(--jj>0)
    {
        if((xx[i]-yy[jj])*k>0)
            if(dfs(i,jj,k))
            {
                mry[i][j]=1;
                return 1;
            }
            else
                break;
    }
    return 0;

}

signed main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false);

    cin>>c>>n>>m>>q;
    int a,b;

    if(c==1)
    {
        for(int i=0;i<=q;i++)
        {
            cout<<1;
        }
    }
    else if(c==2)
    {
        for(int i=1;i<=n;i++)
            cin>>x[i];
        for(int i=1;i<=m;i++)
            cin>>y[i];
        if(n==1)
        {
            x[2]=x[1];
        }
        if(m==1)
        {
            y[2]=y[1];
        }
        if((x[1]-y[1])*(x[2]-y[2])>0)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        while(q--)
        {
            cin>>a>>b;
            int p,q;
            xx[1]=x[1],xx[2]=x[2],yy[1]=y[1],yy[2]=y[2];
            while(a--)
            {
                cin>>p>>q;
                if(n==1)
                {
                    xx[1]=q,xx[2]=q;
                }
                else
                {
                    xx[p]=q;
                }
            }
            while(b--)
            {
                cin>>p>>q;
                if(m==1)
                {
                    yy[1]=q,yy[2]=q;
                }
                else
                {
                    yy[p]=q;
                }
            }
            if((xx[1]-yy[1])*(xx[2]-yy[2])>0)
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
    }
    else if(c>=3&&c<=7)
    {
        memset(mry,-1,sizeof(mry));
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
            xx[i]=x[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>y[i];
            yy[i]=y[i];
        }
        if(dfs(1,1,yy[1]-xx[1]>0?-1:1))
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        while(q--)
        {
            cin>>a>>b;
            int p,q;
            for(re int i=1;i<=n;i++)
            {
                xx[i]=x[i];
            }
            for(re int j=1;j<=n;j++)
            {
                yy[j]=y[j];
            }
            while(a--)
            {
                cin>>p>>q;
                xx[p]=q;
            }
            while(b--)
            {
                cin>>p>>q;
                yy[p]=q;
            }
            if(x[1]!=xx[1]||x[n]!=xx[n]||y[1]!=yy[1]||y[m]!=yy[m])
            {
                if((xx[1]-yy[1])*(xx[2]-yy[2])<=0)
                {
                    cout<<0;
                }
                else
                {
                    if(yy[1]-xx[1]!=y[1]-x[1])
                    {
                        memset(mry,-1,sizeof(mry));
                    }
                    if(dfs(1,1,yy[1]-xx[1]>0?-1:1))
                        cout<<1;
                    else
                        cout<<0;
                }
            }
        }



    }


    return 0;
}
