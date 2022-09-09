// ASD_4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <vector>
#include <queue>
#include <windows.h>
// ������������ ���� � ���������� ������� clock()
#include <ctime>
#include <fstream>
using namespace std;
#define N 1000

#define in_range(x,y,z) for(int x=y; x<z; x++)
struct stroka{
int WEIGHT ;//��� ��������
int X;
int Y;
} ;

struct stroka* graf=( stroka*)malloc(sizeof(struct stroka[N]));


/*struct node{
    int value;
    node * next;
    node(int v, node * n = NULL){
        value = v;
        next = n;
    }
};
 
struct queue{ // ��������� �������
    node * start;
    node * finish;
	int len;
    //int len = 0;
    queue(node * s = NULL, node * f = NULL){
        start = s;
        finish = f;
    }

    string push(int n){
        if(len == 0){
            node * new_node = new node(n,finish);
            start = new_node;
            finish = new_node;
        }else{
            node * new_node = new node(n,NULL);
            start -> next = new_node;
            start = new_node;
        }
        len++;
        return "ok";
    }

    int pop(){
        int v = finish -> value;
        finish = finish -> next;
        len--;
        return v;
    }

    int front(){
        return finish -> value;
    }

    int size(){
        return len;
    }
};
*/



void Zapolnenie_vihodnogo_faila(string file_name2,string stroka)
{
	fstream  MyFile2(file_name2,ios::out);
	if(MyFile2)				
		MyFile2<<"����������� ����:"<<stroka<<endl;	
	else
     cout<<"���������� ������� ����!!!";	
	MyFile2.close();
}

bool prov_znach(char k)
{
if(k=='+'||k=='-'||k=='0'||k=='1'||k=='2'||k=='3'||k=='4'||k=='5'||k=='6'||k=='7'||k=='8'||k=='9')
return true;
else return false;
}

