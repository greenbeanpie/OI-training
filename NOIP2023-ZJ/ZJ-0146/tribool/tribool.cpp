#include<bits/stdc++.h>
//9:23 恰了一块士力架
//好甜啊
//饱和脂肪占一天所需的22%
//好吃！
//感觉可以搞一个n*2+3个点的扩展域并查集
//不太对
//感觉可以搞一个3-SAT
//怎么说呢
//最终值和初值相等
//最终值大概是使用“某个时刻的某个值取反k次”两个变量来表示
//感觉就是搞它个n+m+3个点
//三个点是抽象出来的TFU
//每次新增一个点，从它赋值的来源快速得知值是否确定、取反了几轮
//然后对于每个变量记录一个它最终是哪个点
//然后对于值确定的就确定了最终值
//最终值和开始时的值一样，就确定了开始值
//然后确定了的这些变量的起始点搜索一遍，又确定了一些点
//这样做若干轮
//注意到每个点只需被搜到一次
//就这样吗？
//注意到会剩下一些点确定不了一点，这部分才是关键
//注意到这个连边是树形结构
//感觉可以从一开始的n+3个点先搜一遍，把每个值的最终值都用那个什么东西表示出来
//等于是路径压缩了一下
//然后呢
//假如给每个变量的最终值记录两个值：它是从哪里来的，是否取反
//然后再连边，这次是n+3个点
//但是这次不是DAG了
//这次是外向基环树
//看成内向也行
//然后TF的整个树都能确定，U的整个树都是U
//考虑其他树
//考虑环上边权和
//如果是偶数那么无所谓，随便给环上一个点赋一个点权就能推出来整个树
//奇数那么就去世了整个树都是U，不然环上自相矛盾
//这次应该没问题了
//9:43 开冲
//10:00 怎么突然从UN彼女变成绯色月下了
//虽然本来就是二创
//唉
//基环树找环，这次别忘记弹栈了
//其实压根不用那样弹
//对了！别忘记多测不清空，保龄两行泪
//10:39 过了前三个样例，第四个好像是爆栈了
//手工开栈、
//VScode为什么不能手工开栈？？？？？？
//那个红的DEVC++上编译可以过
//感觉行
//拍？拍不了一点
//10:43 过
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
const int N=4e5+10;
template<class T>
inline void read(T&ret){
    ret=0;char c=getchar();bool f=false;
    while(!isdigit(c))f=c=='-',c=getchar();
    while(isdigit(c))ret=ret*10+c-'0',c=getchar();
    if(f)ret=-ret;
}
inline void read(char&c){
    c=getchar();while(isspace(c))c=getchar();
}
#define cin(...) read(__VA_ARGS__)
template<class T>
inline void print(T x){
    static int st[35];int top=0,f=x<0;if(f)x=-x;
    do st[top++]=x%10;while(x/=10);if(f)putchar('-');
    while(top--)putchar(st[top]+'0');
}
struct DSU{
    int fa[N],h[N];
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    void merge(int x,int y){fa[x=find(x)]=(y=find(y)),h[y]+=(x!=y?h[x]:0);}
    void clear(int n){iota(fa+1,fa+n+1,1),fill(h+1,h+n+1,1);}
}uf;
pii f[N],g[N];
vector<pii>st;
int C,T,n,m,tot,res,flg,idx[N],vis[N];
int get(char op){return op=='T'?n+1:(op=='F'?n+2:n+3);}
void up(int u){
    vis[u]=1;
    st.pb({u,g[u].y});
    if(!vis[g[u].x])up(g[u].x);
    else if(!flg){
        flg=1;
        int val=g[g[u].x].y;
        while(st.back().x!=g[u].x){
            val^=st.back().y;
            st.pop_back();
        }
        if(val)res+=uf.h[uf.find(u)];
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    for(cin(C),cin(T);T;T--,res=0){
        cin(n),cin(m),tot=n+3,uf.clear(n+3);
        for(int i=1;i<=tot;i++)vis[i]=0,idx[i]=i,f[i]={i,0};
        for(int i=1,x,y;i<=m;i++){
            char op;cin(op);
            if(!isupper(op))cin(x),cin(y),f[idx[x]=++tot]=f[idx[y]],f[idx[x]].y^=(op=='-');
            else cin(x),f[idx[x]=++tot]=f[get(op)];
        }
        for(int i=1;i<=n+3;i++)g[i]=f[idx[i]];
        for(int i=1;i<=n;i++)uf.merge(i,g[i].x);
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            if(g[i].x<=n&&uf.find(i)==i)flg=0,st.clear(),up(i);
            else if(uf.find(g[i].x)==uf.find(get('U')))res++;
        }
        print(res),putchar(endl);
    }
    return 0;
}
/*
g++ tribool.cpp -o test.exe -Wall -Wextra -O2 -Dlocal -std=c++14
./test.exe
*/
