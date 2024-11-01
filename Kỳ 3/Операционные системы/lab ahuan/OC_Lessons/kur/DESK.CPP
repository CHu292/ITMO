#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
#include<iostream>
#include <string>
#include "desk.h"

using namespace std;

Desk::Desk(){             //конструктор
    PaintBg();
    mn.Add(80,30,120,30,"Init");
    mn.Add(260,30,120,30,"Test");
    mn.Add(440,30,120,30,"Exit");
    mn.setDisable(1);
    mn.setSelect(0);
    //mn.setDisable(1);
    mn1.Add(80,80,120,30,"How many");
    mn1.Add(80,120,120,30,"Begin value");
    mn1.setDisable(1);
    mn1.Hide();
    //Menu mn2
    mn2.Add(260,80,120,30,"String");
    mn2.Add(260,120,120,30,"Identtifier");
    mn2.Add(260,160,120,30,"Combine");
    mn2.Hide();
    //Menu mn3
    mn3.Add(390,80,120,25,"clear()");
    mn3.Hide();
    //Menu mn4
    mn4.Add(390,120,120,25,"Toupp");
    mn4.Add(390,145,120,25,"operator =");
    mn4.Add(390,170,120,25,"operator <");
    mn4.Add(390,195,120,25,"operator []");
   // mn4.Add(390,220,120,25," vxod");
    mn4.Hide();
    //Menu mn5
    mn5.Add(390,160,120,25,"operator *");
    mn5.Add(390,185,120,25,"operator =");
    mn5.Add(390,210,120,25,"operator ==");
    mn5.Add(390,235,120,25,"operator -");
    mn5.Hide();
    mn.setSubmenu(&mn1,0);
    mn.setSubmenu(&mn2,1);
    mn2.setSubmenu(&mn3,0);
    mn2.setSubmenu(&mn4,1);
    mn2.setSubmenu(&mn5,2);

    lbx1 = new ListBox(20,300,292,162);
    lbx2 = new ListBox(330,300,292,162);
    extern void *ptr;
    ptr = lbx2;

    strcpy(ClassName[0],"String");
    strcpy(ClassName[1],"Identifier");
    strcpy(ClassName[2],"Combine");

    for(int i=0;i<LIMIT;i++){
        inst[i].item = NULL;
        inst[i].classId = 0;
    }
    count = 0;

}

Desk::~Desk(){  //деструктор
    if(lbx1) delete lbx1;
    if(lbx2) delete lbx2;
}

void Desk::setCount(){   //ввод числа
     int k = numInput(205,80,30,30,"count ?");
     if(k>0&&k<=LIMIT){
         count = k;
         lbx1->AddSeveral(k);
         mn1.setEnable(1);
         mn1.setSelect(1);
         mn1.setDisable(0);
     } else dataError(205,80,5,30);
}

String *Desk::CreateInstance(int classId, char *val){  //выбор класса
    switch(classId){
        case 0: return new String(val);
        case 1: return new Identifier(val);
        case 2: return new Combine(val);
    }
    return NULL;
}

void Desk::Init(){  //запись
    int k=0, classId=0, limit=39;
    char val[limit+1];
    char text[limit+1]; text[0]='\0';
    k = numInput(205,120,30,30,"num ?");
    if(k<=0||k>count) if(dataError(205,120,30,30)) return;
    classId = numInput(205,120,30,30,"classId ?1)Identifier2)Combine");
    if(classId!=0&&classId!=1&&classId!=2) if(dataError(205,120,30,30)) return;
    strInput(205,120,30,30,"value ?",val,23);
    k--;
    lbx2->Clear();
    if(inst[k].item){ delete inst[k].item;
        inst[k].item = NULL;
        inst[k].classId = 0;
    }
    inst[k].item = CreateInstance(classId,val);
    inst[k].classId = classId;
    strcpy(val,inst[k].item->text());
    sprintf(text,"%d  %s  %s",k+1,ClassName[classId],val);
    if(inst[k].item) lbx1->UpdateRow(++k,text);
    k=0;
    while(inst[k++].item);
    if(k>count && !mn.isEnable(1)) mn.setEnable(1);
}

