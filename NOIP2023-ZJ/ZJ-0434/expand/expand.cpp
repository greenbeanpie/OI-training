#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    if(c<=2){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
    }

    if(c==1){

    if(a[1]!=b[1])cout<<1;
    else cout<<0;

       while(q--){
            int aa[5],bb[5];
            aa[1]=a[1];
            aa[2]=a[2];
            bb[1]=b[1];
            bb[2]=b[2];
           int kx,ky;
           cin>>kx>>ky;
           while(kx>0){
            int px,vx;
            cin>>px>>vx;
            aa[px]=vx;
            kx--;
           }
           while(ky>0){
            int px,vx;
            cin>>px>>vx;
            bb[px]=vx;
            ky--;
           }

           if(aa[1]!=bb[1])cout<<1;
           else cout<<0;
       }
    }else if(c==2){
    if(a[1]>b[1]&&a[2]>b[2])cout<<1;
    else if(a[1]<b[1]&&a[2]<b[2])cout<<1;
    else cout<<0;

       while(q--){
            int aa[5],bb[5];
            aa[1]=a[1];
            aa[2]=a[2];
            bb[1]=b[1];
            bb[2]=b[2];
           int kx,ky;
           cin>>kx>>ky;
           while(kx>0){
            int px,vx;
            cin>>px>>vx;
            aa[px]=vx;
            kx--;
           }
           while(ky>0){
            int px,vx;
            cin>>px>>vx;
            bb[px]=vx;
            ky--;
           }

           if(aa[1]>bb[1]&&aa[2]>bb[2])cout<<1;
    else if(aa[1]<bb[1]&&aa[2]<bb[2])cout<<1;
    else cout<<0;
       }
    }
    return 0;
}
