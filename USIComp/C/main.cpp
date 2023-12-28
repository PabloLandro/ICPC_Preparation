#include <bits/stdc++.h>
using namespace std;   // Tipos
#define ll long long   // 64 bits INT
#define ld long double // 80 bits FP 


// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5; // Valor de numero máximo de casos genérico
const ll MOD = 1e9 + 7;    // Para outputs grandes, a veces se piden darlos con este modulo. El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;        // Infinito
const ld EPS = 1e-9;       // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

// Estructuras de datos
#define ar array        
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vector<int>> graph;
typedef vector<vector<pair<int, int>>> wgraph; 
#define umap unordered_map
#define uset unordered_set
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define sza(x) ((int)x.size())  
#define all(a) (a).begin(), (a).end() // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define ROF(i, a, b) for(int i = b-1; i>=0; i--)

int n, maxIndex, minIndex;
ll minVal, maxVal, sum, secondMinVal;
vi a, d;

ll mark (int index) {
    ll out = sum;
    if (index == maxIndex)
        return out;
    if (index == minIndex) {
        if (d[index] > secondMinVal) {
            out -= secondMinVal;
            out += d[index];
        }
    } else if (d[index] > maxVal) {
        out -= a[index];
        out += maxVal;
    } else {
        out -= a[index];
        out += d[index];
    }
    return out;
}

void solve() {
    cin >> n;
    
    a.clear();
    a.resize(n);
    d.clear();
    d.resize(n);

    maxVal = 0;
    minVal = INF;
    secondMinVal = INF;
    sum = 0;

    FOR(i,0,n) {
        cin >> a[i];
        if (maxVal < a[i]) {
            maxVal = a[i];
            maxIndex = i;
        }
        if (minVal > a[i]) {
            minIndex = i;
            minVal = a[i];
        } else if (secondMinVal > a[i]) {
            secondMinVal = a[i];
        }
        sum += a[i];
    }
    sum -= minVal;
    sum -= maxVal;
    ll ans = 0;
    int z;
    FOR(i,0,n) {
        cin >> d[i];
        //ans = max(ans, mark(i));
        ll curr = mark(i);
        if (ans < curr) {
            ans = curr;
            z = i;
        }
    }

    cout << ans << ' ' << z << '\n';

}

int main()
{
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // Número de casos
    int tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}