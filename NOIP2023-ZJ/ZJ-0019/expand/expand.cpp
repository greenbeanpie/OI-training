// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int c,n,m,q,a[500005],b[500005],x[500005],y[500005],mx[500005],my[500005];
void cmin(int &A,int B){A=std::min(A,B);}
void cmax(int &A,int B){A=std::max(A,B);}
bool check()
{
    // for(int i=1;i<=n;++i)
    //     std::cout<<x[i]<<" \n"[i==n];
    // for(int i=1;i<=m;++i)
    //     std::cout<<y[i]<<" \n"[i==m];
    if(1ll*(x[1]-y[1])*(x[n]-y[m])<=0)
        return false;
    if(x[n]<y[m])
    {
        for(int i=1;i<=n;++i)
            x[i]*=-1;
        for(int i=1;i<=m;++i)
            y[i]*=-1;
    }
    int ex=std::max_element(x+1,x+1+n)-x,ey=std::min_element(y+1,y+1+m)-y;
    int cx=1,cy=1,xt=1,xv=0,yt=1,yv=0;
    auto calcx=[&](int dir)
    {
        if(xt==cx)
            xv=x[xt];
        while(xt!=ex&&x[xt]<=x[cx])
            cmin(xv,x[xt+=dir]);
    };
    auto calcy=[&](int dir)
    {
        if(yt==cy)
            yv=y[yt];
        while(yt!=ey&&y[yt]>=y[cy])
            cmax(yv,y[yt+=dir]);
    };
    while(cx!=ex&&cy!=ey)
    {
        calcx(+1);
        calcy(+1);
        if(xv>y[cy])
            cx=xt;
        else if(x[cx]>yv)
            cy=yt;
        else
            return false;
    }
    while(cx!=ex)
    {
        calcx(+1);
        if(xv>y[cy])
            cx=xt;
        else
            return false;
    }
    while(cy!=ey)
    {
        calcy(+1);
        if(x[cx]>yv)
            cy=yt;
        else
            return false;
    }
    cx=n,cy=m,xt=n,yt=m;
    while(cx!=ex&&cy!=ey)
    {
        calcx(-1);
        calcy(-1);
        if(xv>y[cy])
            cx=xt;
        else if(x[cx]>yv)
            cy=yt;
        else
            return false;
    }
    while(cx!=ex)
    {
        calcx(-1);
        if(xv>y[cy])
            cx=xt;
        else
            return false;
    }
    while(cy!=ey)
    {
        calcy(-1);
        if(x[cx]>yv)
            cy=yt;
        else
            return false;
    }
    return true;
}
signed main()
{
    freopen("expand.in","r",stdin)&&freopen("expand.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin>>c>>n>>m>>q;
    for(int i=1;i<=n;++i)
        std::cin>>a[i];
    for(int i=1;i<=m;++i)
        std::cin>>b[i];
    std::copy(a+1,a+1+n,x+1);
    std::copy(b+1,b+1+m,y+1);
    std::cout<<check();
    for(int i=1,kx,ky;i<=q;++i)
    {
        std::cin>>kx>>ky;
        std::copy(a+1,a+1+n,x+1);
        std::copy(b+1,b+1+m,y+1);
        for(int j=1,px,vx;j<=kx;++j)
        {
            std::cin>>px>>vx;
            x[px]=vx;
        }
        for(int j=1,py,vy;j<=ky;++j)
        {
            std::cin>>py>>vy;
            y[py]=vy;
        }
        std::cout<<check();
    }
    std::cout<<std::endl;
    return 0;
}