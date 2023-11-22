#include <bits/stdc++.h>
typedef unsigned uint;
typedef long long llt;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return a<b?(a=b,true):false;}
template<typename T>bol _min(T&a,T b){return b<a?(a=b,true):false;}
uint Id[200005];bol M[200005];
std::vector<uint>Way[200005];
voi insert(uint u,uint v)
{
    Way[u].push_back(v),Way[v].push_back(u);
    Way[u^1].push_back(v^1),Way[v^1].push_back(u^1);
}
voi solve()
{
    uint n,m;scanf("%u%u",&n,&m);
    for(uint i=0;i<n;i++)Id[i]=i<<1;
    while(m--)
    {
        static chr C[5];uint p,q;scanf("%s%u",C,&p),p--;
        if(*C=='U')Id[p]=n*2+2;
        else if(*C=='T')Id[p]=n*2+1;
        else if(*C=='F')Id[p]=n*2;
        else scanf("%u",&q),Id[p]=Id[q-1]^(*C=='-');
    }
    for(uint i=0;i<n*2+4;i++)Way[i].clear();
    insert(n*2+2,n*2+3);
    for(uint i=0;i<n;i++)insert(i<<1,Id[i]);
    for(uint i=0;i<n*2+4;i++)Id[i]=i,M[i]=false;
    for(uint i=0;i<n*2+4;i++)if(Id[i]==i)
    {
        std::vector<uint>Q{i};
        while(Q.size())
        {
            uint p=Q.back();Q.pop_back();
            for(auto s:Way[p])if(_min(Id[s],i))Q.push_back(s);
        }
    }
    // for(uint i=0;i<n*2+4;i++)printf("%u%c",Id[i]," \n"[i==n*2+2]);
    for(uint i=0;i<n+2;i++)if(Id[i<<1]==Id[i<<1|1])M[Id[i<<1]]=true;
    uint ans=0;
    for(uint i=0;i<n;i++)ans+=M[Id[i<<1]];
    printf("%u\n",ans);
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
#endif
    uint t;scanf("%*u%u",&t);
    while(t--)solve();
    return 0;
}

/*

g++ tribool.cpp -o tribool -std=c++11 -Wall -fsanitize=undefined,address -DMYEE

*/
