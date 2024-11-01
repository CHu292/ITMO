#include<cstdlib>
#include<cstdio>
#include<graphics.h>
#include "listbox.h"

ListItem::ListItem(){
    x = 0; y = 0; w = 100; h = LINE_HEIGHT;
    strcpy(text,"");
    lbx = NULL;
}

ListItem::ListItem(int xx,int yy,int ww,int hh,char *s){
    x = xx; y = yy; w = ww; h = hh;
    strncpy(text,s,STR_LEN-1);
    text[STR_LEN] = '\0';
    lbx = NULL;
    Show();
}

ListItem::~ListItem(){
    Erase();
}

void ListItem::setText(char *s){
    strncpy(text,s,STR_LEN+1);
    if(strlen(s)>STR_LEN) text[STR_LEN+1] = '\0';
}

void ListItem::Show(){
    Erase();
    int clr = getcolor();
    setcolor(BLUE);
    rectangle(x,y,x+w,y+h);
    setcolor(clr);
    setbkcolor(BLUE);
    int ht = textheight(text);
    outtextxy(x+5,y+(h-ht)/2,text);
}

void ListItem::Erase(){
     //int clr = getcolor();
     //setcolor(BLUE);
     bar(x,y,x+w-1,y+h);
     //setcolor(clr);
}

ListBox::ListBox(){ //puts("ListBox()");
    x = 0; y = 0; w = 200; h = 100;
    n = 0;
    for(int i=0;i<STR_MAX;i++) lItem[i] = NULL;
    Show();
}

ListBox::ListBox(int xx,int yy,int ww,int hh){
    char s[STR_LEN];
    x = xx; y = yy; w = ww; h = hh;
    n = 0;
    Show();
}

ListBox::~ListBox(){ //puts("~ListBox()");
    for(int i=0;i<n;i++) if(lItem[i]) delete lItem[i];
}

void ListBox::Add(char *s){
    if(n<8){
        lItem[n] = new ListItem(x+1, y+n*LINE_HEIGHT+1, w, LINE_HEIGHT,s);
        n++;
    }
}

void ListBox::AddSeveral(int k){
    char s[1];
    if(k>=0&&k<=STR_MAX){
        for(int i=0;i<k;i++) {
            int j = i;
            sprintf(s,"%d",j+1);
            lItem[i] = new ListItem(x+1, y+i*LINE_HEIGHT+1, w, LINE_HEIGHT,s);
            n++;
        }
    }
}

void ListBox::UpdateRow(int k, char *text){ //printf("%d\t%s\n",k,text);
    lItem[--k]->setText(text);
    lItem[k]->Show();
}

void ListBox::Clear(){
    for(int i=0;i<n;i++) delete lItem[i];
    n=0;
}

void ListBox::Erase(){
    for(int i=0;i<n;i++) lItem[i]->Erase();
}

void ListBox::Show(){
    rectangle(x,y,x+w,y+h);
}

void ListBox::Count(){
    printf("n=%d\n",n);
}

