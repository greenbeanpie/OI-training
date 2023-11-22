#include<bits/stdc++.h>
//8:51 不敲缺省源了
//自闭了
//又忘了不定参数模板怎么写了
//然后脑子里一直循环UN彼女，但我想循环献给已逝公主的七重奏
//哎
//会T1，还行
//就先全都升序降序排一遍然后n^2枚举，求LCP比大小，哈希加二分logm即可
//随便交换不就直接排序
//9:13 总算是过了
//小丑了有点
//9:16 果然，二分上界小了1
//有点遗憾了
//会不会越界啊
//两两不同，那么正着反着分别排序之后lcp一定不为m
//唉
//不想上拍，就这样吧
//以后再来查
#define all(x) x.begin(),x.end()
#define ull unsigned long long
#define Inf (int)(INFINITY)
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define ll long long
#define pb push_back
#define endl '\n'
#define y second
#define x first
using namespace std;
const int N=3e3+10,bs[2]={44449,49999};
template<class T>
inline void read(T&ret){
    ret=0;char c=getchar();bool f=false;
    while(!isdigit(c))f=c=='-',c=getchar();
    while(isdigit(c))ret=ret*10+c-'0',c=getchar();
    if(f)ret=-ret;
}
inline void read(string&ret){
    ret.clear();char c=getchar();
    while(isspace(c))c=getchar();
    while(!isspace(c)&&c!=EOF)ret+=c,c=getchar();
}
#define cin(...) read(__VA_ARGS__)
template<class T>
inline void print(T x){
    static int st[35];int top=0,f=x<0;if(f)x=-x;
    do st[top++]=x%10;while(x/=10);if(f)putchar('-');
    while(top--)putchar(st[top]+'0');
}
int n,m;
ull ha[N][N][2][2];
string s[N],t[N];
int lcp(int i,int j,int x,int y){
    int l=0,r=m+1;
    while(l+1<r){
        int mid=(l+r)>>1,f=1;
        for(int k=0;k<2;k++)if(ha[i][mid][x][k]!=ha[j][mid][y][k])f=0;
        if(!f)r=mid;
        else l=mid;
    }
    return l;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin(n),cin(m);
    for(int i=1;i<=n;i++)cin(s[i]),t[i]=s[i],sort(all(t[i]),greater<char>()),sort(all(s[i]));
    for(int i=1;i<=n;i++){
        s[i]=' '+s[i]+' ',t[i]=' '+t[i]+' ';
        for(int j=1;j<=m;j++){
            for(int k=0;k<2;k++){
                ha[i][j][0][k]=ha[i][j-1][0][k]*bs[k]+s[i][j];
                ha[i][j][1][k]=ha[i][j-1][1][k]*bs[k]+t[i][j];               
            }
        }
    }
    // cerr<<lcp(1,2,0,0)<<endl;
    for(int i=1,flg=1;i<=n;i++,flg=1){
        for(int j=1;j<=n&&flg;j++){
            if(i==j)continue;
            int len=lcp(i,j,0,1);
            if(s[i][len+1]>t[j][len+1])flg=0;
        }
        putchar(flg+'0');
    }
    putchar(endl);
    return 0;
}
/*
cd dict
g++ dict.cpp -o test.exe -Wall -Wextra -O2 -std=c++14
./test.exe
*/
