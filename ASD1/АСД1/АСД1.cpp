// ���1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "conio.h"
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define N 52
int m,Vrem,C1;
// ������ ��� ���������� ������.
class Wrong_koordinata_Tochki{};
 class Neverniy_vibor_deistvia{};
 class Perepolnenie_bufera{};
 class Neraspoznanniy_symbol{};
 class Nevernie_chasty_chisel{}; 
 // ������� ����� 50-���������� ����� � ��������� ������.
 void zapolnenie(int a[])
{
	int c;
	char f2;
	cout<<endl<<"������� ����: + ��� ������������� �����; - ��� ������������� �����:  ";
	cin>>f2;
	// �������� ������������ ���������� �����.
	if(f2=='+'||f2=='-')
	{
		// ������������ ���� ����� + ��� -
		if(f2=='+')
			a[0]=-1;
		else if(f2=='-')
			a[0]=-2;
		cout<<endl<<"������� ������ � ������� ��������� ����� � ������ �����:  ";
		cin>>c;
		{
			// �������� ������������ ���������� ��������� �����, ���������� ����� ����� �� �������.
			if(c>1&&c<N)
			{
				// ������������ ���� �����
				a[c]=-3;
				// ���������� ������� ��������� ��������
				for(int i=1;i<N;i++)
					if(i!=c)
						a[i]=rand()%10;
			}
			else			
				throw Wrong_koordinata_Tochki();		
		}
	}
	else 	
		throw Neraspoznanniy_symbol();	
}

 // ������� ������ 50-���������� ����� � ��������� ������.
void vivod(int a[])
{	
	for(int i=0;i<N;i++)
	{
		if(a[i]>=0)
			cout<<a[i];
		else if(i==0&&a[i]==-2)
			cout<<'-';
		else if(i>0&&a[i]==-3)
			cout<<'.';
	}
	cout<<endl;
}

// ������� �������� ����������� ����� ������ ����� �����.
bool prov(int a[],int b[])
{
	int i=1;
	while(a[i]!=-3&&b[i]!=-3&&i<N)	
		i++;
	if(a[i]==b[i])
			return true;
	else
		return false;
}

// ������� ������ ��������.
void vibor(int a[], int  b[])
{
	int ht,Z1;
	cout<<endl<<"���� ������ ������ �������� �� ������ ������� 1,"<<endl<<"���� ������ �� ������ ������� 2, "<<endl<<"���� ���� �������� ������ ����� ������� 3,"<<endl<<"���� ���� �������� ������ ����� ������� 4:   ";
	cin>>ht;
	switch(ht)
	{
		case 1:break;
		case 2:
			{
			//������ ������� �� �������� ��� �����.
			for(int i=0;i<N;i++)
			{
				Z1=a[i];
				a[i]=b[i];
				b[i]=Z1;		
			}
			break;	
			
			}
		case 3:
			{
			//��������� ������� �����.
			for(int i=0;i<N;i++)			
				a[i]=0;			
			break;		
			}
			case 4:
			{
			//��������� ������� �����
			for(int i=0;i<N;i++)			
				b[i]=0;			
			break;				
			}
			default:
				{
					throw Neverniy_vibor_deistvia();				
					break;
				}
	}
	cout<<endl<<endl;
}
//�������,����������� ������ ������� �� ������
void Vizov3(int a[],int b[])
{
	try
	{
		vibor(a,b);;
	}
	catch (Neverniy_vibor_deistvia) 
	 {
		cout<<endl<<endl<<"������������ ����� ��� ���� ��������!!!!"<<endl<<"�������� ������ ���������!!!!"<<endl<<endl;
		cout << "��������� ��������� ���� ������!!!" << endl<<endl;
		exit(0);
	}
}

void Ostatok(int a[],int b[]);
//�������,����������� ������ ������� �� ������
void Vizov4(int a[],int b[])
{
	try
	{
		Ostatok(a,b);
	}
	catch (Nevernie_chasty_chisel) 
	{		
		cout<<endl<<endl<<"������������ ������� ����� ����� ������� ��� ������� �����;"<<endl<<"�������� ������ ������; ���� ����������� �������� (������� �� ����)!!!"<<endl<<endl;
		cout<<"��������� ��������� ���� ������!!!"<<endl<<endl;
		exit(0);
	}
	catch (Perepolnenie_bufera) 
	{		
		cout<<endl<<endl<<"���������� �������� ������� �� ������� , ��� ��� ������� ������ �� ���������� � �����"<<endl<<endl;
		cout<<"��������� ��������� ���� ������!!!"<<endl<<endl;
		exit(0);
	}
}

//������� �������� ��������� ���� �����
void delimost (int a[],int b[])
{
	bool i=prov(a,b);
	if(i==true)
		{
			//����� ������� ������, ����������� �������, ������� ��������� ����������� ����� ������ �����.
			Vizov3(a,b);
			Vizov4(a,b);			
		}
	else
		throw Nevernie_chasty_chisel();
}

//�������,����������� ������ ������� �� ������
void Vizov2(int A[],int B[])
{
	try
	{
		delimost(A,B);
	}
	catch (Nevernie_chasty_chisel) 
	 {
		cout<<endl<<endl<<"������������ ������� ����� ����� ������� ��� ������� �����;"<<endl<<"����� ������ ����� ��������!!!"<<endl<<endl;
		cout << "��������� ��������� ���� ������!!!" << endl<<endl;
		exit(0);
	}
}

// ������� ������ ������� �� ������� 50-���������� ����� � ��������� ������ �� 50-��������� ����� � ��������� ������.
void vivod2(int B2[])
{
	int i=1;
	bool j=false;
	cout<<"������� �� ������� �����:"<<endl;	
	while((B2[i]==0)&&B2[1]==0&&j==false)
	{
		i++;
		if(B2[i+1]>0)
			j=true;
	}	
	//������� ������� �����.
	for(;i<C1;i++)
		//if(B2[i]!=-3)		
			cout<<B2[i];
	cout<<endl<<endl;		
}

