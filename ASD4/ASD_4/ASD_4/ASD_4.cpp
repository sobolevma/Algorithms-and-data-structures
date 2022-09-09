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
// заголовочный файл с прототипом функции clock()
#include <ctime>
#include <fstream>
using namespace std;
#define N 1000

#define in_range(x,y,z) for(int x=y; x<z; x++)
struct stroka{
int WEIGHT ;//вес элемента
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
 
struct queue{ // Структура очередь
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
		MyFile2<<"Минимальный путь:"<<stroka<<endl;	
	else
     cout<<"Невозможно открыть файл!!!";	
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
	/*	//задание динамического массива	
		bool **graph = new bool *[length];
 
		for (int i = 0; i < length; i++) 
		{
			graph[i] = new bool [length];
		}

		
		
		
      int n, s, f,Nach_versh1,Konech_versh1,Nach_versh2,Konech_versh2;
	  Konech_versh2=Nach_versh1=0;//начальная вершина
	  Nach_versh2=Konech_versh1=length-1;//конечная вершина
    //cin >> n >> s >> f;
    //int graph[n][n];
    int *dist = new int [length];
	 //int dist[length]; // Массив расстояний от начальной до i-ой вершины
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
	
    queue vertex; // Очередь вершин
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
                used[i] = true; // i-ая вершина пройдена и не будет корректироваться позже
            }
        }
        used[v] = true;
        vertex.pop();
    }

	cout << dist[f-1];
	//проход от точки length-1 до точки 0
delete []used;
delete []dist;
*/


		

int n=length;
  
  vector < vector<int> > g(length); // граф
  int s=0; // начальная вершина
  /*
  in_range(i,0,m) // считывание графа
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

queue<int> q; // очередь с вершинами, которые мы рассматриваем на данном этапе
  q.push (s);
  vector<bool> used (n); // логический массив, указывающий, посещена ли вершина
  vector<int> d (n),p (n);
  used[s] = true;
  p[s] = -1;
  while (!q.empty()) // пока мы не обойдем все вершины, которые можно достигнуть из данной
    {
      int v = q.front();
      q.pop(); // достаем из головы очереди одну вершину
      for (size_t i=0; i<g[v].size(); ++i) //просмотрим все ребра, исходящие из данной вершины
        {
          int to = g[v][i];
          if (!used[to]) // если текущая вершина еще не была посещена
            {
              used[to] = true; //отмечаем, что мы ее посетили
              q.push (to); // помещаем в очередь
			   d[to] = d[v] + 1;// расстояние;

			  p[to] = v;// parent
            }
        }
    }
  vector<bool>::iterator it;
  it = find (used.begin(), used.end(), false); // проверяем, остались ли еще непосещенные вершины
  if (it == used.end())
    cout << "ГРАФ СВЯЗНЫЙ"<<endl; // если все вершины посещены, то граф связный
  else
    cout << "ГРАФ НЕСВЯЗНЫЙ"<<endl;
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
 //Расстояние до конечной вершины
  if (!used[to])
	cout << "Нет пути!";

else {
	vector<int> path;
	for (int v=to; v!=-1; v=p[v])
		path.push_back (v);
	reverse (path.begin(), path.end());
	cout << "Путь: ";
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
//очистка памяти	
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
	start = clock(); //время начала выполнения программы 
	setlocale(LC_ALL,"Russian");
	string filename1,filename2;
	cout<<"  Введите имя входного файла:  ";		
	nach_1=clock();
	SetConsoleCP(1251);
	getline(cin, filename1);
	SetConsoleCP(866);
	nach_2=clock();
	cout<<"  Введите имя выходного файла:  ";
	nach_3=clock();
	SetConsoleCP(1251);
	getline(cin, filename2);
	SetConsoleCP(866);
	nach_4=clock();
	string s12;
	cout<<"  Введите флаг:  ";
	sred_1=clock();
	SetConsoleCP(1251);
	cin>>s12;
	SetConsoleCP(866);
	sred_2=clock();
	cout<<endl<<endl;	
	filename1="К_АСД4_вход.txt";
	filename2="К_АСД4_выход.txt";
	filename1="C:\\Users\\Максим\\Desktop\\Практика по АСД\\АСД 4\\"+filename1;
	filename2="C:\\Users\\Максим\\Desktop\\Практика по АСД\\АСД 4\\"+filename2;	  
	ifstream  MyFile1(filename1,ios::in);
	int X=0,Y=0,WEIGHT=0;
	bool prov=false;   
   bool znak=true;

   int i=0,dlina_matr=0;   
  	if(MyFile1)
   {	
  
	   
	   //считывание данных из входного файла

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
     cout<<"Невозможно открыть файл!!!";
	finish=clock();
	duration = (float)(finish-sred_2+sred_1-nach_4+nach_3-nach_2+nach_1-start)/ CLOCKS_PER_SEC  ; //время выполнения программы
	cout<<"  Время работы программы: "<<duration*1000<<endl;
	getch();
	return 0;
}

