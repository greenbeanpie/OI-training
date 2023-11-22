#include<bits/stdc++.h>
using namespace std;

#define For(i, l, r) for (int i = (l); i <= (r); ++i)
const int N = 3e3 + 5;

struct IO {
    char c; int f;
#define gc() getchar()
    template<class C>
    inline IO& operator >> (C &x) {
        x = 0; f = 1;
        while (!isdigit(c = gc()) && ~c) f |= -!(c ^ 45);
        while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
        x *= f; return *this;
    }
    inline IO& operator >> (char &x) {
        while ((c = gc()) < 33 && ~c);
        x = c; return *this;
    }
#define pc(c) putchar(c)
    inline bool operator ~ () { return ~c; }
} io;

int n, m, ch[26], i1, i2;
char c;
string a[N], b[N];

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    io >> n >> m;
    For (i, 1, n) {
        For (j, 1, m) {
            io >> c;
            ch[c - 'a']++;
        }
        a[i].resize(m); b[i].resize(m);
        int t = 0;
        For (j, 0, 25)
            while (ch[j]) {
                a[i][t] = b[i][m - t - 1] = j + 'a';
                ch[j]--; t++;
            }

        if (!i1) i1 = i;
        else {
            if (b[i1] > b[i]) i2 = i1, i1 = i;
            else {
                if (!i2) i2 = i;
                else if (b[i2] > b[i]) i2 = i;
            }
        }
    }

    For (i, 1, n) {
        if (i ^ i1) pc((a[i] < b[i1]) + '0');
        else {
            if (!i2) pc('1');
            else pc((a[i] < b[i2]) + '0');
        }
    }
    puts("");

    return 0;
}
