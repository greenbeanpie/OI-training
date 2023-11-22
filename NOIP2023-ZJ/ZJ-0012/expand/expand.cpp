#include <bits/stdc++.h>
typedef unsigned uint;
typedef long long llt;typedef unsigned long long ullt;
typedef bool bol;typedef char chr;typedef void voi;
typedef double dbl;
template<typename T>bol _max(T&a,T b){return a<b?(a=b,true):false;}
template<typename T>bol _min(T&a,T b){return b<a?(a=b,true):false;}
bol solve(uint*X,uint*Y,uint n,uint m)
{
    static uint PreMax[500005],PreMin[500005],SufMax[500005],SufMin[500005];
    static bol Ok[500005];
    for(uint i=0;i<n;i++)PreMax[i]=PreMin[i]=SufMax[i]=SufMin[i]=i;
    for(uint i=1;i<n;i++)
    {
        if(X[PreMax[i-1]]>X[i])PreMax[i]=PreMax[i-1];
        if(X[PreMin[i-1]]<X[i])PreMin[i]=PreMin[i-1];
    }
    for(uint i=n-1;i;i--)
    {
        if(X[SufMax[i]]>X[i-1])SufMax[i-1]=SufMax[i];
        if(X[SufMin[i]]<X[i-1])SufMin[i-1]=SufMin[i];
    }
    std::vector<uint>Left{SufMax[0]},Right{SufMax[0]};
    while(Left.back())Left.push_back((Left.size()&1?PreMin:PreMax)[Left.back()-1]);
    while(Right.back()<n-1)Right.push_back((Right.size()&1?SufMin:SufMax)[Right.back()+1]);
    for(auto&x:Left)x=X[x];
    for(auto&x:Right)x=X[x];
    // puts("");
    // for(uint i=0;i<n;i++)printf("%u%c",X[i]," \n"[i==n-1]);
    // for(uint i=0;i<m;i++)printf("%u%c",Y[i]," \n"[i==m-1]);
    // puts("");
    for(uint i=0;i<m;i++)Ok[i]=false;
    for(uint i=0;i<m;i++)
    {
        if(Left.back()>=Y[i])break;
        while(Left.size()>2&&Left[Left.size()-2]<Y[i])Left.pop_back();
        Ok[i]=Y[i]>Left[0];
    }
    for(uint i=m-1;~i;i--)
    {
        if(Right.back()>=Y[i])break;
        while(Right.size()>2&&Right[Right.size()-2]<Y[i])Right.pop_back();
        if(Y[i]>Right[0]&&Ok[i])return true;
    }
    return false;
}
int main()
{
#ifdef MYEE
    freopen("QAQ.in","r",stdin);
    freopen("QAQ.out","w",stdout);
#else
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
#endif
    static uint X[500005],Y[500005],BaseX[500005],BaseY[500005],n,m,q,x,y;
    scanf("%*u%u%u%u",&n,&m,&q);
    for(uint i=0;i<n;i++)scanf("%u",BaseX+i);
    for(uint i=0;i<m;i++)scanf("%u",BaseY+i);
    for(uint i=0;i<n;i++)X[i]=BaseX[i];
    for(uint i=0;i<m;i++)Y[i]=BaseY[i];
    x=*std::max_element(X,X+n),y=*std::max_element(Y,Y+m);
    putchar("01"[x!=y&&(x<y?solve(X,Y,n,m):solve(Y,X,m,n))]);
    while(q--)
    {
        for(uint i=0;i<n;i++)X[i]=BaseX[i];
        for(uint i=0;i<m;i++)Y[i]=BaseY[i];
        uint a,b;scanf("%u%u",&a,&b);
        while(a--){uint p,v;scanf("%u%u",&p,&v),X[p-1]=v;}
        while(b--){uint p,v;scanf("%u%u",&p,&v),Y[p-1]=v;}
        x=*std::max_element(X,X+n),y=*std::max_element(Y,Y+m);
        putchar("01"[x!=y&&(x<y?solve(X,Y,n,m):solve(Y,X,m,n))]);
    }
    putchar('\n');
    return 0;
}

/*

g++ expand.cpp -o expand -std=c++11 -Wall -fsanitize=undefined,address -DMYEE

*/
