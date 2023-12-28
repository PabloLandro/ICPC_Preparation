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



double distance(double xk, double x1,double y1,double x2,double y2) {
    return sqrt(y1*y1 + (xk-x1)*(xk-x1)) + sqrt(y2*y2 + (xk-x2)*(xk-x2));
}

void dicot(double x1,double y1,double x2,double y2) {
    double a = x1, b = x2;
    double xk = (x1+x2)/2;
    
    double curr = distance(xk,x1,y1,x2,y2);
    bool found = false;
    while (!found) {
        double aux1 = distance((xk+a)/2,x1,y1,x2,y2);
        double aux2 = distance((xk+b)/2,x1,y1,x2,y2);
        double aux3 = distance(xk-0.001,x1,y1,x2,y2);
        double aux4 = distance(xk+0.001,x1,y1,x2,y2);
        if (aux1 < curr) {
            found = curr-aux1 < 0.000001 && aux1-curr > -0.000001;
            curr = aux1;
            b = xk;
        } else if (aux2 < curr) {
            found = curr-aux2 < 0.000001 && aux2-curr > -0.000001;
            curr = aux2;
            a = xk;
        } else if (aux3 < curr) {
            found = curr-aux3 < 0.000001 && aux3-curr > -0.000001;
            curr = aux3;
            a = xk-0.001;
        }  else if (aux4 < curr) {
            found = curr-aux4 < 0.000001 && aux4-curr > -0.000001;
            curr = aux4;
            a = xk+0.001;
        } else{
            found = true;
        }

    }
    printf("%.7f\n", curr);
}

void solve() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dicot(x1,y1,x2,y2);
    return;
    
    /*double xk = (x1+x2)/2;
    double dist = 0;
    //xk = x1+x2 + sqrt(x1*x1+x2*x2-2*x1*x2-4*y1*y2);
    //xk /= 2;
    //if (y1 == y2)
        printf("%.7f\n", (double)(sqrt(y1*y1 + (xk-x1)*(xk-x1)) + sqrt(y2*y2 + (xk-x2)*(xk-x2))));
    /*if (y1 < y2) {
        printf("%.7f\n", (double)(y1 + sqrt(y2*y2 + (x1-x2)*(x1-x2))));    
    } else {
        double aux = y1;
        y1 = y2;
        y2 = aux;
        printf("%.7f\n", (double)(y1 + sqrt(y2*y2 + (x1-x2)*(x1-x2)))); 
    }*/
    //printf("%.9ld\n", dist);*/
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