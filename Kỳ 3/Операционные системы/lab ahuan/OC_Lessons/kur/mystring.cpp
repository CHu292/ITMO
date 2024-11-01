#include<iostream>
#include<cstring>
#include<cstdlib>
#include "mystring.h"

using namespace std;

String::String(){
    cout<<"Default String constructor"<<endl;
	str = new char[STR_MAX+1];
	str[0] = '\0';
	len = 0;
}

String::String(const char *s){
	cout<<"String constructor (char*)"<<endl;
	str = new char[STR_MAX+1];
	int i;
	for(i=0;i<STR_MAX&&s[i]!='\0';i++) str[i] = s[i];
	str[i] = '\0';
	len = i-1;
}

String::String(const char ch){
	cout<<"String constructor (char)"<<endl;
	str = new char[STR_MAX+1];
	str[0] = ch;
	str[1] = '\0';
	len = 1;
}

String::String(const String& ss){
	cout<<"Copy String constructor"<<endl;
	str = new char[STR_MAX+1];
	int i;
	for(i=0;i<=ss.len;i++) str[i] = ss.str[i];
	str[i] = '\0';
	len = ss.len;
}

String::~String(){
	cout<<"String destructor"<<endl;
	delete [] str;
}

char *String::text(){
	return str;
}

void String::clear()
{
    delete str;
    len = 0;
    str = new char[1];
    str[0] = 0;
    report("String::clear()");
}


Identifier::Identifier(){
    cout<<"Default Identifier constructor"<<endl;
}

Identifier::Identifier(const char *s){
	cout<<"Identifier constructor (char*)"<<endl;
	if(!isalpha(s[0])&&s[0]!='_') return;
	int i;
	for(i=1;i<STR_MAX&&s[i]!='\0';i++){
        if(!isalnum(s[i])&&s[i]!='_') return;
    }
	strcpy(str,s);
	len = i;
}
Identifier::Identifier(const Identifier& ss):String(ss){
    cout<<"Copy Identifier constructor"<<endl;
}

Identifier::~Identifier(){
    cout<<"Identifier destructor"<<endl;
}
Identifier Identifier::operator <(const Identifier& ss){
	report("Identifier operator <");
   	for (int i=0;i<max(strlen(str),strlen(ss.str));i++)
	{
		if (str[i] < ss.str[i]) { report("Result: True"); return *this; }
		if (str[i] > ss.str[i]) { report("Result: False"); return *this; }
	}
	if (strlen(str) < strlen(ss.str)) report("Result: True");
	else report("Result: False");
	return *this;
}


Identifier Identifier::operator =(const Identifier& ss){
    report("Identifier operator =");
	if(&ss == this)
	return *this;
	strcpy(str,ss.str);
	len = ss.len;
	return *this;
}

Identifier Identifier::operator =(const char *s){
	report("Identifier operator =");
	if(!isalpha(s[0])&&s[0]!='_'){ str[0]='\0'; len=0; return *this; }
	int i;
	for(i=0;i<STR_MAX&&s[i]!='\0';i++){
		if(!isalnum(s[i])&&s[i]!='_'){ str[0]='\0'; len=0; return *this; }
	}
	strncpy(str,s,i);
	str[i] = '\0';
	len = i;
	return *this;
}
char Identifier::operator [](int i)
{
    report("Identifier::operator[]");
    if ((i<0)||(i>=strlen(str))) {
        report("index is too big(small?)");
        return 0;
    }
    return str[i];
}

void Identifier::toUpper(){
    report("Identifier::function toUpper");
	for(int i=0;str[i]!='\0';i++) if(islower(str[i])) str[i]=toupper(str[i]);
}

Combine::Combine(){
    cout<<"Default Combine constructor"<<endl;
}

Combine::Combine(const char *S){
    cout<<"Combine constructor (char*)"<<endl;
    bool check = true;
	int i,count = 0;
	for (i = 0; i<strlen(S); i++)
	{
		if (S[i] == 'i')
		{
			count++;
			if (count > 1) check = false;
			continue;
		}
		if ((S[i] == '+')||(S[i] == '-'))
		 	if ((i == 0)||(S[i-1] == 'i')) continue;
		 	else check = false;
		if ( S[i]<'0' || S[i]>'9' ) check = false;
	}
	if (check)
	{
		len = strlen(S);
		str = new char[len+1];
		strcpy(str,S);
	}
	else
	{
		len = 0;
		str = new char[1];
		str[0] = '\0';
	}
}

Combine::Combine(const Combine& ss):String(ss){
    cout<<"Copy Combine constructor"<<endl;
}

Combine::~Combine(){
	cout<<"Combine destructor"<<endl;
}
Combine Combine::operator =(const Combine& ss){
	report("Combine operator =");
	if(&ss == this) return *this;
	strcpy(str,ss.str);
	len = ss.len;
	return *this;
}
void Combine::Change1(char* S,int* x,int* y)
{
	int count = 0,res = 0,dau = 1;
	*x = 0; *y = 0;
	for (int i=0; i<strlen(S); i++)
	{
		if (S[i] == 'i')
		{
			count ++;
			*x = res * dau;
			dau = 1;
			res = 0;
			continue;
		}
		if ((S[i] == '+')||(S[i] == '-'))
		{
			if (S[i] == '-') dau = -1; else dau = 1;
			continue;
		}
		res = res*10 + S[i] - 48;
	}
	if (count == 0) *x = res * dau; else *y = res * dau ;
}
void Combine::Change2(char* pCh,int x)
{
	if (x < 0)
	{
		char* s = new char[2];
		s[0] = '-'; s[1] = '\0';
		strcat(pCh,s);
		Change2(pCh,-x);
	}
	if (x > 0)
	{
		int y = x%10;
		char* s = new char[2];
		s[0] = y + 48; s[1] = '\0';
		Change2(pCh,x/10);
		strcat(pCh,s);
	}
}
Combine Combine::operator == (Combine& ss){
	report("Combine operator ==");
	int a,b,c,d;
	Change1(this->str,&a,&b);
	Change1(ss.str,&c,&d);
	if (a==c && b==d) report("Result == ");
		else report("Result !=");
}
Combine Combine::operator -(Combine& ss){
	report("Combine operator - ");
    int a,b,c,d;
    Change1(this->str,&a,&b);
    Change1(ss.str,&c,&d);

    a = a-c;
    b = b-d;

    this->str = new char[1]; this->str[0] = '\0';
	Change2(this->str,a);

	char* x = new char[2];
	x[0] = 'i';x[1] = '\0';
	if (b != 0) strcat(this->str,x);

	Change2(this->str,b);
	this->len = strlen(this->str);
	return *this;
}
Combine Combine::operator *(Combine& ss){
	report("Combine operator * ");
    	int a,b,c,d;
    	Change1(this->str,&a,&b);
    	Change1(ss.str,&c,&d);

    	a = a*c-b*d;
    	b = a*d+b*c;
    	this->str = new char[1]; this->str[0] = '\0';
	Change2(this->str,a);

	char* x = new char[2];
	x[0] = 'i';x[1] = '\0';
	if (b != 0) strcat(this->str,x);

	Change2(this->str,b);
	this->len = strlen(this->str);
	return *this;
}
