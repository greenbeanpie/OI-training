#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int zh[N], fa[N], sta[N], stt[N];
bool stz[N], stf[N], st[N], sst[N], ssst[N];

int dfs(int u, int len){
	
    if(u == -1) return 0;

    if(sst[u] && len & 1) {
		return len;
	}
	
    if(st[u]) return 0;
    sst[u] = 1;
    st[u] = 1;
    if(stt[u] == -1){
        int j = fa[u];

        return dfs(j, len + 1);
    }else if(stt[u] == 1){
        int j = zh[u];
        return dfs(j, len);
    }else if(stt[u] == 0) st[u] = 1;

    return 0;
}

void dfss(int u){
    if(sta[u]) return;
    sta[u] = 1, ssst[u] = 1;
    if(stt[u] == -1){
        int j = fa[u];
    }else if(stt[u] == 1){
        int j = zh[u];
    }
}

int df(int u){
	if(sta[u] == 1 && ssst[u] == 0) return 1;
	
    if(stt[u] == -1){
        int j = fa[u];
    }else if(stt[u] == 1){
        int j = zh[u];

    }
    return 0;
}

int main(){
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

    int c, t;
    scanf("%d%d", &c, &t);
    while(t--){
		memset(sta, 0, sizeof sta);
        memset(zh, -1, sizeof zh);
        memset(fa, -1, sizeof fa);
        memset(stt, 0, sizeof stt);
        memset(stz, 0, sizeof stz);
        memset(stf, 0, sizeof stf);
        memset(sst, 0, sizeof sst);
        memset(st, 0, sizeof st);
        memset(ssst, 0, sizeof ssst);
        int n, m;
        
        scanf("%d%d", &n, &m);
        
        for(int i = 0; i < m; i++){
            char op;
           	cin >> op;
            if(op == '+'){
                int a, b;
                scanf("%d%d", &a, &b);
                if(stz[b])
                    zh[a] = zh[b];
                else zh[a] = b;
                stz[a] = 1;
                stt[a] = 1;
            }else if(op == '-'){
                int a, b;
                scanf("%d%d", &a, &b);
				fa[a] = b;
                stf[a] = 1;
                stt[a] = -1;
            }else if(op == 'U'){
                int a;
                scanf("%d", &a);
                sta[a] = 1;
            }else if(op == 'T'){
                int a;
                scanf("%d", &a);
                sta[a] = 2;
            }else if(op == 'F'){
                int a;
                scanf("%d", &a);
                sta[a] = 3;
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i++)
            if(!st[i]){
                memset(sst, 0, sizeof sst);
                int t = dfs(i, 0);
                if(t > 0){ 
                    res += t;
                    dfss(i);
                } 
            }
        memset(st, 0, sizeof st);
        for(int i = 1; i <= n; i++)
            if(!st[i])
                res += df(i);
        printf("%d\n", res);
    }

    
    return 0;
}