// ������� ��������� �� ������ ���� �����.
bool sravn(int a[],int b[],int c,int c1)
{
	if(c>c1) return true;
	if(c==c1)
	{
		int i=1;
		while(a[i]==b[i]&&i<c)
			i++;
		if(a[i]>b[i]||a[0]<0&&b[0]>0)
			return true;
		else 
			return false;
	}
}

int otdel_drob(int a[])
{
int i,i1;
for(i=1;i<N;i++)
	if(a[i]!=-3)	
	{i1=i-1;i=N+1;}
	return i1;
}
// ������� ���������� �������.
void Ostatok(int a[],int b[])
{	
	int B2[N],B3[N];
	int c=otdel_drob(a);
	C1=c;
	int c1=otdel_drob(b);
	if(sravn(a,b,c,c1)==true)//�������� ���� ������� �����
	{
		if(c>c1)
		{
		int i=0;
		while(c<c-1)
			{
			
			B2[i]=B3[i]=0;
		}
		for(int i=0;i<c1;i++)
			//���������� ������������� �������� ���������� �� ������� b (��������� �����).	
			if(c==c1)
			B2[i]=B3[i]=b[i];
			else
			B2[i+1]=B3[i+1]=b[i];
		
			
		
		Vrem=0; //���������� �������� ����� �������� ������� ����� ����� �������� ������� ��������.
		i=c-1;
		if(b[c-1]!=0)
		{
			int j=2;
			while(sravn(a,B3,c,c1)==true)//�������� ���� ������� ����� ��� ����������� �����.
			{				
				for(i=0;i<c;i++) //���������� ����� �2 ������� �������� ����� �3.
					B2[i]=B3[i];		
				for(i=c-1;i>0;i--) //���������� ������ �������� ����� �3.
				{
						//if(b[i]!=-3) //�� ����� �����
						//{
							//���������� �������� ������� ����� �3 � ����� �������� ������� ����� �3
							int W;
							W=b[i]*j+Vrem;
							B3[i]=W%10;
							Vrem=W/10;	
							if(i==1&&Vrem>0)	//�������� �� ������������ ������							
								throw Perepolnenie_bufera();							
						//}
				}				
				//cout<<endl;
				//vivod(B2);
				//vivod(B3);
				//cout<<endl;				
				j++;	
			}
			if(a[0]==b[0])//���������� ������� �� ������� ��� 2-� ������������� ��� 2-� ������������� �����
			{
				for(i=c-1;i>0;i--)			
						//if(a[i]!=-3) //���������� �� �����
						{
							if(a[i]<B2[i])//���� ����������� ������ ������ �����������
							{
								if(a[i-1]>0)//���� ����������� ������ ������ 0
								{
									B3[i]=10+a[i]-B2[i];
									//if(a[i-1]!=-3)//���� ��������� ������ �����, ���� ��������� ��� �� ���� ������
										a[i-1]=a[i-1]-1;
									//else
										//a[i-2]=a[i-2]-1;
								}
								else  //���� ����������� ������ ����� 0
								{
									B3[i]=10+a[i]-B2[i];
									//if(a[i-1]!=-3) //���� ��������� ������ �����, ���� ��������� ��� �� ���� ������, � ����� ��� �� ����.
									//{
										a[i-1]=9;
										a[i-2]=a[i-2]-1;
									//}
									//else
									//{
										//a[i-2]=9;
										//a[i-3]=a[i-3]-1;
									//}
								}
							}
							else								
									B3[i]=a[i]-B2[i];														
						}
				vivod2(B3);
			}
			else if(a[0]!=b[0]) //���������� ������� �� ������� ��� �������������� � �������������� ����� �����
				{
					for(i=c-1;i>0;i--)	//���������� ����������� ������	
						//if(a[i]!=-3)
						{
							if(B3[i]<a[i])
							{
								if(B3[i-1]>0)
								{
									B2[i]=10+B3[i]-a[i];
									//if(B3[i-1]!=-3)
										B3[i-1]=B3[i-1]-1;
									//else
										//B3[i-2]=B3[i-2]-1;
								}
								else 
								{
									B2[i]=10+B3[i]-a[i];
									//if(a[i-1]!=-3)
									{
										B3[i-1]=9;
										B3[i-2]=B3[i-2]-1;
									}
									//else
									//{
										//B3[i-2]=9;
										//B3[i-3]=B3[i-3]-1;
									//}									
								}
							}
							else								
									B2[i]=B3[i]-a[i];														
						}
					vivod2(B2);
				}
		}	
		else		
			throw Nevernie_chasty_chisel();		
	}
	else
		cout<<"������� �� �������: "<<endl<<0<<endl<<endl;
}


void Vizov1(int a[])
{
	try
	{
		zapolnenie(a);
	}
	catch (Wrong_koordinata_Tochki) 
 {
	cout<<endl<<endl<< "�������� ���������� �����!!!  "<<endl<<endl;
	cout << "��������� ��������� ���� ������!!!" << endl<<endl;
	exit(0);
 }
 catch (Neraspoznanniy_symbol) 
 {
	cout<<endl<<endl << "������ ���������������� ������, �� + ��� - !!!"<<endl;
	cout << "��������� ��������� ���� ������!!!" << endl<<endl;
	exit(0);	
 }
}


int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL,"Russian");
	//������ �����
	int A[N];
	//������ �����
	int B[N];
	Vizov1(A);	
	vivod(A);
	Vizov1(B);
	vivod(B);			
	Vizov2(A,B);		
	getch();
	return 0;
}

