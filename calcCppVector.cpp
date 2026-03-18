#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
    int n = 1000;
    if (argc > 1) {
        n = stoi(argv[1]);
    }

    vector<vector<long long> > A(n, vector<long long>(n));
    vector<vector<long long> > B(n, vector<long long>(n));
    vector<vector<long long> > C(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto durationMs = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << "cpp: " << durationMs << "ms\n";
    cout << C[0][0] << '\n';

    return 0;
}