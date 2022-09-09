// ASD2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include "conio.h"

#include <iostream>
#include <cstring>
#include <stdexcept>
 using namespace std;
class String
{
public:
    typedef size_t size_type;
    typedef char value_type;
    static const size_type npos = -1;
    String();
    String( const String& );
    String( const char* );
    String( const char* str, size_type length );
    ~String(); 
	size_type Insert(const String&,size_type index = 0 )const;

    friend bool operator== ( const String&, const String& );
    friend bool operator!= ( const String&, const String& );
    char& operator[] ( size_type );
    const char& operator[] ( size_type ) const;
    String& operator= ( const String& );
    String& operator= ( const char* );
    friend std::ostream& operator<< ( std::ostream&, const String& );
    friend std::istream& operator>> ( std::istream&, String& );
    String& operator+= ( const String& );
    String& operator+= ( const char* );
    friend String operator+ ( const String&, const String& );
    friend String operator+ ( const char*, const String& );
    friend String operator+ ( const String&, const char* );
    friend String strcpString(String,String ,int );
	friend void  kol_simv(String);
	
    size_type find( const String&, size_type index = 0 ) const;
    size_type find( const char*, size_type index = 0 ) const;
    size_type find( const char*, size_type, size_type ) const;
    size_type find( char, size_type index = 0 ) const;
    void resize( size_type );
    String substr( size_type index = 0, size_type length = npos ) const;   
    void swap( String& );
    size_type size() const;
    size_type capacity() const; 
private:
    size_type m_len;
    size_type m_capacity;
    char *m_arr;
};
 
String::String():
m_len( 0 ), m_capacity( 2*m_len+1 ), m_arr( new char[m_capacity]() )
{
    *m_arr = '\0';
}
 
String::String( const String& s ):
m_len( s.m_len ), m_capacity( 2*m_len+1 ), m_arr( new char[m_capacity]() )
{
    strcpy( m_arr, s.m_arr );
}
 
String::String( const char* str ):
m_len( strlen( str ) ), m_capacity( 2*m_len+1 ), m_arr( new char[m_capacity]() )
{
    strcpy( m_arr, str );
}
 
String::String( const char* str, size_type length ):
m_len( std::min( length, strlen( str ) ) ), 
    m_capacity( 2*m_len+1 ), m_arr( new char[m_capacity]() )
{
    strncpy( m_arr, str, std::min( length, strlen( str ) ) );
}
 
String::~String()
{
    delete [] m_arr;
}
 
bool operator== ( const String& c1, const String& c2 )
{
    return strcmp( c1.m_arr, c2.m_arr ) == 0;
}
 
bool operator!= ( const String& c1, const String& c2 )
{
    return strcmp( c1.m_arr, c2.m_arr ) != 0;
}
 
char& String::operator[] ( size_type index )
{
    return m_arr[index];
}
 
const char& String::operator[]( size_type index ) const
{
    return m_arr[index];
}
 
String& String::operator= ( const String& s )
{
    if ( this != &s )
        String( s ).swap( *this );  
    return *this;
}
 
String& String::operator= ( const char* s )
{
    String( s ).swap( *this );  
    return *this;
}
 
std::ostream& operator<< ( std::ostream& out, const String& s )
{
    out << s.m_arr;
    return out;
}
 
std::istream& operator>> ( std::istream& in, String& s )
{
    char tmp[4096];
    in >> tmp;
    s = in ? tmp : String();
    return in;
}
 
String& String::operator+= ( const String& append )
{
    resize( m_len + append.m_len + 1 );
    strcat( m_arr, append.m_arr );
    return *this;
}
 
String& String::operator+= ( const char* append )
{
    resize( m_len + strlen( append ) + 1 );
    strcat( m_arr, append );
    return *this;
}
 
String operator+ ( const String& lhs, const String& rhs )
{
    String ret( lhs );
    ret += rhs;
    return ret;
}
 
String operator+ ( const char* lhs, const String& rhs )
{
    String ret( lhs );
    ret += rhs;
    return ret;
}
 
String operator+ ( const String& lhs, const char* rhs )
{
    String ret( lhs );
    ret += rhs;
    return ret;
}
 
String strcpString(String A,String B,int pos,int a,int b)
{
	int j=0,i;
	String C=A;
	A.resize(a+b);
	
		
	for(i=pos;i<a;i++)	
	{
		if(j<b)
			A[i+b]=A[i];
		else
			A[i+b]=C[i];
		j++;
	}
	cout<<A<<endl;
	j=0;
	for(i=pos;i&&j<b;i++)	
	{
		A[i]=B[j];
		j++;
	}
	cout<<A<<endl;
	
	return A;
}


 
String::size_type String::find( const String& str, size_type index ) const
{
    char * ptr = strstr( m_arr + index, str.m_arr );
    if (ptr != nullptr)
        return ptr - m_arr;
    else
        return npos;
}
 
String::size_type String::find( const char* str, size_type index ) const
{
    char *ptr = strstr( m_arr + index, str );
    if (ptr != nullptr)
        return ptr - m_arr;
    else
        return npos;
}
 
String::size_type String::find( char ch, size_type index ) const
{
    for ( size_type i = index; i != m_len; ++i )
    {
        if ( m_arr[i] == ch ) 
            return i;
    }
    return npos;
}
 
String String::substr( size_type index, size_type length ) const
{
    String res( this->m_arr + index, length );
    return res;
}
 
void String::resize( size_type new_len )
{
    m_capacity = 2 * new_len + 1;
    char *new_arr = new char[m_capacity]();
    strcpy( new_arr, m_arr );
    delete [] m_arr;
    m_len = new_len;
    m_arr = new_arr;
}
 
