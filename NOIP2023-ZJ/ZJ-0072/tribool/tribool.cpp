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
ll fa[200010];
ll find(ll x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
void un(ll u,ll v){fa[find(u)]=find(v);}
struct node{ll tp,x;};
ll n,m;
node a[200010];
//0:F 1:T 2:U 3:x 4:!x
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ll TT=d;TT=d;while(TT--){
        n=d,m=d;
        ll F=2*n+1,T=2*n+2,U=2*n+3;
        f(i,1,2*n+3)fa[i]=i;
        f(i,1,n)a[i]={3,i};
        while(m--){
            char c;cin>>c;
            if(c=='+'){
                ll x=d,y=d;
                if(a[y].tp==0)a[x]={0,-1};
                else if(a[y].tp==1)a[x]={1,-1};
                else if(a[y].tp==2)a[x]={2,-1};
                else if(a[y].tp==3)a[x]={3,a[y].x};
                else if(a[y].tp==4)a[x]={4,a[y].x};

            }else if(c=='-'){
                ll x=d,y=d;
                if(a[y].tp==0)a[x]={1,-1};
                else if(a[y].tp==1)a[x]={0,-1};
                else if(a[y].tp==2)a[x]={2,-1};
                else if(a[y].tp==3)a[x]={4,a[y].x};
                else if(a[y].tp==4)a[x]={3,a[y].x};
            }else{
                ll x=d;
                if(c=='F')a[x]={0,-1};
                else if(c=='T')a[x]={1,-1};
                else if(c=='U')a[x]={2,-1};
            }
        }f(i,1,n){
            if(a[i].tp==0)un(i,F),un(i+n,T);
            else if(a[i].tp==1)un(i,T),un(i+n,F);
            else if(a[i].tp==2)un(i,i+n),un(i,U),un(i+n,U);
            else if(a[i].tp==3)un(i,a[i].x),un(i+n,a[i].x+n);
            else if(a[i].tp==4)un(i,a[i].x+n),un(i+n,a[i].x);
            // cout<<a[i].tp<<" "<<a[i].x<<endl;
            // if(i==885)cout<<a[i].tp<<" "<<a[i].x<<endl;
        }ll res=0;f(i,1,n){
            if(find(i)==find(i+n)||find(i)==find(U))res++;//,cout<<i<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}