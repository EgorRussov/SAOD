#include "WFOpt.h"
#include <algorithm>

int Distance(const char* s, const char* t) {
    int M = strlen(s);
    int N = strlen(t);

    int* p1 = new int[N];
    int* p2 = new int[N];

    // Initialize p1 with numbers from 0 to N-1
    for (int j = 0; j < N; j++) {
        p1[j] = j;
    }

    for (int i = 1; i <= M; i++) {
        p2[0] = i; // Store the iteration number in the first element of p2

        for (int j = 1; j < N; j++) {
            int penalty = (s[i - 1] == t[j - 1]) ? 0 : 1;
            p2[j] = std::min({ p1[j] + 1, p2[j - 1] + 1, p1[j - 1] + penalty });
        }

        // Swap p1 and p2
        std::swap(p1, p2);
    }

    int distance = p2[N - 1]; // Distance is the last element of p1

    delete[] p1;
    delete[] p2;

    return distance;
}