void Desk::strclear (){   //очистка строки
    int len, k = numInput(520,80,25,25,"num ?");
     char text[40]; text[0]='\0';
     if(k<=0||k>count){ if(dataError(520,80,25,25)) return; }
    else {
        inst[k-1].item->clear();
        sprintf(text,"%d  %s  %s",k,ClassName[0],inst[k-1].item->text());
        lbx1->UpdateRow(k,text);
    }
}


void Desk::sidToUpper(){       // верхний регистр
    int k = numInput(520,120,25,25,"num ?");
    if(k<=0||k>count){ if(dataError(520,120,25,25)) return; }
    if(inst[k-1].classId!=1) { Msg(520,120,25,25,"Wrong data"); return; }
    Identifier *pId = (Identifier*)inst[k-1].item;
    pId->toUpper();
    char text[40]; text[0]='\0';
    sprintf(text,"%d  %s  %s",k,ClassName[1],pId->text());
    lbx1->UpdateRow(k,text);
}

void Desk::sidAssign(){//присваивание
    int k,k1=0;
    Identifier *pOp[2];
    char op[2][6] = {"op1 ?","op2 ?"};
    for(int i=0;i<2;i++){
        k = numInput(520,145,25,25,op[i]); if(!k1) k1=k;
        if(k<=0||k>count){ if(dataError(520,145,25,25)) return; }
        if(inst[k-1].classId!=1) { Msg(520,145,25,25,"Wrong data"); return; }
        pOp[i] = (Identifier*)inst[k-1].item;
    }
    *pOp[0] = *pOp[1];
    char text[40]; text[0]='\0';
    sprintf(text,"%d  %s  %s",k1,ClassName[1],pOp[0]->text());
    lbx1->UpdateRow(k1,text);
}

void Desk::sidSub(){//сравнение
    int k,k1=0;
    Identifier *pOp[2];
    char op[2][6] = {"op1 ?","op2 ?"};
    for(int i=0;i<2;i++){
        k = numInput(520,170,25,25,op[i]); if(!k1) k1=k;
        if(k<=0||k>count){ if(dataError(520,170,25,25)) return; }
        if(inst[k-1].classId!=1) { Msg(520,170,25,25,"Wrong data"); return; }
        pOp[i] = (Identifier*)inst[k-1].item;
    }
    *pOp[0] < *pOp[1];
    char text[40]; text[0]='\0';
    sprintf(text,"%d  %s  %s",k1,ClassName[1],pOp[0]->text());
    lbx1->UpdateRow(k1,text);
}

 void Desk::Ind()  //индексное выражение
 {
    int k,k1=0;
    Identifier *pOp[3];
    char op[1][6] = {"op1 ?"};
    for(int i=0;i<1;i++){
        k = numInput(520,170,25,25,op[i]); if(!k1) k1=k;
        if(k<=0||k>count){ if(dataError(520,170,25,25)) return; }
        if(inst[k-1].classId!=1) { Msg(520,170,25,25,"Wrong data"); return; }
        pOp[0] = (Identifier*)inst[k-1].item;
        char *id=new char[5];
        strInput(520,170,25,25,"Index",id,2);
        int idx;
        if (!str2int(id,idx)) {
            Msg(520,170,25,25,"Wrong data");
            delete id;
            break;
        }
        delete id;
        char text[40],out[20]; text[0]='\0';
        idx--;
        sprintf(out,"Return value is %c",(*(Identifier*)pOp[0])[idx]);
        sprintf(text,"%d  %s  %s",k,ClassName[2],pOp[0]->text());
        lbx1->UpdateRow(k1,out);
        getch();
        lbx1->UpdateRow(k1,text);
    }
}

void Desk::sbtInd(){//удаление
int k,k1=0;
    Combine *pOp[3];
    char op[3][6] = {"op1 ?","op2 ?","op3 ?"};
    for(int i=0;i<3;i++){
        k = numInput(520,210,25,25,op[i]); if(!k1) k1=k;
        if(k<=0||k>count){ if(dataError(520,210,25,25)) return; }
        if(inst[k-1].classId!=2) { Msg(520,210,25,25,"Wrong data"); return; }
        pOp[i] = (Combine*)inst[k-1].item;
    }
    *pOp[0] = *pOp[1] - *pOp[2];
    char text[40]; text[0]='\0';
    sprintf(text,"%d  %s  %s",k1,ClassName[2],pOp[0]->text());
    lbx1->UpdateRow(k1,text);
}


