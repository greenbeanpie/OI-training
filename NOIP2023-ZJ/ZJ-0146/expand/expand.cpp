#include<bits/stdc++.h>
//10:46 犹豫要不要现在恰第二块士力架
//馋了，但是不饿
//考虑这个题
//注意到这个相当于序列中每个连续段都能任意伸长
//然后要求一个序列每个元素严格大于/小于另一个序列每个元素
//10:54 浅恰了一口
//“为了避免你扔硬币蒙混过关”
//唉
//注意到相对顺序不会改变
//10:58 又恰了一口
//感觉有点横扫饥饿做回自己了
//修改？感觉每次修改都硬跑问题也不大
//并且修改这么多感觉也不是能轻松转移的那种
//大概只是多测减少读入压力
//然后考虑这个东西
//11:07 又恰了一口
//现在脑内播放世界如此可爱
//为什么同样是灵梦主题曲，少女绮想曲就那么有名呢
//11:11 又恰了一口
//注意到不管怎么扩展第一个元素和最后一个元素都是确定的
//所以如果第一个元素是第一行大那么都得是第一行大，其他很多以此类推
//11:13 又恰了一口
//11:15 又恰了一口，恰完了
//今天推荐摄入的饱和脂肪的44%！
//假设现在钦定第一行大，第二行要小
//容易发现扩展就全扩展第二行最小的那个一定不劣
//不劣吗？
//11:19 两盘初级扫雷，一盘27s一盘28s
//之前都只要10s左右的
//说明脑子不太清醒
//先等一会先
//11:21 现在考虑刚才得知最后一个元素的大小关系也是确定的
//如果和第一个冲突了那就直接输出0了
//如果没冲突就可以硬扩展两个序列的最后一个后面肯定都是对的
//然后考虑前面
//直觉感觉第二个序列完全不需要扩展别的更加方便
//直觉感觉刚刚的直觉是错的
//感觉可以两个指针扫过去
//如果符合就都下一个
//不符合就第一个序列之前的某一段扩展，把现在这个往后推，
//往后推一定可行吗？
//11:27 现在脑内播放诸神眷恋的幻想乡
//怎么回事呢。
//考虑把前面的最大值往后推
//感觉这个东西很难刻画
//注意到我可以扩展第二个序列
//那么只要找到一个比它小的就全都行了
//那么就是双指针扫，每次尝试把最近的一个比它小的值推过来
//10^100等于是无穷大的长度
//感觉还是要要结合起来用
//11:41 感觉时间有点紧
//单调栈维护一个前缀大一个前缀小？
//难受
//11:51 现在脑内播放感情的摩天楼
//设需要大的序列是a，另一个是b
//注意到如果对于一个位置，之前a伸长了p，b伸长了q，相当于一个没动另一个伸长了|p-q|
//从前往后扫的话容易出现伸长上下都行就难以判断
//然后考虑到什么
//麻了，不写了，垫T4暴力
#define all(x) x.begin(),x.end()
#define Inf (int)(INFINITY)
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define ll long long
#define pb push_back
#define endl '\n'
#define y second
#define x first
using namespace std;
const int N=1e6+10;
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
vector<int>p,q;
int c,n,m,Q,aa[N],bb[N],a[N],b[N];
void work(int*a,int n,int*b,int m){
    int mx1=0,mn1=inf,mx2=0,mn2=inf;
    for(int i=1;i<=n;i++){mx1=max(mx1,a[i]),mn1=min(mn1,a[i]);}
    for(int j=1;j<=m;j++){mx2=max(mx2,b[j]),mn2=min(mn2,b[j]);}  
    if(mn1<=mn2||mx1<=mx2)putchar('0');  
    else putchar('1');
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin(c),cin(n),cin(m),cin(Q);
    for(int i=1;i<=n;i++)cin(a[i]),aa[i]=a[i];
    for(int j=1;j<=m;j++)cin(b[j]),bb[j]=b[j];
    if(aa[1]==bb[1]||aa[n]==bb[m])putchar('0');
    else if((aa[1]<bb[1])^(aa[n]<bb[m]))putchar('0');
    else if(aa[1]>bb[1])work(aa,n,bb,m);
    else work(bb,m,aa,n);    
    for(int k1,k2;Q;Q--){
        cin(k1),cin(k2),p.clear(),q.clear();
        for(int i,v;k1;k1--)cin(i),cin(v),aa[i]=v,p.pb(i);
        for(int j,v;k2;k2--)cin(j),cin(v),bb[j]=v,q.pb(j);
        if(aa[1]==bb[1]||aa[n]==bb[m])putchar('0');
        else if((aa[1]<bb[1])^(aa[n]<bb[m]))putchar('0');
        else if(aa[1]>bb[1])work(aa,n,bb,m);
        else work(bb,m,aa,n);
        for(int i:p)aa[i]=a[i];
        for(int j:q)bb[j]=b[j];
    }
    putchar(endl);
    return 0;
}
/*
g++ expand.cpp -o test.exe -Wall -Wextra -O2 -std=c++14
./test.exe
*/

