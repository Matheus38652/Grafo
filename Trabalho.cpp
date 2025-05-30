#include <iostream>
#define V 6
using namespace std;

class Grafo {
private:
    int matriz[V][V];
    bool visitado[V];

public:
    Grafo() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                matriz[i][j] = 0;
            }
            visitado[i] = false;
        }
    }

    void adicionarAresta(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            if (matriz[u][v] == 0) {
                matriz[u][v] = matriz[v][u] = 1;
                cout << "Aresta adicionada entre " << u << " e " << v << endl;
            }
        } else {
            cout << "Índices inválidos!\n";
        }
    }

    void DFS(int v, int comunidade[], int &tamanho) {
        visitado[v] = true;
        comunidade[tamanho++] = v;

        for (int i = 0; i < V; i++) {
            if (matriz[v][i] == 1 && !visitado[i]) {
                DFS(i, comunidade, tamanho);
            }
        }
    }

    void encontrarComunidades() {
        cout << "\nComunidades detectadas:\n";
        for (int i = 0; i < V; i++) {
            visitado[i] = false;
        }

        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                int comunidade[V], tamanho = 0;
                DFS(i, comunidade, tamanho);

                cout << "{ ";
                for (int j = 0; j < tamanho; j++) {
                    cout << comunidade[j] << " ";
                }
                cout << "}\n";
            }
        }
    }
};

int main() {
    Grafo g;

    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(3, 4);
    g.adicionarAresta(5, 4);

    g.encontrarComunidades();

    return 0;
}
