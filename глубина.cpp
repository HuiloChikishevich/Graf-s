#include <fstream>
#include <stack>
#include <vector>
#include <iostream>
#include <clocale>
#define N 10
using namespace std;
�
void designing(int* , int, int, ofstream&); // ��������������� ��������
�
int main()
{
� � setlocale(LC_ALL, "Russian");
� � ofstream o("result.txt");
� � ifstream in("A.txt");
� � if (!in) return 1;
� � // ------------------------------�������������------------------------------
� � stack <int> st; // ���� ��� �������� ������� ������
� � bool instack[N]; //false - ������� �� � �����, true - � �����
� � bool DUG[N][N]; // ������� ���������
� � int start, end; // ����� ��������� � �������� ������
� � int rang[N]; // ����� ����
� � int VON_PUNKT[N]; // ����� �������, �� ������� ������ � �������
� � cout<< "������� ��������� �������: ";
� � do{ cin>> start;} while (start < 0 || start > 9);
� � cout<< "������� �������� �������: ";
� � do{ cin>> end;} while (end < 0 || end > 9 || end == start);
� � for (int i = 0; i < N; i++)
� � {
� � � � VON_PUNKT[i] = start;
� � � � rang[i] = 999;
� � � � instack[i] = false;
� � � � for (int j = 0; j < N; j++)
� � � � � � in>> DUG[i][j];
� � }
� � // ���������� ��������� ������� � �������
� � st.push (start);
� � instack[start] = true;
� � VON_PUNKT[start] = -1;
� � rang[start] = 0;
� � // --------------------------------����� ���--------------------------------
� � while (!st.empty())
� � {
� � � � � int besuch = st.top();
� � � � � st.pop();
� � � � � for (int i = 0; i < N; i++)
� � � � � {
� � � � � � � if (!instack[i] && DUG[besuch][i])
� � � � � � � {
� � � � � � � � � st.push (i);
� � � � � � � � � instack[i] = true;
� � � � � � � � � rang[i] = rang[besuch] + 1;
� � � � � � � � � VON_PUNKT[i] = besuch;
� � � � � � � }
� � � � � }
� � }
� � // --------------------------������ ���� � ���� ----------------------------
� � designing(VON_PUNKT, rang[end], end, o);
� � in.close(); �o.close();
� � return 0;
}
�
void designing(int *p, int rang, int end, ofstream &o)
{
� � vector <int> v;
� � vector <int>::iterator cur;
� � for (int i = end; i != -1; i = p[i])
� � � � v.push_back(i);
� � o<< "���������� ���������: "<< rang<< endl;
� � for (cur = v.end() - 1; cur >= v.begin(); cur--)
� � � � o<< *cur<< " ";
}
