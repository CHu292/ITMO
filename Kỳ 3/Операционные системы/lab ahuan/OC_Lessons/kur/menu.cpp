#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<graphics.h>
#include "menu.h"

MenuItem::MenuItem(){
    status = 0;
    x = 0; y = 0; w = 120; h = 30;
    strcpy(text,"Item");
    Show();
}

MenuItem::MenuItem(int xx,int yy,int ww,int hh, char *s){
    status = 0;
    x = xx; y = yy; w = ww; h = hh;
    strncpy(text,s,16);
    Show();
}

void MenuItem::setStatus(int k){
    status = k;
    Show();
}

int MenuItem::getStatus(){
    return status;
}

void MenuItem::Show(void){
    rectangle(x,y,x+w,y+h);
    int clr = getcolor();
    if(status > 0) setcolor(RED);
    else if(status==0) setcolor(LIGHTGREEN);
    else setcolor(LIGHTGRAY);
    setbkcolor(BLUE);
    int wt = textwidth(text);
    int ht = textheight(text);
    outtextxy(x+(w-wt)/2,y+(h-ht)/2,text);
    setcolor(clr);
}

void MenuItem::Hide(void){
     if(status==1) status = 0;
     int clr = getcolor();
     setcolor(BLUE);
     bar(x,y,x+w+1,y+h+1);
     setcolor(clr);
}

Menu::Menu(){
    n=0;
    selected=-1;
    visible = 1;
    supmenu = NULL;
    for(int i=0;i<10;i++){
        mItem[i].item = NULL;
        mItem[i].submenu = NULL;
        mItem[i].enabled = 1;
    }
}

Menu::Menu(Menu *mn, int k){
    n=0;
    selected=-1;
    visible = 1;
    supmenu = mn;
    for(int i=0;i<10;i++){
        mItem[i].item = NULL;
        mItem[i].submenu = NULL;
        mItem[i].enabled = 1;
    }
    mn->setSubMenu(k,this);
}

Menu::~Menu(){
    while(n>=0) delete mItem[--n].item;
}

int Menu::isEnable(int k){
    return mItem[k].item->getStatus() >= 0;
}

void Menu::Add(int x,int y,int w,int h,char *s){
    mItem[n++].item = new MenuItem(x,y,w,h,s);
    return;
}

void Menu::setSubmenu(Menu *mn,int k){
    if(k>=0&&k<n) mItem[k].submenu = mn;
    mn->supmenu = this;
}

void Menu::Show(void){
     for(int i=0;i<n;i++) mItem[i].item->Show();
     visible = 1;
}

void Menu::Hide(void){
     Menu *smn = NULL;
     if(selected >=0) smn = mItem[selected].submenu;
     if(smn) smn->Hide();
     for(int i=0;i<n;i++) mItem[i].item->Hide();
     selected = -1;
     visible = 0;
}

void Menu::setSelect(int k){
    if(mItem[k].enabled){
        mItem[k].item->setStatus(1);
        if(selected >=0) mItem[selected].item->setStatus(0);
        selected = k;
    }
}

void Menu::setEnable(int k){
    if(k!=selected) mItem[k].item->setStatus(0);
    mItem[k].enabled = 1;
    Show();
}

void Menu::setDisable(int k){
    if(k!=selected) mItem[k].item->setStatus(-1);
    mItem[k].enabled = 0;
    Show();
}

void Menu::Forward(void){
    Menu *smn = NULL;
    int i;
    for(i=selected+1;i<n;i++) if(mItem[i].enabled) break;
    if(i<=n-1){
        mItem[i].item->setStatus(1);
        if(selected>=0){
            mItem[selected].item->setStatus(0);
            smn = mItem[selected].submenu;
        }
        if(smn) { /*smn->selected = -1*/; smn->Hide(); }
        selected = i;
    }
}

void Menu::Backward(void){
    int i;
    for(i=selected-1;i>=0;i--) if(mItem[i].enabled) break;
    if(i>=0){
        mItem[i].item->setStatus(1);
        mItem[selected].item->setStatus(0);
        Menu *smn = mItem[selected].submenu;
        if(smn) { /*smn->selected = -1*/; smn->Hide(); }
        selected = i;
    } else if(supmenu) {
        selected = -1;
        Hide();
    }
}

void Menu::Upward(void){
    Menu *mn = this, *mn1 = NULL;
    while(mn->selected >=0 && (mn1=mn->mItem[mn->selected].submenu) && mn1->visible) mn = mn1;
    mn->Backward();
}

void Menu::Downward(void){
    Menu *mn = this, *mn1 = NULL;
    while(mn->selected >=0 && (mn1=mn->mItem[mn->selected].submenu) && mn1->visible) mn = mn1;
    mn->Forward();
}

void Menu::setSubMenu(int i, Menu *mn){
    if(i>=0&&i<n) mItem[i].submenu = mn;
}

Menu *Menu::getSubMenu(int i){
    if(i>=0&&i<n) return mItem[i].submenu;
    return NULL;
}

int Menu::getSelected(void){
    return selected;
}
