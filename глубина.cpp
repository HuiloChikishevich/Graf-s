#include <fstream>
#include <stack>
#include <vector>
#include <iostream>
#include <clocale>
#define N 10
using namespace std;
 
void designing(int* , int, int, ofstream&); // ךמםסענףטנמגאםטו לאנרנףעא
 
int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream o("result.txt");
    ifstream in("A.txt");
    if (!in) return 1;
    // ------------------------------טםטצטאכטחאצטÿ------------------------------
    stack <int> st; // סעוך הכÿ ץנאםוםטÿ םמלונמג גונרטם
    bool instack[N]; //false - גונרטםא םו ג סעוךו, true - ג סעוךו
    bool DUG[N][N]; // לאענטצא סלוזםמסעט
    int start, end; // םמלונ סעאנעמגמי ט ךמםוקםמי גונרטם
    int rang[N]; // הכטםא ןףעט
    int VON_PUNKT[N]; // םמלונ גונרטםû, טח ךמעמנמי ןמןאכט ג עוךףשף‏
    cout<< "Âגוהטעו םאקאכüםף‏ גונרטםף: ";
    do{ cin>> start;} while (start < 0 || start > 9);
    cout<< "Âגוהטעו ךמםוקםף‏ גונרטםף: ";
    do{ cin>> end;} while (end < 0 || end > 9 || end == start);
    for (int i = 0; i < N; i++)
    {
        VON_PUNKT[i] = start;
        rang[i] = 999;
        instack[i] = false;
        for (int j = 0; j < N; j++)
            in>> DUG[i][j];
    }
    // חאןטסûגאול םאקאכüםף‏ גונרטםף ג מקונוהü
    st.push (start);
    instack[start] = true;
    VON_PUNKT[start] = -1;
    rang[start] = 0;
    // --------------------------------מבשטי ראד--------------------------------
    while (!st.empty())
    {
          int besuch = st.top();
          st.pop();
          for (int i = 0; i < N; i++)
          {
              if (!instack[i] && DUG[besuch][i])
              {
                  st.push (i);
                  instack[i] = true;
                  rang[i] = rang[besuch] + 1;
                  VON_PUNKT[i] = besuch;
              }
          }
    }
    // --------------------------חאןטסü ןףעט ג פאיכ ----------------------------
    designing(VON_PUNKT, rang[end], end, o);
    in.close();  o.close();
    return 0;
}
 
void designing(int *p, int rang, int end, ofstream &o)
{
    vector <int> v;
    vector <int>::iterator cur;
    for (int i = end; i != -1; i = p[i])
        v.push_back(i);
    o<< "Êמכטקוסעגמ ןונוץמהמג: "<< rang<< endl;
    for (cur = v.end() - 1; cur >= v.begin(); cur--)
        o<< *cur<< " ";
}
