#include<bits/stdc++.h>
//f[i][j]表示现在在i，连续打卡j天的最大能量
//然后转移就是f[i][0]=max f[i-1][j]
//f[i][j]=f[i-1][j-1]+w(i,j)
//w(i,j)可以前缀和二分求
//12:47 多少垫好了这一档
//
#define all(x) x.begin(),x.end()
#define Inf (int)(INFINITY)
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define int long long
#define ll long long
#define pb push_back
#define endl '\n'
#define y second
#define x first
using namespace std;
const int N=5e3+10;
template<class T>
inline void read(T&ret){
    ret=0;char c=getchar();bool f=false;
    while(!isdigit(c))f=c=='-',c=getchar();
    while(isdigit(c))ret=ret*10+c-'0',c=getchar();
    if(f)ret=-ret;
}
#define cin(...) read(__VA_ARGS__)
template<class T>
inline void print(T x){
    static int st[35];int top=0,f=x<0;if(f)x=-x;
    do st[top++]=x%10;while(x/=10);if(f)putchar('-');
    while(top--)putchar(st[top]+'0');
}
int C,T,n,m,k,d,res,f[N][N];
vector<pii>gt[N];
int calc(int i,int j){
    auto it=upper_bound(all(gt[i]),make_pair(j,Inf));
    if(it==gt[i].begin())return 0;
    // cerr<<i<<" "<<j<<" "<<prev(it)->y<<endl;
    return prev(it)->y;
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    for(cin(C),cin(T);T;T--,res=-Inf){
        cin(n),cin(m),cin(k),cin(d);
        for(int i=1;i<=n;i++)gt[i].clear();
        for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)f[i][j]=-inf;
        for(int i=1,l,r,v;i<=m;i++)cin(r),cin(l),cin(v),gt[r].pb({l,v});
        for(int i=1;i<=n;i++){sort(all(gt[i]));int sum=0;for(pii&p:gt[i])sum+=p.y,p.y=sum;}
        f[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++)f[i][0]=max(f[i][0],f[i-1][j]);
            for(int j=1;j<=k;j++)f[i][j]=f[i-1][j-1]-d+calc(i,j);
        }
        for(int j=0;j<=k;j++)res=max(res,f[n][j]);
        print(res),putchar(endl);
    }
    return 0;
}
/*
g++ run.cpp -o test.exe -Wall -Wextra -O2 -std=c++14
./test.exe
*/