void String::swap( String& c ) 
{ 
    if ( this != &c )
    {
        std::swap( m_len, c.m_len );
        std::swap( m_capacity, c.m_capacity );
        std::swap( m_arr, c.m_arr );
    }
}

String::size_type String::size() const
{
    return m_len;
}
 
String::size_type String::capacity() const
{
    return m_capacity;
}
 
int mass[26];
void funct(char k12)
{
if(k12=='a'||k12=='A')
	mass[0]++;
else if(k12=='b'||k12=='B')
	mass[1]++;
else if(k12=='c'||k12=='C')
	mass[2]++;
else if(k12=='d'||k12=='D')
	mass[3]++;
else if(k12=='e'||k12=='E')
	mass[4]++;
else if(k12=='f'||k12=='F')
	mass[5]++;
else if(k12=='g'||k12=='G')
	mass[6]++;
else if(k12=='h'||k12=='H')
	mass[7]++;
else if(k12=='i'||k12=='I')
	mass[8]++;
else if(k12=='j'||k12=='J')
	mass[9]++;
else if(k12=='k'||k12=='K')
	mass[10]++;
else if(k12=='l'||k12=='L')
	mass[11]++;
else if(k12=='m'||k12=='M')
	mass[12]++;
else if(k12=='n'||k12=='N')
	mass[13]++;
else if(k12=='o'||k12=='O')
	mass[14]++;
else if(k12=='p'||k12=='P')
	mass[15]++;
else if(k12=='q'||k12=='Q')
	mass[16]++;
else if(k12=='r'||k12=='R')
	mass[17]++;
else if(k12=='s'||k12=='S')
	mass[18]++;
else if(k12=='t'||k12=='T')
	mass[19]++;
else if(k12=='u'||k12=='U')
	mass[20]++;
else if(k12=='v'||k12=='V')
	mass[21]++;
else if(k12=='w'||k12=='W')
	mass[22]++;
else if(k12=='x'||k12=='X')
	mass[23]++;
else if(k12=='y'||k12=='Y')
	mass[24]++;
else if(k12=='z'||k12=='Z')
	mass[25]++;
}


void  kol_simv(String s)
{
	for(int i=0;i<26;i++)
		mass[i]=0;
	for(int i=0;i<s.size();i++)
	{
		funct(s[i]);
	}
	for(int i=0;i<26;i++)
		if(mass[i]>0)
		{
		if(i==0) 
			{
				cout<<"A:"<<mass[i]<<endl;}
		else if( i==1)
			{
				cout<<"B:"<<mass[i]<<endl;}
		else if( i==2)
			{cout<<"C:"<<mass[i]<<endl;}
		else if( i==3)
			{cout<<"D:"<<mass[i]<<endl;}
		else if( i==4)
			{cout<<"E:"<<mass[i]<<endl;}
		else if( i==5)
			{cout<<"F:"<<mass[i]<<endl;}
		else if( i==6)
			{cout<<"G:"<<mass[i]<<endl;}
		else if( i==7)
			{cout<<"H:"<<mass[i]<<endl;}
		else if( i==8)
			{cout<<"I:"<<mass[i]<<endl;}
		else if( i==9)
			{cout<<"J:"<<mass[i]<<endl;}
		else if( i==10)
			{cout<<"K:"<<mass[i]<<endl;}
		else if( i==11)
			{cout<<"L:"<<mass[i]<<endl;}
		else if( i==12)
			{cout<<"M:"<<mass[i]<<endl;}
		else if( i==13)
			{cout<<"N:"<<mass[i]<<endl;}
		else if( i==14)
			{cout<<"O:"<<mass[i]<<endl;}
		else if( i==15)
			{cout<<"P:"<<mass[i]<<endl;}
		else if( i==16)
			{cout<<"Q:"<<mass[i]<<endl;}
		else if (i==17)
			{cout<<"R:"<<mass[i]<<endl;}
		else if( i==18)
			{cout<<"S:"<<mass[i]<<endl;}
		else if( i==19)
			{cout<<"T:"<<mass[i]<<endl;}
		else if (i==20)
			{cout<<"U:"<<mass[i]<<endl;}
		else if (i==21)
			{cout<<"V:"<<mass[i]<<endl;}
		else if (i==22)
			{cout<<"W:"<<mass[i]<<endl;}
		else if( i==23)
			{cout<<"X:"<<mass[i]<<endl;}
		else if(i==24)
			{cout<<"Y:"<<mass[i]<<endl;}
		else if( i==25)
			{cout<<"Z:"<<mass[i]<<endl;}
	}
}
int main(void)
{
    setlocale(LC_ALL,"Russian");
	String str1, str2,str3,str4,str5;
	
    cout << "Введите str1: ";
    cin >> str1;
    cout << "Введите  str2: ";
    cin >> str2;
    cout << str1 + str2<<endl;
	str3=str1+str2;
	cout<<str3<<endl;
	str4=str1;
	if(str4==str1)
		cout<<"str4 равна str1"<<endl;
	str4+=str2;
	if(str4!=str1)
		cout<<"str4 не равна str1"<<endl;
	cout<<"Длина str1:"<<str1.size()<<endl;
	cout<<"Вхождение подстроки str2 в строку str4 начинается с элемента c индексом:"<<str4.find(str2,0)<<endl;
    str5=strcpString(str1,str2,3,str1.size(),str2.size());
	cout<<"Новая строка:"<<str5<<endl;
	kol_simv(str5);
	return 0;
}























