#include<bits/stdc++.h>
using namespace std;
int a[100005];
int pf[15];//
int pf2[15];
int pfrd[105];
int pfrdv[105];
int changev(char v){
    if(v=='U')return -3;
    if(v=='F')return -2;
    if(v=='T')return -1;
}
int nt(int abcdefg){
    if(abcdefg==-1)return -2;
    if(abcdefg==-2)return -1;
    if(abcdefg==-3)return -3;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,m,ans=0;
        cin>>n>>m;
        for(int iiii=0;iiii<=100004;iiii++){
            a[iiii]=0;
        }
        if(c==1||c==2){
            for(int i=1;i<=14;i++){
                pf[i]=0;
                pf2[i]=0;
            }
            int rdtop=0,rdvtop=0;
            for(int i=1;i<=m;i++){
                    char v;
                    cin>>v;
                    //cout<<v<<"   wow!"<<endl;
                    pfrdv[rdvtop++]=v;
                    if(v=='+'){
                        int aa,bb;
                        cin>>aa>>bb;
                        pfrd[rdtop++]=aa;
                        pfrd[rdtop++]=bb;
                    }else if(v=='-'){
                        int aa,bb;
                        cin>>aa>>bb;
                        pfrd[rdtop++]=aa;
                        pfrd[rdtop++]=bb;
                    }else{
                        int cc;
                        cin>>cc;
                        pfrd[rdtop++]=cc;
                    }
            }

            ans=114514;
            for(int pianfen2=0;pianfen2<pow(3,n);pianfen2++){
                int i22=1;
                //dbug(pianfen2);
                int pianfen=pianfen2;
                while(i22<=n){
                    pf[i22]=pianfen%3-3;
                    //cout<<"oh...    "<<pf[i22]<<endl;
                    pf2[i22]=pianfen%3-3;
                    pianfen/=3;
                    i22++;
                }
                //dbug(i22-1,pianfen2);
                int dtop=0,dvtop=0;
                for(int i=1;i<=m;i++){
                    /*cout<<endl;
                    for(int i=1;i<i22;i++){
                    cout <<pf[i]<<" ";
                    }
                    cout<<"--------------"<<endl;
                    cout<<endl;*/


                    char v;
                    v=pfrdv[dvtop++];
                    if(v=='+'){
                        int aa,bb;
                        //cin>>aa>>bb;
                        aa=pfrd[dtop++];
                        bb=pfrd[dtop++];
                        //cout<<aa<<" "<<bb<<endl;
                        pf[aa]=pf[bb];
                    }else if(v=='-'){
                        int aa,bb;
                        //cin>>aa>>bb;
                        aa=pfrd[dtop++];
                        bb=pfrd[dtop++];
                        //cout<<aa<<" "<<bb<<endl;
                        pf[aa]=nt(pf[bb]);
                    }else{
                        int cc;
                        //cin>>cc;
                        cc=pfrd[dtop++];
                        //cout<<cc<<" "<<v<<endl;
                        pf[cc]=changev(v);
                    }
                }
                bool flgg=1;
                for(int i=1;i<i22;i++){
                    if(pf[i]!=pf2[i]){
                        flgg=0;
                        break;
                    }
                }
                //for(int i=1;i<i22;i++){
                //    cout <<pf[i]<<" ";
                //}
                //cout<<"  jntm2233"<<endl;
                if(flgg){
                    int wans=0;
                    /*for(int i=1;i<i22;i++){
                    cout <<pf[i]<<" ";
                    }
                    cout<<"  jntm"<<endl;*/
                    for(int i=1;i<i22;i++){
                        if(pf[i]==changev('U'))wans++;
                    }
                    ans=min(ans,wans);
                }
            }
            cout<<ans<<endl;
        }else if(c==3||c==4){
            for(int i=1;i<=m;i++){
                char v;
                int ii;
                cin>>v>>ii;
                a[ii]=changev(v);
            }
            for(int i=1;i<=n;i++){
                if(a[i]==changev('U'))ans++;
            }
            cout<<ans<<endl;
        }else if(c==5||c==6){
            for(int i=1;i<=n;i++){
                a[i]=i;
            }
            for(int i=1;i<=m;i++){
                char v;
                cin>>v;
                if(v=='+'){
                    int aa,bb;
                    cin>>aa>>bb;
                    a[aa]=a[bb];
                }else{
                    int ii;
                    cin>>ii;
                    a[ii]=-3;
                }
            }
            int ans=0;
            for(int i=1;i<=m;i++){
                int wfl=a[i];
                int bief=0;
                while(wfl!=-3&&wfl!=i){
                    wfl=a[wfl];
                    bief++;
                    if(bief>=1024)break;
                }
                if(wfl==-3)ans++;
            }
            cout<<ans<<endl;
        }else{
            cout<<n<<endl;
        }
    }
    return 0;
}

