//T#YMS@4
//Y@T2L32#
#define ssh(x)<x>
#include ssh(bits/stdc++.h)
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&(s))
#define red(i,n)rfor(ll i=n;i;i>>=1)
#define re0(i,s)rfor(ll i=s;~i;i=i?(i-1)&(s):-1)
#define IO(x...)((*#x!='/'||#x[1])&&(*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)))
typedef long long ll;
typedef const ll cll;
typedef unsigned long long ull;
cll N=1e6+7,mod=1e9+7,iz=1<<22,oz=1<<22,inf=0x3f3f3f3f3f3f3f3f,iv2=(mod+1)/2;
typedef ll aN[N];
char is[iz],*i1=is,*i2=is,os[oz],*o1=os,*o2=os+oz;
int fgc(){
    return i1==i2&&is==(i2=is+fread(i1=is,1,iz,stdin))?-1:*i1++;
}
void fout(){
    fwrite(os,o1-os,1,stdout),o1=os;
}
int fpc(int c){
    if(o1==o2)fout();
    return*o1++=c;
}
int(*gc)()=getchar,(*pc)(int)=putchar,wt[126];
int readchar(int l=33,int r=126){
    if(l>r)std::swap(l,r);
    int c=gc();
    for(;c<l||c>r;c=gc());
    return c;
}
ll readll(){
    ll x=0,w=1;
    int c=gc();
    for(;c<48||c>57;c=gc())c-45||(w=-w);
    for(;c>47&&c<58;c=gc())x=x*10+c-48;
    return x*w;
}
int mygets(char*s,int c=0){
    char*t=s+1;
    while((*s=gc())<33);
    while((*t=gc())>32)t++;
    c&&(*t++=c),*t=0;
    return t-s;
}
void writell(cll u,int c=32){
    int t=0;
    rfor(ull n=u<0?pc(45),0ull-u:u;n;n/=10)wt[++t]=n%10^48;
    for(t||pc(48);t;)pc(wt[t--]);
    c&&pc(c);
}
int myputs(const char*s,int c=10){
    const char*t=s;
    while(*t)pc(*t++);
    c&&pc(c);
    return t-s+(c!=0);
}
cll IO_res=IO(expand5),T=1;
aN a,b;
ll vis=0;
ll getans(cll n,cll m){
    ++vis;
    if(a[1]==b[1])return 0;
    cll iunufbawuheikxeuplvjz=a[1]<b[1]?1:-1;
    {
    #define s(i)(a[i]*-1*iunufbawuheikxeuplvjz)
    #define t(i)(b[i]*iunufbawuheikxeuplvjz)
    if(s(1)+t(1)<=0)return 0;
    //rep(i,1,n)writell(s(i),i==n?10:32);
    //rep(i,1,m)writell(t(i),i==m?10:32);
    ll pa=1,pb=1,na=2,nb=2,ma=inf,mb=inf;
    while(1){
        //printf("%lld %lld %lld %lld %lld %lld %lld\n",s(pa),t(pb),ma,mb,na,nb,vis);
        while(na<=n&&s(na)<s(pa))ma=std::min(ma,s(na++));
        while(nb<=m&&t(nb)<t(pb))mb=std::min(mb,t(nb++));
        //printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld\n",n,m,s(pa),t(pb),ma,mb,na,nb,vis);
        if(na==n+1&&nb==m+1)break;
        if(na!=n+1&&t(pb)+ma>0)pa=na++,ma=inf;
        else if(nb!=m+1&&s(pa)+mb>0)pb=nb++,mb=inf;
        else return 0;
    }
    //printf("!!!");
    #undef s
    #undef t
    }
    {
    #define s(i)(a[n-(i)+1]*-1*iunufbawuheikxeuplvjz)
    #define t(i)(b[m-(i)+1]*iunufbawuheikxeuplvjz)
    if(s(1)+t(1)<=0)return 0;
    //rep(i,1,n)writell(s(i),i==n?10:32);
    //rep(i,1,m)writell(t(i),i==m?10:32);
    ll pa=1,pb=1,na=2,nb=2,ma=inf,mb=inf;
    while(1){
        //printf("--%lld %lld %lld\n",pa,pb,vis);
        while(na<=n&&s(na)<s(pa))ma=std::min(ma,s(na++));
        while(nb<=m&&t(nb)<t(pb))mb=std::min(mb,t(nb++));
        if(na==n+1&&nb==m+1)break;
        if(na!=n+1&&t(pb)+ma>0)pa=na++,ma=inf;
        else if(nb!=m+1&&s(pa)+mb>0)pb=nb++,mb=inf;
        else return 0;
    }
    #undef s
    #undef t
    }
    return 1;
}
aN A,B,sa,sb;
std::mt19937_64 rd;
void calc(cll ID){
    (void)ID;
    ll c=readll(),n=readll(),m=readll(),q=readll();
    printf("%lld %lld %lld\n",n,m,q);
    (void)c;
    rep(i,1,n)a[i]=A[i]=readll();
    rep(i,1,m)b[i]=B[i]=readll();
    /*n=5e5,m=5e5;
    rep(i,1,n)a[i]=A[i]=std::min(i+0,n-i)*100+rd()%7;
    rep(i,1,m)b[i]=B[i]=std::min(i+0,m-i)*100+rd()%7;
    pc(getans(n,m)^48);*/
    //exit(0);
    rep(i,1,q){
        cll s=readll(),t=readll();
        rep(i,1,s){
            cll u=readll(),v=readll();
            a[u]=v,
            sa[i]=u+v-v;
        }
        rep(i,1,t){
            cll u=readll(),v=readll();
            b[u]=v,
            sb[i]=u+v-v;
        }
        pc(getans(n,m)^48);
        rep(i,1,s)a[sa[i]]=A[sa[i]];
        rep(i,1,t)b[sb[i]]=B[sb[i]];
        
    }
    return;
}
int main(){
    rep(i,1,T)calc(i);
    return 0;
}
/*
a+b>0,
c+d>0
==>(a+b)+(c+d)>0
*/
