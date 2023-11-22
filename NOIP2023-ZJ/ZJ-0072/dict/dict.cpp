#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define f(i,a,b) for(int i=(a);i<=(b);i++)
ll rd(){
    ll x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){
        if(c=='-')f=-1;
        c=getchar();
    }while(isdigit(c)){
        x=x*10+c-'0';
        c=getchar();
    }return x*f;
}
#define d rd()
ll n,m;
char c1[3030][3030];//正
char c2[3030][3030];//逆
char mn[3030],imn[3030];
ll id,iid;

int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=d,m=d;f(i,1,n){
        cin>>c1[i]+1;
        sort(c1[i]+1,c1[i]+m+1);
        f(j,1,m)c2[i][j]=c1[i][m-j+1];
    }
    f(i,1,m)mn[i]=c2[1][i];id=1;
    f(i,2,n){
        bool fl=0;
        f(j,1,m)if(c2[i][j]!=mn[j]){fl=(c2[i][j]<mn[j]);break;}
        if(fl){
            f(j,1,m)imn[j]=mn[j],mn[j]=c2[i][j];
            iid=id,id=i;
        }else{
            if(!iid){iid=i;f(j,1,m)imn[j]=c2[i][j];}
            else{
                f(j,1,m)if(c2[i][j]!=imn[j]){fl=(c2[i][j]<imn[j]);break;}
                if(fl){iid=i;f(j,1,m)imn[j]=c2[i][j];}
            }
        }
    }f(i,1,n){
        if(i!=id){
            bool fl=0;
            f(j,1,m)if(c1[i][j]!=mn[j]){fl=(c1[i][j]<mn[j]);break;}
            if(fl)putchar('1');else putchar('0');
        }else{
            bool fl=0;
            f(j,1,m)if(c1[i][j]!=imn[j]){fl=(c1[i][j]<imn[j]);break;}
            if(fl)putchar('1');else putchar('0');
        }
    }
    return 0;
}