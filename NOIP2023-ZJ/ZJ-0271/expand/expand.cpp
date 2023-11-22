#define PROBLEM expand

#ifdef DEBUG_zPbYWEQlRAWJ3OvuMksw50wYDAJC1812TmBHJtbb6mMCAYXCXJ1B3EZrwVgIcUA0
#include <iostream>
#else
#define _STR(x) #x
#define _FNAME(x, ext) _STR(x) "." #ext
#include <fstream>
namespace std {
    ifstream cin(_FNAME(PROBLEM, in));
    ofstream cout(_FNAME(PROBLEM, out));
}
#undef _FNAME
#undef _STR
#endif

#include <vector>

namespace ns0 {
    int xseq[1000000], yseq[1000000];
    bool bfMatch[5000];
    bool Solve(int n, int m) {
        if (xseq[0] == yseq[0]) {
            return false;
        }
        int* gseq, * lseq;
        int glen, llen;
        if (xseq[0] > yseq[0]) {
            gseq = xseq;
            lseq = yseq;
            glen = n;
            llen = m;
        }
        else {
            gseq = yseq;
            lseq = xseq;
            glen = m;
            llen = n;
        }
        if (gseq[glen - 1] <= lseq[llen - 1]) {
            return false;
        }
        if (glen <= 2000 & llen <= 2000) { // The BruteForce algorithm
            for (int i = 0; i < llen; i++) {
                bfMatch[i] = false;
            }
            bfMatch[0] = true;
            int firstMatch = 0;
            for (int i = 0; i < glen; i++) {
                int cur = gseq[i];
                int tfm = llen;
                for (int i = firstMatch; i < llen; i++) {
                    if (bfMatch[i] == true) {
                        if (lseq[i] < cur) {
                            bfMatch[i + 1] = true;
                            if (i < tfm) {
                                tfm = i;
                            }
                        }
                        else {
                            bfMatch[i] = false;
                        }
                    }
                }
            }
            return bfMatch[llen - 1];
        }
        return false;
    }
    std::vector<std::pair<int, int>> xchanges, ychanges;
    int main() {
        int _, n, m, q;
        std::cin >> _ >> n >> m >> q;
        for (int i = 0; i < n; i++) {
            std::cin >> xseq[i];
        }
        for (int i = 0; i < m; i++) {
            std::cin >> yseq[i];
        }
        std::cout << Solve(n, m);
        for (int _ = 0; _ < q; _++) {
            xchanges.clear();
            ychanges.clear();
            int xops, yops;
            std::cin >> xops >> yops;
            // Apply changes
            for (int i = 0; i < xops; i++) {
                int pos, val;
                std::cin >> pos >> val;
                pos--;
                xchanges.push_back({ pos, xseq[pos] });
                xseq[pos] = val;
            }
            for (int i = 0; i < yops; i++) {
                int pos, val;
                std::cin >> pos >> val;
                pos--;
                ychanges.push_back({ pos, yseq[pos] });
                yseq[pos] = val;
            }
            std::cout << Solve(n, m);
            // Revert changes
            for (auto x : xchanges) {
                xseq[x.first] = x.second;
            }
            for (auto y : ychanges) {
                yseq[y.first] = y.second;
            }
        }
        return 0;
    }
}

int main() {
    return ns0::main();
}
