#include<bits/stdc++.h> // rp++++++++
using namespace std;

const int MS = 3 * 1e3 + 5;
inline int read() {

    int t = 1, a = 0;
    char c = getchar();
    while(c < '0' || c > '9' && c != '-') c = getchar();
    if(c == '-') t = -1, c = getchar();
    while(c >= '0' && c <= '9') a = (a << 3) + (a << 1) + (c ^ 48), c = getchar();
    return a * t;

}

bool cmpmin(char a, char b) {
    return a < b;
}
bool cmpmax(char a, char b) {
    return a > b;
}
char c[MS];
int str1[MS], str2[MS];
int cnt[MS][30];
int n, m;

bool check(int a, int b)
{
    int l = str1[a], r = str2[b];
    int cl = cnt[a][l], cr = cnt[b][r];
    if(l > r) return false;
    if(l < r) return true;
    while(l == r) {
        int t = min(cnt[a][l], cnt[b][r]);
        cl -= t;
        cr -= t;
        while(cl == 0 && l <= 26 && l >= 0)l++, cl = cnt[a][l];
        while(cr == 0 && r <= 26 && r >= 0)r--, cr = cnt[b][r];
    }
    if(l < r) return true;
    if(l > r) return false;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w",stdout);
    n = read(); m = read();
    if(n == 1) {
        printf("1");
        return 0;
    }

    for(int a = 1; a <= n; a++) {
        str1[a] = 50; str2[a] = 0;
        for(int i = 1; i <= m; i++) {
            c[i] = getchar(); cnt[a][c[i] - 'a']++;
            str1[a] = min(str1[a], c[i] - 'a');
            str2[a] = max(str2[a], c[i] - 'a');
        }
        getchar();
    }
    for(int i = 1; i <= n; i++) {
        bool p = true;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(!check(i, j)) {p = false; break;}

        }
        if(p) printf("1");
        else printf("0");

    }

    return 0;

}
