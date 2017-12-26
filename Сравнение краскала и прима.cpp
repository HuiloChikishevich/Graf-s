#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf=1000000;
void matrix (int **p, int **arr, int *cost, int v, int e) {

    for (int i=0; i<v; i++) {

        for (int j=0; j<v; j++) {

            p[i][j]=0;

        }

    }
    for (int i=0; i<e; i++) {

        p[arr[i][0]-1][arr[i][1]-1]=cost[i];

        p[arr[i][1]-1][arr[i][0]-1]=cost[i];

    }

}
void Prim (int **g, int v, bool *used, vector <int> min, vector <int> s) {

    min[0]=0;

    int t=0;

    for (int i=0; i<v; i++) {

        t=-1;

        for (int j=0; j<v; j++) {

            if (used[j]==0) {

                if (min[t]>min[j] || t==-1) {

                    t=j;

                }

            }

        }

        if (min[t]!=inf) {

            used[t]=1;

            if (s[t]!=-1) {

                cout<<t<<" "<<s[t]<<endl;

            }

            for (int i=0; i<v; i++) {

                if (g[t][i]<min[i]) {

                    min[i]=g[t][i];

                    s[i]=t;

                }

            }

        }

        else {

            cout<<"No Min Spanning Tree";

            return;

        }

    }

}
int DSU_get (int v, vector <int> p) {

	return (v==p[v]) ? v : (p[v]=DSU_get(p[v], p));

}
void DSU_unite (int x, int y, vector <int> p) {

	x=DSU_get(x, p);

	y=DSU_get(y, p);

	if (rand()&1)

		swap (x, y);

	if (x!=y)

		p[x]=y;

}
void Kruskal_with_DSU (int v, int e, vector <pair < int, pair <int,int>>> g) {

    vector<int> p (v);

    int cost=0;

    vector <pair <int,int>> q;

    sort (g.begin(), g.end());

    p.resize (v);

    for (int i=0; i<v; i++) {

        p[i]=i;

    }

    for (int i=0; i<e; ++i) {

        int z=g[i].first;

        int x=g[i].second.first;

        int y=g[i].second.second;

	    if (DSU_get(x, p)!=DSU_get(y, p)) {

	        cost+=z;

		    q.push_back (g[i].second);

		    DSU_unite (x, y, p);

	    }

    }

}
int main() {

    int e,v; //количество ребер, вершин

    cin>>e>>v;

    int **arr=new int* [e];

    int *cost=new int [e];

    for (int i=0; i<e; i++) {

        arr[i]=new int [2];

    }

    for (int i=0; i<e; i++) {

        cin>>arr[i][0]>>arr[i][1];

        cin>>cost[i];

    }

    int **g=new int* [v]; //матрица смежности

    for (int i=0; i<v; i++) {

        g[i]=new int [v];

    }

    matrix (g, arr, cost, v, e);

    bool *used=new bool [v];

    for (int i=0; i<v; i++) {

        used[i]=0;

    }

    vector <int> min (v, inf);

    vector <int> s (v, -1);

    Prim (g, v, used, min, s);

    vector <pair <int, pair <int,int>>> g1;

    for (int i=0; i<e; i++) {

        g1[i].first=cost[i];

        g1[i].second.first=arr[i][1];

        g1[i].first=arr[i][0];

    }

    Kruskal_with_DSU (v, e, g1);

    return 0;

}
