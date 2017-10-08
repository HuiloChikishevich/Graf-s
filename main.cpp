#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "locale.h"
 
using namespace std;
 
const int Vmax=100,
Emax=Vmax*(Vmax-1)/2; //в случае, если граф полный
int terminal[Emax], weight[Emax], point[Emax];
int head[Vmax], last[Vmax];
int n, m, v, u, w, k=0, i;
char r;
void Add(int v, int u, int w) //добавление ребра
{
k=k+1;
terminal[k]=u; weight[k]=w;
//если вершина v новая, то
//первая смежная ей вершина имеет номер k
if (head[v]==0) head[v]=k;
//если вершина v уже просматривалась, то
//следующая смежная с ней вершина имеет номер k
if (last[v]!=0) point[last[v]]=k;
last[v]=k;
}
//главная функция
void main()
{
setlocale(LC_ALL,"Rus");
cout<<"Кол. вершин >> "; cin>>n;
cout<<"Кол. ребер >> "; cin>>m;
cout<<"Вводите ребра и их вес (v, u, w):\n";
for (i=0; i<m; i++)
{
cin>>v>>u>>w;
cout<<"Ребро ориент.? (y/n) >> "; cin>>r;
if (r=='y') Add(v, u, w);
else
{
Add(v, u, w);
Add(u, v, w);
}
cout<<"..."<<endl;
}
m=m*2;
//вывод списка ребер
cout<<"Список ребер графа:\n";
for (i=0; i<m; i++)
{
k=head[i];
while (k>0)
{
cout<<"("<<i<<"->"<<terminal[k]<<")$="<<weight[k]<<endl;
k=point[k];
}
}
system("pause>>void");
}
int main()
{
    int n, m, x, y, a[80][80];
    setlocale(LC_ALL, "rus");
    cout << "Введите количество вершин: ";
    cin >> n;
    cout << "Введите количество рёбер: ";
    cin>> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
        cout << endl;
    cout << "Введите рёбра: " << endl;
    for(int i=1;i<=m;i++)
    {
        cin >> x >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    cout << endl;
    cout << "Матрица смежности: " << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    _getch();
    return 0;
}
int M, N; // размеры матрицы инцидентности
// adjacencyMatrix - матрица инцидентности размерами MxN
// выделяем память для матрицы смежности
bool **adjacencyMatrix = new bool*[M];
for (int row = 0; row < M; row++)
{
    adjacencyMatrix[row] = new bool[M];
    for (int column = 0; column < M; column++)
        adjacencyMatrix[row][column] = false;
}
 
// заполняем матрицу смежности значениями
// проходимся по каждому столбцу
for (int column = 0; column < N; column++)
{
    // индексы откуда и куда
    int from = -1, to = -1;
    // ищем строку, где будет указана информация откуда (1) и куда (-1)
    for (int row = 0; row < M && (from == -1 || to == -1); row++)
    {
        if (incidenceMatrix[row][column] == 1)
            from = row;
        else if (incidenceMatrix[row][column] == -1)
            to = row;
    }
    // помечаем переход в матрице смежности
    adjacencyMatrix[from][to] = true;
}
