#include <iostream>

#include <vector>



using namespace std;



void matrix1 (int **p, int **arr, int v, int e) {

    for (int i=0; i<v; i++) {

        for (int j=0; j<v; j++) {

            p[i][j]=0;

        }

    }

    for (int i=0; i<e; i++) {

        p[arr[i][0]-1][arr[i][1]-1]=1;

        p[arr[i][1]-1][arr[i][0]-1]=1;

    }

}



void DFS (int v0, int p=-1, int v, int **g, bool *used, int *f, int *t, int timer) {

    int children=0;

    used [v0]=1;

    t[v0]=f[v0]=timer++;

    for (int i=0; i<v; i++) {

        if (g[v0][i]) {

            int to=g[v0][i];

            if (to==p) {

                continue;

            }

            if (used[to]) {

                f[v0]=min(t[to], f[v0]);

            }

            else {

                dfs (to, v0, v, g, used, f, t, timer);

                f[v0]=min(f[v0], f[to]);

                if (f[to]>=t[v0] && p!=-1) {

                    arr_c(v0);

                    children++;

                }

            }

        }

    }

    if (p==-1 && children>1) {

        arr_c(v0);

    }

}



int main() {

    int e,v;

    cin>>e>>v; //количество ребер и вершин

    int v1, v2;

    cin>>v1>>v2;

    int **arr=new int* [e];

    for (int i=0; i<e; i++) {

        arr[i]=new int [2];

    }

    for (int i=0; i<e; i++) {

        cin>>arr[i][0]>>arr[i][1];

    }

    int **g=new int* [v]; //матрица смежности

    for (int i=0; i<v; i++) {

        g[i]=new int [v];

    }

    matrix1 (g, arr, v, e);

    bool *used=new bool [v];

    for (int i=0; i<v; i++) {

        used[i]=0;

    }

    int *f=new int [v];

    int *t=new int [v];

    int timer=0;

    DFS (0, -1, v, g, used, f, t, timer);

    return 0;

}
