#include<bits/stdc++.h>

int n, m;
int s[3005], t[3005];
int cnt[3005][29];
bool bl[3005];

int check(int p) {
    int now = 0;
    for(; !cnt[p][now]; now++);
    for(int i = 1; i <= n; i++) {
        bl[i] = 0;
        s[i] = 0;
        t[i] = 25;
        for(; !cnt[i][t[i]]; t[i]--);
        if(t[i] < now) return 0;
        else if(t[i] > now) bl[i] = 1;
    }
    bl[p] = 1;
    for(int dt; now < 26; now++) {
        dt = cnt[p][now];
        for(int i = 1; i <= n; i++) {
            if(bl[i]) continue;
            s[i] += dt;
            for(; s[i] >= cnt[i][t[i]]; s[i] -= cnt[i][t[i]], t[i]--);
            if(t[i] < now) return 0;
            else if(t[i] > now) bl[i] = 1;
        }
    }
    return 1;
}

int main() {
    freopen("dict.in", "r", stdin); freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1, ch; i <= n; i++) {
        scanf("\n");
        for(int j = 1; j <= m; j++) {
            ch = getchar() - 'a';
            cnt[i][ch]++;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d", check(i));
    puts("");
    return 0;
}
