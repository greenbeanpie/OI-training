#include <bits/stdc++.h>

#define int long long
#define map unordered_map
#ifndef ONLINE_JUDGE
#pragma GCC optimize(                                                       \
    3, "Ofast", "inline", "-fgcse", "-fgcse-lm", "-fipa-sra", "-ftree-pre", \
    "-ftree-vrp", "-fpeephole2", "-ffast-math", "-fsched-spec",             \
    "unroll-loops", "-falign-jumps", "-falign-loops", "-falign-labels",     \
    "-fdevirtualize", "-fcaller-saves", "-fcrossjumping", "-fthread-jumps", \
    "-funroll-loops", "-freorder-blocks", "-fschedule-insns",               \
    "inline-functions", "-ftree-tail-merge", "-fschedule-insns2",           \
    "-fstrict-aliasing", "-falign-functions", "-fcse-follow-jumps",         \
    "-fsched-interblock", "-fpartial-inlining", "no-stack-protector",       \
    "-freorder-functions", "-findirect-inlining", "-fhoist-adjacent-loads", \
    "-frerun-cse-after-loop", "inline-small-functions",                     \
    "-finline-small-functions", "-ftree-switch-conversion",                 \
    "-foptimize-sibling-calls", "-fexpensive-optimizations",                \
    "inline-functions-called-once", "-fdelete-null-pointer-checks")
#endif
namespace IN {
#define getc() (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, 1000000), p1 == p2)? EOF  : *p1++)
    char buf[1000000], * p1, * p2;
    template <typename T>
    inline bool read(T& x) {
        static std::streambuf* inbuf = std::cin.rdbuf();
        x = 0;
        register int f = 0, flag = false;
        register char ch = getc();
        while (!std::isdigit(ch)) {
            if (ch == '-') f = 1;
            ch = getc();
        }
        if (std::isdigit(ch)) x = x * 10 + ch - '0', ch = getc(), flag = true;
        while (std::isdigit(ch)) {
            x = x * 10 + ch - 48;
            ch = getc();
        }
        x = f ? -x : x;
        return flag;
    }
    template <typename T, typename... Args>
    inline bool read(T& a, Args &...args) {
        return read(a) && read(args...);
    }
#undef getc
}  // namespace IN

namespace OUT {
    template <typename T>
    inline void put(T x) {
        static std::streambuf* outbuf = std::cout.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf->sputc('-');
            x = -x;
        }
        if (!x) {
            outbuf->sputc('0');
            outbuf->sputc('\n');
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf->sputc(stack[top]);
            --top;
        }
        outbuf->sputc('\n');
    }
    inline void putc(const char ch) {
        static std::streambuf* outbuf = std::cout.rdbuf();
        outbuf->sputc(ch);
    }
    template <typename T>
    inline void put(const char ch, T x) {
        static std::streambuf* outbuf = std::cout.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf->sputc('-');
            x = -x;
        }
        if (!x) {
            outbuf->sputc('0');
            outbuf->sputc(ch);
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf->sputc(stack[top]);
            --top;
        }
        outbuf->sputc(ch);
    }
    template <typename T, typename... Args>
    inline void put(T a, Args... args) {
        put(a);
        put(args...);
    }
    template <typename T, typename... Args>
    inline void put(const char ch, T a, Args... args) {
        put(ch, a);
        put(ch, args...);
    }
}  // namespace OUT
using IN::read;
using OUT::put;
using OUT::putc;
int sid;
int line(int num) { return num / sid + 1; }
int row(int num) { return num % sid + 1; }
void range_modify(std::map<int, int>* cnt, int x) {
    while ((*--((*cnt).end())).first >= x) {
        cnt[(*--cnt->end()).first - x] += (--*cnt->end()).second;
        cnt->erase(--cnt->end());
    }
}
int range_query(std::map<int, int>* cnt, int x) {
    return (*cnt)[x];
}
signed main() {
    int n, m;
    read(n);
    read(m);
    sid = 1.0 * ceil(sqrt(n));
    int num[n + 1][n + 1];
    std::map<int, int> cnt[n + 1];
    int cur = 0;
    for (int i = 1; i <= sid && cur < n; i++) {
        read(num[i][1]);
        for (int j = 2; j <= sid && cur < n; j++) {
            read(num[i][j]);
            cnt[i][num[i][j]]++, cur++;
        }
    }
    int op,l,r,x;
    for (int T = 0; T < m; T++) {
        read(op);read(l);read(r);read(x);
        int startl = line(l), startr = row(l), endl = line(r), endr = row(r);
        if (op == 1) {
            if (startr == 1) {
                range_modify(cnt[startl], x);
            }
            else {
                for (int i = startr; i <= sid; i++) {
                    if (num[startl][i] >= x) {
                        cnt[startl][num[startl][i]]--;
                        cnt[startl][num[startl][i] - x]++;
                        num[startl][i] -= x;
                    }
                }
            }
            for (int i = startl + 1; i < endl; i++) {
                range_modify(cnt[i], x);
            }
            if (endr == sid) {
                range_modify(cnt[endl], x)
            }
            else {
                for (int i = endr; i <= sid; i++) {
                    if (num[endl][i] >= x) {
                        cnt[endl][num[endl][i]]--;
                        cnt[endl][num[endl][i] - x]++;
                        num[endl][i] -= x;
                    }
                }
            }
        }
        else {
            int cnt1 = 0;
            if (startr == 1) {
                cnt += range_query(cnt[startl], x);
            }
            else {
                for (int i = startr; i <= sid; i++) {
                    if (num[startl][i] >= x) {
                        cnt++;
                    }
                }
            }
            for (int i = startl + 1; i < endl; i++) {
                cnt += range_query(cnt[i], x);
            }
            if (endr == sid) {
                cnt += range_query(cnt[endl], x)
            }
            else {
                for (int i = endr; i <= sid; i++) {
                    if (num[endl][i] == x) {
                        cnt++;
                    }
                }
            }
            put(cnt);
            putc("\n");
        }
    }
    return 0;
}