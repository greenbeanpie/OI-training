#include <bits/stdc++.h>
#define int long long
#define L(i,j,k) for(int (i)=(j);(i)<=(k);(i)++)
#define R(i,j,k) for(int (i)=(j);(i)>=(k);(i)--)
#define dg if(false)
using namespace std;
void bl(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<int>a(n+10),b(m+10);
  L(i,1,n){
    cin>>a[i];
  }
  L(i,1,m){
    cin>>b[i];
  }
  b[m+1]=1e18;
  a[n+1]=1e18;
  auto aa=a;
  auto bb=b;
  auto sol=[&]()->void{
    if(
      (a[1]==b[1])||(a[n]==b[m])||
      ((a[1]<b[1])&&(a[n]>b[m]))||
      ((a[1]>b[1])&&(a[n]<b[m]))
    ){
      cout<<0;
      return ;
    }
    vector<int>c(n+m+1,0);
    if(a[1]>b[1]){
      int ri=1;
      c[1]=1;
      L(i,2,m+1){
        if(a[1]<=b[i]){
          ri=i-1;
          break;
        }
        c[i]=1;
      }
      L(i,2,n){
        int lst=-1;
        L(j,1,m+1){
          if(b[j]<a[i]){

          }
          else{
            lst=j-1;
            if(!c[j]){

              break;
            }
          }
        }
        if(lst==-1){
          cout<<0;
          return ;
        }
        if(lst>ri){
          L(j,ri,lst){
            c[j]=1;
          }
          ri=lst;
        }
        else{
          L(j,lst+1,ri){
            c[j]=0;
          }
          ri=lst;
        }
      }
      cout<<(ri>=m);
    }
    else{
      int ri=1;
      c[1]=1;
      L(i,2,n+1){
        if(b[1]<=a[i]){
          ri=i-1;
          break;
        }
        c[i]=1;
      }
      L(i,2,m){
        int lst=-1;
        L(j,1,n+1){
          if(a[j]<b[i]){

          }
          else{
            if(!c[j]){
              lst=j-1;
              break;
            }

          }
        }
        if(lst==-1){
          cout<<0;
          return ;
        }
        if(lst>ri){
          L(j,ri,lst){
            c[j]=1;
          }
          ri=lst;
        }
        else{
          L(j,lst+1,ri){
            c[j]=0;
          }
          ri=lst;
        }
      }
      cout<<(ri>=n);
    }
  };
  sol();
  L(i,1,q){
    int k1,k2;
    cin>>k1>>k2;
    L(j,1,k1){
      int x,y;
      cin>>x>>y;
      a[x]=y;
    }
    L(j,1,k2){
      int x,y;
      cin>>x>>y;
      b[x]=y;
    }
    sol();
    a=aa;
    b=bb;
  }
}
signed main(){
  freopen("expand.in","r",stdin);
  freopen("expand.out","w",stdout);

  ios::sync_with_stdio(false);
  cin.tie(nullptr);

#define lc ((p)<<1)
#define rc ((p)<<1|1)
  struct ST{
    vector<int>a;
    struct tree{
      int l,r,z,mi;
    };
    vector<tree>s;
    void pp(int p){
      s[p].z=max(s[lc].z,s[rc].z);
      s[p].mi=min(s[lc].mi,s[rc].mi);
    }
    void build(int p,int l,int r){
      s[p].l=l;s[p].r=r;
      s[p].mi=1e18;
      s[p].z=-1e18;
      if(l==r){
        s[p].z=a[l];
        s[p].mi=a[l];
        return ;
      }
      int mid=(l+r)>>1;
      build(lc,l,mid);
      build(rc,mid+1,r);
      pp(p);
    }
    void chg(int p,int x,int k){
      if(s[p].l==s[p].r){
        s[p].z=k;
        s[p].mi=k;
        return ;
      }
      int mid=(s[p].l+s[p].r)>>1;
      if(x<=mid){
        chg(lc,x,k);
      }
      else{
        chg(rc,x,k);
      }
      pp(p);
    }
    int ask(int p,int l,int r){
      if(s[p].l>=l&&s[p].r<=r){
        return s[p].z;
      }
      int mid=(s[p].l+s[p].r)>>1;
      int v=-1e18;
      if(l<=mid){
        v=max(v,ask(lc,l,r));
      }
      if(r>mid){
        v=max(v,ask(rc,l,r));
      }
      return v;
    }
    int askk(int p,int l,int r){
      if(s[p].l>=l&&s[p].r<=r){
        return s[p].z;
      }
      int mid=(s[p].l+s[p].r)>>1;
      int v=1e18;
      if(l<=mid){
        v=min(v,ask(lc,l,r));
      }
      if(r>mid){
        v=min(v,ask(rc,l,r));
      }
      return v;
    }
  }s1,s2;
  int C,n,m,q;
  cin>>C;
  if(C<=7){
    bl();
    return 0;
  }
  cin>>n>>m>>q;
  vector<bool>ans;
  vector<int>a(n+1),b(m+1);
  int len=max(n,m);
  vector<int>c(len+5,0);
  L(i,1,n){
    cin>>a[i];
  }
  L(i,1,m){
    cin>>b[i];
  }
  auto aa=a;
  auto bb=b;

  s1.a=a;
  s2.a=b;
  s1.s.resize(4*n+10);
  s2.s.resize(4*m+10);
  s1.build(1,1,n);
  s2.build(1,1,m);

  auto work=[&]()->void{
    if(
      (a[1]==b[1])||(a[n]==b[m])||
      ((a[1]<b[1])&&(a[n]>b[m]))||
      ((a[1]>b[1])&&(a[n]<b[m]))
    ){
      cout<<0;
      dg{
        cout<<"zuichu"<<'\n';
      }
      return ;
    }
    if(a[1]>b[1]){//asb
      L(i,1,n){//
        int idl,idr;
        if(a[i]<=s2.askk(1,1,n)){
          cout<<0;
          dg{
            cout<<"quanmei"<<'\n';
          }
          return ;
        }
        int l=1,r=n,mid;
        while(l<=r){
          mid=(l+r)>>1;
          if(s2.askk(1,1,mid)>=a[i]){
            l=mid+1;
          }
          else{
            r=mid-1;
            idl=mid;
          }
        }
        if(a[i]>s2.ask(1,idl,n)){
          idr=n;
          cout<<1;
          dg{
            cout<<"quanyou"<<'\n';
          }
          return ;
        }
        l=idl,r=n;
        while(l<=r){
          mid=(l+r)>>1;
          if(s2.ask(1,idl,mid)<a[i]){
            l=mid+1;
          }
          else{
            r=mid-1;
            idr=mid;
          }
        }
        dg{
          cout<<i<<' '<<idl<<' '<<idr<<'\n';
        }
        c[idl]++;
        c[idr+1]--;
      }
      int sum=0;
      L(k,1,n){
        sum+=c[k];
        if(sum==0){
          cout<<0;
          return ;
        }
      }
      cout<<1;
      return ;
    }
    else{
      L(i,1,m){//
        int idl,idr;
        if(b[i]<=s1.askk(1,1,m)){
          cout<<0;
          dg{
            cout<<"quanmei b"<<'\n';
          }
          return ;
        }
        int l=1,r=m,mid;
        while(l<=r){
          mid=(l+r)>>1;
          if(s1.askk(1,1,mid)>=b[i]){
            l=mid+1;
          }
          else{
            r=mid-1;
            idl=mid;
          }
        }
        if(a[i]>s1.ask(1,idl,m)){
          idr=m;
          cout<<1;
          dg{
            cout<<"quanyou b"<<'\n';
          }
          return ;
        }
        l=idl,r=m;
        while(l<=r){
          mid=(l+r)>>1;
          if(s2.ask(1,idl,mid)<b[i]){
            l=mid+1;
          }
          else{
            r=mid-1;
            idr=mid;
          }
        }
        dg{
          cout<<i<<' '<<idl<<' '<<idr<<'\n';
        }
        c[idl]++;
        c[idr+1]--;
      }
      int sum=0;
      L(k,1,n){
        sum+=c[k];
        if(sum==0){
          cout<<0;
          return ;
        }
      }
      cout<<1;
      return ;
    }
  };
  dg{
    L(j,1,n){
      cout<<a[j]<<" \n"[j==n];
    }
    L(j,1,m){
      cout<<b[j]<<" \n"[j==m];
    }
  }
  work();
  L(i,1,q){
    int k1,k2;
    cin>>k1>>k2;
    fill(c.begin(), c.end(),0);
    L(j,1,k1){
      int x,y;
      cin>>x>>y;
      s1.chg(1,x,y);
      a[x]=y;
    }
    L(j,1,k2){
      int x,y;
      cin>>x>>y;
      s2.chg(1,x,y);
      b[x]=y;
    }
    dg{
      L(j,1,n){
        cout<<a[j]<<" \n"[j==n];
      }
      L(j,1,m){
        cout<<b[j]<<" \n"[j==m];
      }
    }
    work();
    a=aa;
    b=bb;
  }


  /*
  if(
    (a[1]==b[1])||(a[n]==b[m])||
    ((a[1]<b[1])&&(a[n]>b[m]))||
    ((a[1]>b[1])&&(a[n]<b[m]))
  ){
    dead;
  }
  */
  return 0;
}
//0001100000010000000000000011000000000000000011000000000000000
//1101100011110101110101111111111111111110011111111101101100000
