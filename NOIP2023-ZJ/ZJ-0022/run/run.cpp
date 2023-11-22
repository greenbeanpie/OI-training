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
cll IO_res=IO(run),C=readll(),T=readll();
struct node{
    ll l,r,c;
    void read(){
        cll x=readll(),y=readll(),v=readll();
        l=x-y+1,r=x,c=v;
    }
    operator ll()const{
        return r;
    }
}p[N];
aN x;
ll tx;
struct sgt{
    typedef ll aN[3*N];
    aN f;
    ll n,n_;
    void pushup(cll i){
        cll t=std::max(f[i<<1],f[i<<1|1]);
        f[i<<1]-=t,f[i<<1|1]-=t,f[i]+=t;
    }
    void update(ll l,ll r,cll c){
        for(l+=n-1,r+=n+1;l^r^1;pushup(l>>=1),pushup(r>>=1))~l&1&&(f[l^1]+=c),r&1&&(f[r^1]+=c);
        red(i,l>>1)pushup(i);
        //rep(i,1,n_)printf("%lld ",query(i,i));puts("");
    }
    ll query(ll l,ll r)const{
        ll resl=-inf,resr=-inf;
        for(l+=n-1,r+=n+1;l^r^1;resl+=f[l>>=1],resr+=f[r>>=1])
        ~l&1&&(resl=std::max(resl,f[l^1])),r&1&&(resr=std::max(resr,f[r^1]));
        resl=std::max(resl,resr);
        red(i,l>>1)resl+=f[i];
        return resl;
    }
    void set(cll s,cll w){
        n_=s,n=2<<(31^__builtin_clz(n_+3));
        memset(f,0,(n+1)<<4);
        rep(i,1,n_)f[i+n]=w*x[i];
        per(i,n-1,1)pushup(i);
        //rep(i,1,n_)printf("%lld ",query(i,i));puts("");
    }
}dt;
aN g;
struct opt{
    ll l,r,op,c,*res;
    void add(){
        x[++tx]=l-1;
        x[++tx]=r;
    }
    void calc(){
        /*if(op==1)rep(i,l,r)g[i]+=c;
        else{
            *res=-inf;
            rep(i,l,r)*res=std::max(*res,g[i]+c);
            //printf("res=%lld %lld %lld\n",c,g[4],*res);
        }
        //rep(i,1,5)printf("%lld ",g[i]);puts("");
        return;*/
        l=std::lower_bound(x+1,x+tx+1,l-1)-x+1;
        r=std::lower_bound(x+1,x+tx+1,r)-x;
        if(op==1)dt.update(l,r,c);
        else{
        *res=dt.query(l,r)+c;
            //printf("res=%lld %lld %lld\n",dt.query(l,r),c,*res);
            }
    }
}q[N];
aN f;
void calc(cll ID){
    (void)ID;
    cll n=readll(),m=readll(),k=readll(),d=readll();
    rep(i,1,m)p[i].read();
    if(n<=1000){
        static ll w[1002][1002];
        memset(w,0,sizeof w);
        rep(i,1,m)w[p[i].l][p[i].r+1]+=p[i].c;
        rep(i,1,n+1){
             ll x=0;
             rep(j,i,n+1)w[i][j]=x+=w[i][j];
        }
        rep(i,1,n+1){
             ll x=0;
             per(j,i,1)w[j][i]=x+=w[j][i];
        }
        f[0]=0;
        rep(i,1,n+1){
            f[i]=-inf;
            rep(j,std::max(1ll,i-k),i)f[i]=std::max(f[i],f[j-1]+(i-j)*-d+w[j][i]);//,printf("%lld %lld %lld\n",i,j,(i-j)*d+w[j][i]);
            //printf("%lld\n",f[i]);
        }
        writell(f[n+1],10);
        return;
    }else{
        std::sort(p+1,p+m+1);
        tx=0;
        ll tq=0,xz;
        rep(i,1,m){
            //printf("%lld %lld %lld\n",p[i].l,p[i].r,p[i].c);
            q[++tq]=(opt){1,p[i].l,1,p[i].c,NULL};
            if(i==m||p[i].r!=p[i+1].r)++tq,xz=p[i].r+1,
            q[tq]=(opt){std::max(1ll,xz-k),xz,0,-d*xz,&q[tq+1].c}
            ,++tq,q[tq]=(opt){xz+1,p[i+1].r+1,1,0,NULL};
        }
        rep(i,1,tq)q[i].add();
        std::sort(x+1,x+tx+1),tx=std::unique(x+1,x+tx+1)-x-1;
        dt.set(tx,d);
        
        //rep(i,1,n+1)g[i]=i*d;
        
        rep(i,1,tq-1)/*printf("%lld %lld %lld %lld\n",q[i].l,q[i].r,q[i].op,q[i].c),*/q[i].calc();
        writell(q[tq].c,10);
    }
}
int main(){
    rep(i,1,T)calc(i);
    return 0;
}
/*
f(i)=max[j in [1,i]]f(j-1)+cover(j,i)
//choose[i]=0
cover(j,i)=(i-j)*-d+[i-j>k?-inf:0]+sum[[l,r] in [j,i-1]?c:0]
segment_tree?
*/
