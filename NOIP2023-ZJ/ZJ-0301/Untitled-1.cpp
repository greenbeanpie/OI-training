#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline int read() {
    int x=0;char c=getchar();bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x; return x;
}
// const int maxn=
vector<int> ll;
int main()
{
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    For(i,1,5) ll.push_back(i);
    cout<<upper_bound(ll.begin(),ll.end(),10)-ll.begin()-1<<endl;
    return 0;
}
/*
g++ /.cpp -O2 -Wall -o .exe
./.exe
*/