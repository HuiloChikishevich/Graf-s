#include <iostream>

#include <cmath>

#include <vector>



using namespace std;



void matrix (int **g, int **arr, int v, int k) {

    int count=0;

    for (int w=0; w<v; w++) {

        for (int i=w; i<v; i++) {

            for (int j=1; j<k-1; j++) {

                if (arr[w][j]==arr[i][j-1]) {

                    count++;

                }

            }

            if (count==k-2) {

                g[i][w]++;

                g[w][i]++;

            }

            count=0;

        }

    }

}



void CreateArray (int j, int w, int k, int n, int **arr, int *temp) {

    if(j==k) {

        for(int i=0; i<k; i++) {

            arr[w][i]=temp[i];

            w++;

        }

    }

    else {

        for(int i=-1; i<n; i++) {

            temp[j]=i+1;

            CreateArray (j+1, w, k, n, arr, temp);

        }

    }

}



void FindEulerianCycle (int **g, int v, int e, vector <int> &cycle, int v0) {

    for (int i=0; i<v; i++) {

        if (g[v0][i]!=0) {

            g[v0][i]--;

            g[i][v0]--;

            FindEulerianCycle (g, v, e, cycle, i);

        }

    }

    cycle.push_back(v0);

}



int main() {

    int n, k; //n-количество элементов в алфавите; k-длина слов

    cin>>n>>k;

    int v=pow(n, k-1);

    int e=pow(n, k);

    int **arr=new int* [v];

    int *temp=new int [k];

    for (int i=0; i<v; i++) {

        arr[i]=new int [k-1];

    }

    for (int i=0; i<v; i++) {

        for (int j=0; j<k-1; j++) {

            arr[i][j]=0;

        }

    }

    for (int i=0; i<k; i++) {

        temp[i]=0;

    }

    CreateArray (0, 0, k-1, n, arr, temp);

    int **g=new int* [v];

    for (int i=0; i<v; i++) {

        g[i]=new int [v];

    }

    matrix (g, arr, v, k);

    vector <int> cycle;

    FindEulerianCycle (g, v, e, cycle, 0);

    for (int i=0; i<cycle.size(); i++) {

        cout<<arr[cycle[i]][k-2]<<" ";

    }

    return 0;

}
