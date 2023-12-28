// TRIANGLE COLORING
// https://codeforces.com/problemset/problem/1795/D

#include <bits/stdc++.h>
using namespace std;    // Tipos
#define ll long long    // 64 bits INT
#define ld long double  // 80 bits FP

// Constantes
const unsigned ll MOD = 998244353;   // Para outputs grandes, a veces se piden darlos con

// Estructuras de datos
typedef vector<int> vi;

// Bucles
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b; i > 0; i--)

unsigned ll powe (unsigned ll b, unsigned ll e) {
    unsigned ll result = 1;
    unsigned ll p = b;
    while (e > 0) {
        if (e % 2) result = result * p % MOD;
        p = p * p % MOD;
        e /= 2;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;

    vi v(n, 0);
    FOR(i, 0, n) cin >> v[i];

    unsigned ll combinations = 1;
    for (int i = 0; i < n; i += 3) {
        int min = v[i];
        unsigned ll count = 3;
        if (v[i + 1] < min) {
            min = v[i + 1];
            count = 2;
        }
        if (v[i + 2] < min) {
            count = 1;
        }
        combinations = count*combinations % MOD;
    }

    vector<unsigned ll> F(n/3 + 1);
    F[0] = 1;
    for (int i = 1; i <= n/3;  i++)
        F[i] = i * F[i - 1] %MOD;

    unsigned ll n_3f = F[n/3];
    unsigned ll n_6f_inv = powe(F[n/6], MOD-2);
    combinations = combinations * n_3f % MOD;
    combinations = combinations * n_6f_inv % MOD;
    combinations = combinations * n_6f_inv % MOD;
    cout << combinations << endl;
}


int main() {
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
     //freopen("input.txt", "r", stdin);
     //freopen("output.txt", "w", stdout);

    solve();
}