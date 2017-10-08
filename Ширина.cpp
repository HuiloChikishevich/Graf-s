#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "fstream"
using namespace std;
int i,j,k,p,cur;
int Start,N,M;
int _tmain(int argc, _TCHAR* argv[])
{
    int i, j, k, p, cur;
    int Start, N, M;
    int *Label;
    int *FIFO;
    int **Graf;
    ifstream input ("Graf.txt");
    input>>N>>M>>Start;
    Label = new int[N];
    FIFO = new int[N];
    Graf = new int*[N];
    for(int i=0;i<N;i++)
        Graf[i] = new int[N];
    for(int i=0;i<N;i++)
        for(int j=0; j<N; j++)
            input>>Graf[i][j];    
    for(int i=0;i<N;i++)
    {  
        FIFO[i]=0;
        Label[i]=32767;
    }
    p = 0;
    k = 1;
    FIFO[p]=Start;
    Label[Start]=0;
    while(p!=k)
    {
        cur=FIFO[p];
        p++;
        for(int i=0;i<N;i++)
        {   if (Graf[cur][i]==1 && Label[i]>Label[cur]+1)
        {
            FIFO[k]=i;
            k++;
            Label[i]=Label[cur]+1;
        }
        }
    }
    for(int i=0;i<N;i++)
    {cout<<Label[i]<<" ";}
    getch();
    return 0;
}
2