void Desk::sbtMulti(){//умножение
int k,k1=0;
    Combine *pOp[3];
    char op[3][6] = {"op1 ?","op2 ?","op3 ?"};
    for(int i=0;i<3;i++){
        k = numInput(520,210,25,25,op[i]); if(!k1) k1=k;
        if(k<=0||k>count){ if(dataError(520,210,25,25)) return; }
        if(inst[k-1].classId!=2) { Msg(520,210,25,25,"Wrong data"); return; }
        pOp[i] = (Combine*)inst[k-1].item;
    }
    *pOp[0] = *pOp[1] * *pOp[2];
    char text[40]; text[0]='\0';
    sprintf(text,"%d  %s  %s",k1,ClassName[2],pOp[0]->text());
    lbx1->UpdateRow(k1,text);
}

void Desk::sbtAssign(){//присваивание
    int k,k1=0;
    Combine *pOp[2];
    char op[2][6] = {"op1 ?","op2 ?"};
    for(int i=0;i<2;i++){
        k = numInput(520,185,25,25,op[i]); if(!k1) k1=k;
        if(k<=0||k>count){ if(dataError(520,185,25,25)) return; }
        if(inst[k-1].classId!=2) { Msg(520,185,25,25,"Wrong data"); return; }
        pOp[i] = (Combine*)inst[k-1].item;
    }
    *pOp[0] = *pOp[1];
    char text[40]; text[0]='\0';
    sprintf(text,"%d  %s  %s",k1,ClassName[2],pOp[0]->text());
    lbx1->UpdateRow(k1,text);
}

void Desk::sbtSub(){//сравнение
    int k,k1=0;
    Combine *pOp[2];
    char op[2][6] = {"op1 ?","op2 ?"};
    for(int i=0;i<2;i++){
        k = numInput(520,210,25,25,op[i]); if(!k1) k1=k;
        if(k<=0||k>count){ if(dataError(520,210,25,25)) return; }
        if(inst[k-1].classId!=2) { Msg(520,210,25,25,"Wrong data"); return; }
        pOp[i] = (Combine*)inst[k-1].item;
    }
    *pOp[0] == *pOp[1];
    char text[40]; text[0]='\0';
    sprintf(text,"%d  %s  %s",k1,ClassName[2],pOp[0]->text());
    lbx1->UpdateRow(k1,text);
}


void Desk::numResult(int x,int y,int w,int h,char *s,int k){ // результат
    int len = strlen(s)+5;
    char *text = new char[len];
    if(k<=99) sprintf(text,"%s= %d",s,k);
    else sprintf(text,"%s= xxx",s);
    int wt = textwidth(text);
    int ht = textheight(text);
    w+=wt;
    outtextxy(x+(w-wt)/2,y+(h-ht)/2,text);
    getch();
    bar(x,y,x+w+1,y+h+1);
}

int Desk::dataError(int x,int y,int w,int h){ //ошибка
    char text[]="Data Error";
    int wt = textwidth(text);
    int ht = textheight(text);
    w+=wt;
    int color = getcolor();
    setcolor(RED);
    rectangle(x,y,x+w,y+h);
    outtextxy(x+(w-wt)/2,y+(h-ht)/2,text);
    setcolor(color);
    char ch;
    do ch=getch();
    while(ch!=13&&ch!=27);
    bar(x,y,x+w+1,y+h+1);
    return (ch=27)?1:0;
}

