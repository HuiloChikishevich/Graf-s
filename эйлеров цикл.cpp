#include <iostream.h>
#include <stdlib.h>
 
struct Node
{
   int inf;
   Node *next;
};
 
//============================Stack==============================
 
void push(Node *&st,int dat)
{  // Load number in stack
 
   Node *el = new Node;
   el->inf = dat;
   el->next = st;
   st=el;
}
 
int pop(Node *&st)
{       // Izvlechenie iz steka
   int value = st->inf;
   Node *temp = st;
   st = st->next;
   delete temp;
 
   return value;
}
 
int peek(Node *st)
{     // polychenie chisla bez izvlechenia
   return st->inf;
}
 
//==============================================================
 
Node **graph;   //
const int vertex = 1; // first vershina
 
void add(Node*& list,int data)
{  //Dobavlenie smegnoy
 
   if(!list){list=new Node;list->inf=data;list->next=0;return;}
 
   Node *temp=list;
   while(temp->next)temp=temp->next;
   Node *elem=new Node;
   elem->inf=data;
   elem->next=NULL;
   temp->next=elem;
}
 
void del(Node* &l,int key)
{ // Delete key iz spiska
 
   if(l->inf==key){Node *tmp=l; l=l->next; delete tmp;}
   else
        {
	 Node *tmp=l;
	 while(tmp)
         {
	    if(tmp->next) //
	       if(tmp->next->inf==key)
                  {  //
		     Node *tmp2=tmp->next;
	             tmp->next=tmp->next->next;  
	             delete tmp2;  
	           }
	       tmp=tmp->next;
	 }
   }
}
 
int eiler(Node **gr,int num)
{ //
   int count;
   for(int i=0;i<num;i++)
   {  /
 
      count=0;
      Node *tmp=gr[i];
 
	 while(tmp)
         {       // schitaem stepen
            count++;
	    tmp=tmp->next;
         }
      if(count%2==1)return 0; //
   }
   return 1;   //
}
 
void eiler_path(Node **gr)
{ //
 
   Node *S = NULL;//
   int v=vertex;//
   int u;
 
   push(S,v); //
   while(S)
      {  //
	 v = peek(S); //
	 if(!gr[v]){ //
	 v=pop(S); cout<<v+1<<"   "; //
      }
     else
      {
	 u=gr[v]->inf; push(S,u);  //
	 del(gr[v],u); del(gr[u],v); //
      }
   }
}
 
int main()
{
 
system("CLS");
	cout<<"Êîëè÷åñòâî âåðøèí:  "; int n; cin>>n; //
   int zn;//
 
   graph=new Node*[n];
   for(int i=0;i<n;i++)graph[i]=NULL;
   for(i=0;i<n;i++)   //
	 for(int j=0;j<n;j++)
		 {
	    cin>>zn;
	    if (zn) add(graph[i],j);
	  }
 
		 cout<<"\n\nÐÅÇÓËÜÒÀÒ  ";
 
   if(eiler(graph,n))eiler_path(graph);
   else cout<<"Ãðàô íå ÿâëÿåòñÿ ýéëåðîâûì.";
 
   cout<<endl;
   cin.get();
   cin.get();
   return(0);
 
}
