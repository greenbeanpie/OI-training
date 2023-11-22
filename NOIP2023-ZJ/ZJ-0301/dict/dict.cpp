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
const int maxn=3030;
int n,m;
struct Node{
    string s;
    int id;
    bool flag;
}a[maxn*2];
string str;
bool ans[maxn];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    For(i,1,n)
    {
        cin>>str;
        sort(str.begin(),str.end());
        a[i].s=str;
        a[i].id=i;
        a[i].flag=false;
        reverse(str.begin(),str.end());
        a[i+n].s=str;
        a[i+n].id=i;
        a[i+n].flag=true;
    }
    sort(a+1,a+n*2+1,[&](Node x,Node y){
        if(x.s!=y.s) return x.s<y.s;
        return x.flag<y.flag;
    });
    For(i,1,n*2)
    {
        if(a[i].flag) break;
        ans[a[i].id]=true;
    }
    For(i,1,n) putchar(ans[i]?'1':'0');
    cout<<'\n';
    return 0;
}
/*
g++ dict/dict.cpp -O2 -Wall -o dict/dict.exe
dict/dict.exe
*/