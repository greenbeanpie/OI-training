#include<bits/stdc++.h>
const int N = 1e5+7;
int n, m;
struct val{
    int id; bool flp;
    friend bool operator==(val x, val y){
        return x.id == y.id && x.flp == y.flp;
    }
} v[N];
int ans;
val fa[N][2]; bool und[N][2];
inline val& f(val x){
    return fa[x.id][x.flp];
}
inline bool& u(val x){
    return und[x.id][x.flp];
}
void init(int n){
    for(int i=0; i<=n+1; i++){
        f({i, 0}) = {i, 0};
        f({i, 1}) = {i, 1};
    }
}
val fd(val x){
    return f(x)==x? x : f(x)=fd(f(x));
}
void un(val x, val y){
    x = fd(x), y = fd(y);
    f(x) = y;
}
void slv(){
    scanf("%d%d", &n, &m);
    init(n);
    for(int i=0; i<=n+1; i++)
        v[i] = {i, 0};
    while(m--){
        char op; scanf(" %c", &op);
        switch(op){
        case 'T': case 'F':{
            int i; scanf("%d", &i);
            v[i] = {0, op=='T'};
            break;
        }
        case 'U':{
            int i; scanf("%d", &i);
            v[i] = {n+1, 0};
            break;
        }
        case '+': case '-':{
            int i, j; scanf("%d%d", &i, &j);
            v[i] = {v[j].id, v[j].flp^(op=='-')};
            break;
        }
        }
    }
    for(int i=1; i<=n; i++){
        un({i, 0}, v[i]);
        un({i, 1}, {v[i].id, !v[i].flp});
    }
    memset(und, 0, sizeof(und));
    u(fd({n+1, 0})) = true;
    for(int i=1; i<=n; i++){
        if(fd({i, 0}) == fd({i, 1}))
            u(fd({i, 0})) = true;
    }
    ans = 0;
    for(int i=1; i<=n; i++)
        if(u(fd({i, 0})) || u(fd({i, 1})))
            ans++;
    printf("%d\n", ans);
}
int c, t;
int main(){
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while(t--) slv();
    return 0;
}
