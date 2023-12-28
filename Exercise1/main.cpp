// https://codeforces.com/contest/1895/problem/D
#include <bits/stdc++.h>

#include <string>

using namespace std;    // Tipos
#define ll long long    // 64 bits INT
#define ld long double  // 80 bits FP

// Constantes
#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;  // Valor de numero máximo de casos genérico
const ll MOD =
    1e9 + 7;  // Para outputs grandes, a veces se piden darlos con este modulo.
              // El modulo se puede aplicar en cada op. sin cambiar resultado
const ll INF = 1e9;   // Infinito
const ld EPS = 1e-9;  // Comparaciones de fp, e.g. if(abs(a-b) < EPS)

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
#define all(a) \
    (a).begin(), (a).end()  // Aplicar a toda la estructura, e.g. sort(all(a))

// Bucles
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ROF(i, a, b) for (int i = b - 1; i >= 0; i--)

struct node {
    string value;
    struct node *next;        // bit at the same position different
    struct node *descending;  // bit at the same position same, next node in
                              // ascending order
};

struct node *newNode(string data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void appendNode(node *root, string a, int index) {
    node branch;
    if (a[index] == '0') {
        if (root->left == NULL) root->left = newNode(-1);
        branch = root->left;
    } else {
        if (root->right == NULL) root->right = newNode(-1);
        branch = root->right;
    }
    if (index == a.length()-1) branch->value = a;
    else appendNode(branch, a, index+1);
}

node* createTree(vector<string> sorted) {
    node* root = newNode(-1) {}

    for (int i = 0; i < sorted.size(); i++) {
        string a = sorted[i];
        appendNode(root, a, 0);
    }
}

int main() {
    // Optimizacion I/O
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Usar archivos I/O, comentar al subir
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n = 1;
    cin >> n;

    vi a(n - 1, 0);

    for (int i = 0; i = n - 1; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<string> sorted(n, "");
    for (int i = 0; i < n-1; i++) {
        
    }

    node *root = createTree(sorted);
}