void Desk::Msg(int x,int y,int w,int h,char *s){//собщение
    int wt = textwidth(s);
    int ht = textheight(s);
    w+=wt;
    outtextxy(x+(w-wt)/2,y+(h-ht)/2,s);
    getch();
    bar(x,y,x+w+1,y+h+1);
}
int Desk::str2int(char *str,int &result)//перевод в число
{
    char correct=1,minus=0;
    int  res=0,i=0;
    if (str[0] == '-') {
        minus = 1;
        i = 1;
    }
    if (str[i] == 0) {
        return 0;
    }
    while(correct&&(str[i]!=0)) {
        if ((str[i] >= 0x30)&&(str[i] <= 0x39)) {
            res = res*10 + (str[i] - 0x30);
        } else {
            correct = 0;
        }
        i++;
    }
    if (correct) {
        result = (minus)?(-res):(res);
        return 1;
    } else {
        return 0;
    }
}
int Desk::numInput(int x, int y, int w, int h, char *prompt){//число
    int ht, wt;
    char text[2];
    setbkcolor(BLUE);
    wt = textwidth(prompt);
    ht = textheight(prompt);
    w+=wt;
    outtextxy(x+(w-wt)/2,y+(h-ht)/2,prompt);
    text[0] = getch(); text[1]='\0';
    bar(x,y,x+w+1,y+h+1);
    wt = textwidth(text);
    ht = textheight(text);
    outtextxy(x+(w-wt)/2,y+(h-ht)/2,text);
    while(getch()!=13);
    bar(x,y,x+w+1,y+h+1);
    if(text[0]>=48&&text[0]<=57) return text[0]-48;
    return 0;
}

void Desk::strInput(int x, int y, int w, int h, char *prompt, char *text, int limit){//строка
    int ht, wt;
    setbkcolor(BLUE);
    wt = textwidth(prompt);
    ht = textheight(prompt);
    w+=wt;
    outtextxy(x+(w-wt)/2,y+(h-ht)/2,prompt);
    int i=0;
    text[0]='\0';
    while(((text[i++]=getch())!=13)&&(i<=limit)){
        text[i]='\0';
        bar(x,y,x+w+1,y+h+1);
        w-=wt;
        wt = textwidth(text);
        ht = textheight(text);
        w+=wt;
        outtextxy(x+(w-wt)/2,y+(h-ht)/2,text);
    }
    text[i-1]='\0';
    bar(x,y,x+w+1,y+h+1);
}

void Desk::PaintBg(){ //окно
    setfillstyle(1,1);
    bar(0,0,640,480);
    setcolor(11);
    rectangle(5,5,635,475);
}

void Desk::Go(){//команды
    unsigned char ch;
    for(;;){
        ch = getch();
        switch(ch){
        case 13: Command(); break;
        case 72: mn.Upward(); break;
        case 75: mn.Backward(); break;
        case 77: mn.Forward(); break;
        case 80: mn.Downward(); break;
        case 27: exit(0);
        }
    }
}

void Desk::Command(void){ //команды
     lbx2->Clear();
     Menu *smn = mn.getSubMenu(mn.getSelected());
     Menu *smn1 = NULL;
     if(smn) smn1 = smn->getSubMenu(smn->getSelected());
     switch(mn.getSelected()){
         case 0: if(smn){
                     switch(smn->getSelected()){
                         case -1: smn->Show(); break;
                         case 0: setCount(); break;
                         case 1: Init(); break;

                     }
                 }
                 break;
         case 1: if(smn){
                     switch(smn->getSelected()){
                         case -1: smn->Show(); break;
                         case 0: if(smn1){
                                     switch(smn1->getSelected()){
                                         case -1: smn1->Show(); break;
                                         case 0: strclear(); break;
                                     }
                                 }
                                 break;
                         case 1: if(smn1){
                                     switch(smn1->getSelected()){
                                         case -1: smn1->Show(); break;
                                         case 0: sidToUpper(); break;
                                         case 1: sidAssign(); break;
                                         case 2: sidSub(); break;
                                         case 3: Ind();break;
                                        }
                                    }
                                    break;
                         case 2: if(smn1){
                                     switch(smn1->getSelected()){
                                         case -1: smn1->Show(); break;
                                         case 0: sbtMulti(); break;
                                         case 1: sbtAssign(); break;
                                         case 2: sbtSub(); break;
                                         case 3: sbtInd();break;
                                     }
                                 }
                                 break;
                         case 3: break;
                     }
                 }
                 break;
         case 2: exit(0);
     }
}
