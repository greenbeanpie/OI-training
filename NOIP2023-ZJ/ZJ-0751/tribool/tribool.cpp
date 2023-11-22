#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int c,t,n,m,k,d,ans;

int now_day,now_tj;

struct Node
{
    int x,y,v;
}tj[N];

bool cmp(Node a,Node b)
{
    if(a.x == b.x) return a.v;
    return a.x<b.x;
}

inline void read(int &x)
{
    x = 0;int f = 1;char c = getchar();
    while(!isdigit(c)){if(c == '-')f = -1;c = getchar();}
    while(isdigit(c)){x = (x<<1)+(x<<3)+(c^48);c = getchar();}
    x*=f;
}

int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);

    return 0;
}