string alhoritm_kgrafu(int length)
{
		//int m=0;
		string strok="",S2="";
	/*	//������� ������������� �������	
		bool **graph = new bool *[length];
 
		for (int i = 0; i < length; i++) 
		{
			graph[i] = new bool [length];
		}

		
		
		
      int n, s, f,Nach_versh1,Konech_versh1,Nach_versh2,Konech_versh2;
	  Konech_versh2=Nach_versh1=0;//��������� �������
	  Nach_versh2=Konech_versh1=length-1;//�������� �������
    //cin >> n >> s >> f;
    //int graph[n][n];
    int *dist = new int [length];
	 //int dist[length]; // ������ ���������� �� ��������� �� i-�� �������
    //bool used[length];
	bool *used=new bool[length];
    //for(int i = 0; i < n; i++){
        //for(int j = 0; j < n; j++){
          //  cin >> graph[i][j];
        //}
    //}

    for(int i = 0; i < length; i++){
        dist[i] = 0;
        used[i] = false;
    }
	
    queue vertex; // ������� ������
    vertex.len=0;
	//
	vertex.push(s-1);
    used[s-1] = true;
    while(vertex.size() != 0){
        int v = vertex.front();
        for(int i = 0; i < length; i++){
            if(graph[v][i] == 1 && used[i] == false){
                vertex.push(i);
                dist[i] = dist[v] + 1; 
                used[i] = true; // i-�� ������� �������� � �� ����� ���������������� �����
            }
        }
        used[v] = true;
        vertex.pop();
    }

	cout << dist[f-1];
	//������ �� ����� length-1 �� ����� 0
delete []used;
delete []dist;
*/


		

int n=length;
  
  vector < vector<int> > g(length); // ����
  int s=0; // ��������� �������
  /*
  in_range(i,0,m) // ���������� �����
    {
      int u,v;
      cin >> u >> v;
      g[u-1].push_back(v-1);
      g[v-1].push_back(u-1);
    }
*/

  
	in_range(i,0,length)
 			{
				if(graf[i].WEIGHT!=0)
				{										
					g[graf[i].X-1].push_back(graf[i].Y-1);					
					g[graf[i].Y-1].push_back(graf[i].X-1);
					
				}
				// graph[graf[m].X][graf[m].Y]=false;
		
			}

queue<int> q; // ������� � ���������, ������� �� ������������� �� ������ �����
  q.push (s);
  vector<bool> used (n); // ���������� ������, �����������, �������� �� �������
  vector<int> d (n),p (n);
  used[s] = true;
  p[s] = -1;
  while (!q.empty()) // ���� �� �� ������� ��� �������, ������� ����� ���������� �� ������
    {
      int v = q.front();
      q.pop(); // ������� �� ������ ������� ���� �������
      for (size_t i=0; i<g[v].size(); ++i) //���������� ��� �����, ��������� �� ������ �������
        {
          int to = g[v][i];
          if (!used[to]) // ���� ������� ������� ��� �� ���� ��������
            {
              used[to] = true; //��������, ��� �� �� ��������
              q.push (to); // �������� � �������
			   d[to] = d[v] + 1;// ����������;

			  p[to] = v;// parent
            }
        }
    }
  vector<bool>::iterator it;
  it = find (used.begin(), used.end(), false); // ���������, �������� �� ��� ������������ �������
  if (it == used.end())
    cout << "���� �������"<<endl; // ���� ��� ������� ��������, �� ���� �������
  else
    cout << "���� ���������"<<endl;
 // for (int i = 0; i<n; i++)
        //cout << d[i] << "   ";
  int dlina=0;
  
  int to=length-2;
  if(it == used.end())
  {
	   int max_dlina=-1; 
	   string S="";
	  for(to=length-1;to>0;to--)
  {
 //���������� �� �������� �������
  if (!used[to])
	cout << "��� ����!";

else {
	vector<int> path;
	for (int v=to; v!=-1; v=p[v])
		path.push_back (v);
	reverse (path.begin(), path.end());
	cout << "����: ";
	for (size_t i=0; i<path.size(); ++i)
	{
		cout << path[i] + 1 << " ";
		S+=(char)(path[i] + 1+'0');
		
		dlina++;
	}

if(dlina>max_dlina)
{
	S2="";
	max_dlina=dlina;
	S2=S;
	S="";
}
	dlina=0;
}
	cout<<endl<<endl;
	  }
  }
  
  /* queue<int> q;
        q.push (s);
        vector<bool> used (n);
        vector<int> d (n), p (n);
        used[s] = true;
        p[s] = -1;
        while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (size_t i=0; i<g[v].size(); ++i) 
                {
                        int to = g[v][i];
                        if (!used[to]) 
                        {
                                used[to] = true;
                                q.push (to);
                                d[to] = d[v] + 1;
                                p[to] = v;
                        }
                }
        }
        for (int i = 0; i<n; i++)
                cout << d[i] << "  ";
        
        cout << endl;
*/
//������� ������	
//for (int i = 0; i < length; i++)
//{
 // delete []graph[i];
//}
//delete []graph;
		
		return strok=S2;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int cout_chisel=0;
	
	float duration;
	clock_t start, finish,sred_1,sred_2,nach_1,nach_2,nach_3,nach_4;
	start = clock(); //����� ������ ���������� ��������� 
	setlocale(LC_ALL,"Russian");
	string filename1,filename2;
	cout<<"  ������� ��� �������� �����:  ";		
	nach_1=clock();
	SetConsoleCP(1251);
	getline(cin, filename1);
	SetConsoleCP(866);
	nach_2=clock();
	cout<<"  ������� ��� ��������� �����:  ";
	nach_3=clock();
	SetConsoleCP(1251);
	getline(cin, filename2);
	SetConsoleCP(866);
	nach_4=clock();
	string s12;
	cout<<"  ������� ����:  ";
	sred_1=clock();
	SetConsoleCP(1251);
	cin>>s12;
	SetConsoleCP(866);
	sred_2=clock();
	cout<<endl<<endl;	
	filename1="�_���4_����.txt";
	filename2="�_���4_�����.txt";
	filename1="C:\\Users\\������\\Desktop\\�������� �� ���\\��� 4\\"+filename1;
	filename2="C:\\Users\\������\\Desktop\\�������� �� ���\\��� 4\\"+filename2;	  
	ifstream  MyFile1(filename1,ios::in);
	int X=0,Y=0,WEIGHT=0;
	bool prov=false;   
   bool znak=true;

   int i=0,dlina_matr=0;   
  	if(MyFile1)
   {	
  
	   
	   //���������� ������ �� �������� �����

	  while(!MyFile1.eof())
		{
			
			char symbol=MyFile1.get();
		
			if(symbol!='\n')
			{
			
			if(prov_znach(symbol)==true)
				{
					if(!(symbol=='+'||symbol=='-')&&cout_chisel==0) 
					{
						X=10*X+symbol-'0';
						prov=true;
					}
					else if(!(symbol=='+'||symbol=='-')&&cout_chisel==1) 
					{
						Y=10*Y+symbol- '0';		
						prov=true;
					}		
					else if(cout_chisel==2)
					{
						if(symbol=='-'&&i==0) {znak=false;i++;}
						else if(symbol=='-'&&i==0) {i++;}
						if(symbol!='+'&&symbol!='-') 
						{
							WEIGHT=10*WEIGHT+symbol- '0';
							prov=true;
						}				
					}			
				}	
				else if(prov==true)
				{
					cout_chisel++;
					prov=false;
				}
			}
			else
			{
			
				graf[dlina_matr].X=X;
				graf[dlina_matr].Y=Y;
				if(znak==true)
				{
					graf[dlina_matr].WEIGHT=WEIGHT;
			
				}
				else
				{
					graf[dlina_matr].WEIGHT=-WEIGHT;
				
				}
				//cout<<graf[dlina_matr].X<<'\t'<<graf[dlina_matr].Y<<'\t'<<graf[dlina_matr].WEIGHT<<endl;
				dlina_matr++;
				cout_chisel=0;
				X=0;
				Y=0;
				i=0;
				znak=true;
				WEIGHT=0;			
			}		
		}

	  if(s12!="-t")		
	{
		string S=alhoritm_kgrafu(dlina_matr);
		Zapolnenie_vihodnogo_faila(filename2,S);
	}	  
   }
   else
     cout<<"���������� ������� ����!!!";
	finish=clock();
	duration = (float)(finish-sred_2+sred_1-nach_4+nach_3-nach_2+nach_1-start)/ CLOCKS_PER_SEC  ; //����� ���������� ���������
	cout<<"  ����� ������ ���������: "<<duration*1000<<endl;
	getch();
	return 0;
}

