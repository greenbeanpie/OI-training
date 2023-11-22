#define PROBLEM run

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
#include <algorithm>

namespace ns0 {
    typedef unsigned long long u64;
    typedef signed long long s64;
    struct Challenge {
        int date;
        int days;
        s64 value;
        Challenge(int x, int y, s64 v) : date(x), days(y), value(v) { }
        bool operator < (const Challenge& that) const {
            return this->date < that.date;
        }
    };
    std::vector<Challenge> challenges;
    void Initialize() {
        challenges.clear();
    }
    s64 Calculate(int brep, int n, int m, int k, int d) {
        int days = 0, cid = 0;
        s64 result = 0;
        for (int i = 0; i < n; i++) {
            if (brep & (1 << i)) {
                days++;
                result -= d;
                if (days > k) {
                    return 0;
                }
            }
            else {
                days = 0;
            }
            if (cid < m && challenges[cid].date == i) {
                if (days >= challenges[cid].days) {
                    result += challenges[cid].value;
                }
                cid++;
            }
        }
        return result;
    }
    int main() {
        int _, T;
        std::cin >> _ >> T;
        for (int _ = 0; _ < T; _++) {
            int n, m, k, d;
            std::cin >> n >> m >> k >> d;
            Initialize();
            for (int i = 0; i < m; i++) {
                int x, y;
                s64 v;
                std::cin >> x >> y >> v;
                x--;
                challenges.emplace_back(x, y, v);
            }
            std::sort(challenges.begin(), challenges.end());
            s64 maxPoints = 0;
            for (int i = 0, _i_End = 1 << n; i < _i_End; i++) {
                s64 points = Calculate(i, n, m, k, d);
                if (points > maxPoints) {
                    maxPoints = points;
                }
            }
            std::cout << maxPoints << '\n';
        }
        return 0;
    }
}

int main() {
    return ns0::main();
}

/**
#!/bin/bash

ulimit -m 1048576
ulimit -v 1048576
PROBLEM_NAME=$1
TEST=1
if g++ -O2 -std=c++14 -static ${PROBLEM_NAME}.cpp -o ${PROBLEM_NAME}.elf; then
	while [ -f ~/down/day0/${PROBLEM_NAME}/${PROBLEM_NAME}${TEST}.in ]; do
		echo -e "\033[107m\033[30m ** \033[0m TEST $TEST"
		cp ~/down/day0/${PROBLEM_NAME}/${PROBLEM_NAME}${TEST}.in ${PROBLEM_NAME}.in;
		printf '\033[34m'
		if /usr/bin/time -f "RUNTIME INFORMATION:\n  CPU time %E (%U user +%S system) seconds.\n  Memory %M KB max.\n  Exit status %x." ./${PROBLEM_NAME}.elf; then
			if diff -w ${PROBLEM_NAME}.out ~/down/day0/${PROBLEM_NAME}/${PROBLEM_NAME}${TEST}.ans; then
				echo -e "\033[102m\033[30m AC \033[0m \033[92mOK.\033[0m"
			else
				echo -e "\033[101m\033[30m WA \033[0m \033[91mANSWER INCORRECT.\033[0m";
			fi
		else
			echo -e "\033[101m\033[30m RE \033[0m \033[91mNON-ZERO EXIT STATUS.\033[0m";
		fi
		echo '';
		TEST=$(($TEST+1));
	done
else
	echo -e "\033[103m\033[30m CE \033[0m \033[93mFAILED TO COMPILE.\033[0m";
fi
*/
