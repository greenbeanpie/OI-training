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
cll IO_res=IO(tribool),C=readll(),T=readll();//clear
aN f,a,vis;
ll find(cll u){
    return u!=f[u]?f[u]=find(f[u]):u;
}
void calc(cll ID){
    (void)ID;
    cll n=readll(),m=readll();
    rep(i,1,n)a[i]=i<<1,vis[i]=0;
    rep(i,1,m)switch(readchar()){
        case 'T':a[readll()]=1;break;
        case 'F':a[readll()]=0;break;
        case 'U':a[readll()]=-1;break;
        case '+':{
            cll x=readll(),y=readll();
            a[x]=a[y];
        }break;
        case '-':{
            cll x=readll(),y=readll();
            a[x]=a[y]==-1?-1:a[y]^1;
        }break;
    }
    //rep(i,1,n)writell(a[i]);
    rep(i,1,2*n+2)f[i]=i;
    rep(i,1,n){
        //if((a[i]==(i<<1|1))||(a[i]==-1))f[find(i)]=find(n+1);
        //else 
        if(a[i]==-1)f[find(i<<1)]=f[find(i<<1|1)]=find(1);
        else if(a[i]>>1)f[find(i<<1)]=find(a[i]),f[find(i<<1|1)]=find(a[i]^1);
    }
    ll cnt=0;
    rep(i,1,n)cnt+=find(i<<1)==find(i<<1|1);
    writell(cnt,10);
    return;
}
int main(){
    rep(i,1,T)calc(i);
    return 0;
}
