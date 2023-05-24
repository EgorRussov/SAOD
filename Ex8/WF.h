#pragma once
#include <string>
#include <algorithm>
#include <iostream>
class WF {
private:
    int* pm;
    int M;
    int N;
    std::string s;
    std::string t;
    bool matrixInitialized;

public:
    WF() : pm(nullptr), M(0), N(0), matrixInitialized(false) {
    }

    ~WF() {
        delete[] pm;
    }

    void Init(const char* sc, const char* tc) {
        s = std::string(sc);
        t = std::string(tc);

        if (matrixInitialized) {
            delete[] pm;
        }

        M = s.length();
        N = t.length();
        pm = new int[(M + 1) * (N + 1)];

        matrixInitialized = true;
    }


    int Rows() const {
        return M;
    }

    int Columns() const {
        return N;
    }

    int Get(int i, int j) const{
        return pm[i * (N + 1) + j];
    }

    void Set(int i, int j, int val) const {
        pm[i * (N + 1) + j] = val;
    }

    int Distance() const {
        int M = s.length();
        int N = t.length();
        for (int i = 0; i <= M; i++) {
            Set(i, 0, i);
        }

        for (int j = 0; j <= N; j++) {
            Set(0, j, j);
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                int penalty = (s[i - 1] == t[j - 1]) ? 0 : 1;
                int value = std::min({ Get(i - 1, j) + 1, Get(i, j - 1) + 1, Get(i - 1, j - 1) + penalty });
                Set(i, j, value);
            }
        }
        return Get(M, N);
    }


    WF(const WF&) = delete;
    WF& operator=(const WF&) = delete;
};
