#ifndef MYSTRING_H
#define MYSTRING_H
#ifndef STR_MAX
  #define STR_MAX 255
#endif
#include "friends.h"
class String {
protected:
    char *str;
    int len;

public:
    String();
    String(const char *);
    String(const char);
    String(const String &);
    ~String();
    void clear();
	char *text();
    void friend report(char *);
};
class Identifier: public String {
public:
	Identifier();
	Identifier(const char *);
	Identifier(const Identifier &);
	Identifier operator <(const Identifier &);
	Identifier operator =(const char *);
    Identifier operator =(const Identifier &);
    char operator [](int);
	~Identifier();
	void toUpper();
};
class Combine: public String {
public:
	Combine();
	Combine(const char *);
	Combine(const Combine &);
	Combine operator =(const Combine &);
    	Combine operator ==(Combine& );
	Combine operator -(Combine &);
	Combine operator *(Combine &);
	~Combine();
	void ChangeChar();
    	void Change1(char*,int*,int*);
    	void Change2(char*,int);
};
#endif /* MYSTRING_H */
