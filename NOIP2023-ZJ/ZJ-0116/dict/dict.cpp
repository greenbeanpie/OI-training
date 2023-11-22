#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull T=13331;
const int LUOGU_UID=234641;

int n,m;

struct StringHash{
    char ch[3001];
    ull hash[3001];

    inline void read(){
        for(int i=1;i<=m;i++)
            scanf(" %c",ch+i);
    }

    inline StringHash reverse(){
        StringHash ret;
        for(int i=1;i<=m;i++)
            ret.ch[i]=ch[m-i+1];
        return ret;
    }

    inline void sort(){
        std::sort(ch+1,ch+1+m,[&](char x,char y){
            return x<y;
        });
    }

    inline void initHash(){
        hash[0]=0;
        for(int i=1;i<=m;i++)
            hash[i]=hash[i-1]*T+ch[i];
    }

    inline bool operator<(StringHash &x)const{
        int l=0,r=m;
        while(l<r){
            int mid=l+r+1>>1;
            if(hash[mid]==x.hash[mid])l=mid;
            else r=mid-1;
        }
        return l<m&&(ch[l+1]<x.ch[l+1]);
    }
}s1[3001],s2[3001];

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        s1[i].read();
        s1[i].sort();
        s2[i]=s1[i].reverse();
        s1[i].initHash();
        s2[i].initHash();
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n&&flag;j++)
            if(i!=j&&!(s1[i]<s2[j]))flag=false;
        printf("%d",flag);
    }
    // fprintf(stderr,"%lf\n",clock()*1.0/CLOCKS_PER_SEC);
    return 0;
}