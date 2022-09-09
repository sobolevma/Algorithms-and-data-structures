// ASD3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>
// заголовочный файл с прототипом функции clock()
#include <ctime>
#include <fstream>
using namespace std;
#define N 1000
//структура stroka
struct stroka{
int massive[100000] ;//массив с максимальной длиной 100000
int dlina;
} ;

int kolvo_strok,sum_dl=0;
struct stroka* mas_strok=( stroka*)malloc(sizeof(struct stroka[N]));

int maximal_index(int n, int array[])//находим индекс максимального элемента
{
    int max_index=0; 
    for(int i=0;i<n;i++)
    {
        if(array[i]>array[max_index])
            max_index=i;
	}
     return max_index; 
}
 
void array_printout(int ar[], int S)
{
    for (int i=0; i<S; i++)
        cout << ar[i] << "\t";
    cout << endl;
}

void Swap(int *a,int *b)
{
int c=*a;
*a=*b;
*b=c;
}


void sort_pancaces()  
{
	for(int c=0;c<kolvo_strok;c++)
	{
		int max=0,a=0;
	
		for(int j=mas_strok[c].dlina-1-a;j>=0;j--)//идем с конца строки
		{
			// cout << endl << a+1 << " iteration" << endl; 
			 max=maximal_index(mas_strok[c].dlina-a, mas_strok[c].massive); 
			//cout<<max<<"+"<<endl;
			// cout<<arr[max]<<endl;
			 //cout<<endl<<endl; 
			//чтобы не вертеть, если максимальное значение уже на своём месте
			 if (!(max==j))
			{
				//переворачиваем массив от максимального значения до хвоста, точнее тех элементов, которые уже отсортированы
				for(int j=mas_strok[c].dlina-1-a,i=max;i<j;i++,j--)//длина массива с i по j, где i увеличивается а j
				{
					Swap(&mas_strok[c].massive[j],&mas_strok[c].massive[i]);
					//cout<<arr[i]<<"++";
				} 
				//cout << "after swap of end..." << endl;
				//array_printout(arr, length);
			}

			 a++; 
		}
		

	}
}

bool prov_znach(char k)
{
if(k=='+'||k=='-'||k=='0'||k=='1'||k=='2'||k=='3'||k=='4'||k=='5'||k=='6'||k=='7'||k=='8'||k=='9')
return true;
else return false;
}

void Zapolnenie_vihodnogo_faila(string file_name2)
{
	fstream  MyFile2(file_name2,ios::out);
	if(MyFile2)
	{
		for(int i=0;i<kolvo_strok;i++)
		{
			for(int j=0;j<mas_strok[i].dlina;j++)
			{
				
				MyFile2<<mas_strok[i].massive[j]<<"  ";}
		MyFile2<<endl;
		}
	}
	else
     cout<<"Невозможно открыть файл!!!";	
	MyFile2.close();
}

int main() {
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
	
	filename1="C:\\Users\\Максим\\Desktop\\Практика по АСД\\АСД 3\\"+filename1;
	filename2="C:\\Users\\Максим\\Desktop\\Практика по АСД\\АСД 3\\"+filename2;
	  
	ifstream  MyFile1(filename1,ios::in);
	//bool pr=false;
   char zn;
   string s="";
   bool znak=false;
   kolvo_strok=0;
   int i=0,j=0,e=0;   
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
				
				if(!(symbol=='+'||symbol=='-'))
				{
					s+=symbol;
					i++;
					
					if(i>0&&znak==false)
					{
					zn='+';
					
					}
				}
				else if(i==0)
				{
					zn=symbol;
					i++;
					znak=true;
				}
			
			}
			else //if(pr==false)
			{
				if(s.length()>0)
			{
			
				if(zn=='+')
				{
					mas_strok[j].massive[e]=atoi(s.c_str());
					e++;
					s="";
				}
				else
				{
					mas_strok[j].massive[e]=-atoi(s.c_str());
					e++;
					s="";
				}
					
				//pr=true;
				
								
			}
			
			znak=false;
			i=0;
			
			
			
			//pr=false;
			}			
		
			
		}
		else
		{
			if(s!="")
			{
				if(zn=='+')
					{
					mas_strok[j].massive[e]=atoi(s.c_str());
					e++;
					s="";
					}
				else
				{
					mas_strok[j].massive[e]=-atoi(s.c_str());
					e++;
					s="";
				}
			}
			
			mas_strok[j].dlina=e;
			sum_dl+=mas_strok[j].dlina;
			e=0;
			j++;
		}
		
		}
	kolvo_strok=j;
	
	//сортировка массивов структуры
	if(s12!="-t")sort_pancaces();
   Zapolnenie_vihodnogo_faila(filename2);
	
   
   }
   else
     cout<<"Невозможно открыть файл!!!";
	MyFile1.close();
	finish = clock(); //время окончания выполнения программы 
	duration = (float)(finish-sred_2+sred_1-nach_4+nach_3-nach_2+nach_1-start)/ CLOCKS_PER_SEC ; //время выполнения программы
	cout<<"  Время работы программы: "<<duration*1000<<endl<<"  Среднее длина строк в массивах: "<<sum_dl/kolvo_strok<<endl<<"  Количество строк: "<<kolvo_strok<<endl<<endl;
	getch();
    return 0;
}
 

