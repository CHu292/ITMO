#ifndef DESK_H
#define DESK_H

#include "menu.h"
#include "listbox.h"
#include "mystring.h"

#define LIMIT 8

struct INSTANCE{
    String *item;
    int classId;
};

class Desk {

private:
    char ClassName[3][12];
    Menu mn, mn1, mn2, mn3, mn4, mn5;
    ListBox *lbx1, *lbx2;
    INSTANCE inst[LIMIT];
    int count;

public:
    Desk();
    ~Desk();
    void PaintBg(void);
    void Go(void);
    void Command(void);
    void setCount(void);
    void Init(void);
    int numInput(int,int,int,int,char *);
    void strInput(int,int,int,int,char *,char *,int);
    int str2int(char *,int &);
    int dataError(int,int,int,int);
    String *CreateInstance(int,char *);
    void numResult(int,int,int,int,char *,int);
    void Msg(int,int,int,int,char *);
    void strclear(void);
    void sidToUpper(void);
    void sidAssign(void);
    void sidSub(void);
    void Ind(void);
    void sbtInd(void);
    void sbtMulti(void);
    void sbtAssign(void);
    void sbtSub(void);
};

#endif /* DESK_H */
