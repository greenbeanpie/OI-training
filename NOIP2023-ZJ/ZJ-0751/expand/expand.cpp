#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 5e5+10;

int X[N],Y[N],c,n,m,q;

inline void read(int &x)
{
    x = 0;int f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
    while(isdigit(c)){x = (x<<1)+(x<<3)+(c^48);c = getchar();}
    x*=f;
}

bool op(int a,int b,int c,int d)
{
    if(max(a,b)<min(c,d) || max(c,d)<min(a,b))
        return true;
    else if((min(a,b)-min(c,d))*(max(a,b)-max(c,d))>0)
        return true;
    else return false;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    read(c);read(n);read(m);read(q);
    for(int i=1;i<=n;i++) read(X[i]);
    for(int j=1;j<=m;j++) read(Y[j]);
    if(n == 1 && m == 1)
    {
        printf("1");
        while(q--)
        {
            int kx,ky,p,v;
            read(kx);read(ky);
            while(kx--)
            {
                read(p);read(v);
                X[p] = v;
            }
            while(ky--)
            {
                read(p);read(v);
                Y[p] = v;
            }
            printf("1");
        }
    }
    else if(n == 2 && m == 2)
    {
        int a = X[1],b = X[2],c = Y[1],d = Y[2];
        if(op(a,b,c,d)) printf("1");
        else printf("0");
        while(q--)
        {
            int kx,ky,p,v;
            read(kx);read(ky);
            while(kx--)
            {
                read(p);read(v);
                X[p] = v;
            }
            while(ky--)
            {
                read(p);read(v);
                Y[p] = v;
            }
            int a = X[1],b = X[2],c = Y[1],d = Y[2];
            if(op(a,b,c,d)) printf("1");
            else printf("0");
        }
    }
    else if(n == 2 && m == 1)
    {
        int a = X[1],b = X[2],c = Y[1];
        if(c<min(a,b) || c>max(a,b)) printf("1");
        else printf("0");
        while(q--)
        {
            int kx,ky,p,v;
            read(kx);read(ky);
            while(kx--)
            {
                read(p);read(v);
                X[p] = v;
            }
            while(ky--)
            {
                read(p);read(v);
                Y[p] = v;
            }
            int a = X[1],b = X[2],c = Y[1];
            if(c<min(a,b) || c>max(a,b)) printf("1");
            else printf("0");
        }
    }
    else if(m == 2 && n == 1)
    {
        int c = Y[1],a = X[2],b = X[1];
        if(c<min(a,b) || c>max(a,b)) printf("1");
        else printf("0");
        while(q--)
        {
            int kx,ky,p,v;
            read(kx);read(ky);
            while(kx--)
            {
                read(p);read(v);
                X[p] = v;
            }
            while(ky--)
            {
                read(p);read(v);
                Y[p] = v;
            }
            int c = Y[1],a = X[2],b = X[1];
            if(c<min(a,b) || c>max(a,b)) printf("1");
            else printf("0");
        }
    }
    return 0;
}
