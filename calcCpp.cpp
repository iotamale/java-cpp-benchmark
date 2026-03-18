#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int n = 1000;
    if (argc > 1) {
        n = stoi(argv[1]);
    }

    vector<long long> A(n * n);
    vector<long long> B(n * n);
    vector<long long> C(n * n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i*n + j] = i + j;
            B[i*n + j] = i - j;
        }
    }

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i*n + j] += A[i*n + k] * B[k*n + j];
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto durationMs = chrono::duration_cast<chrono::milliseconds>(end - start).count();

    cout << durationMs << "ms\n";
    cout << C[0] << '\n';

    return 0;
}