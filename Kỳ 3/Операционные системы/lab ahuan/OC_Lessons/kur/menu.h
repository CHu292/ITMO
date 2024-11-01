#ifndef MENU_H
#define MENU_H

class MenuItem{
private:
    int status;
    int x, y, w, h;
    char text[16];

public:
    MenuItem();
    MenuItem(int,int,int,int, char *);
    void Show(void);
    void Hide(void);
    void setStatus(int);
    int getStatus(void);
    ~MenuItem(){}
};

class Menu;

struct MItem{
    MenuItem *item;
    bool enabled;
    Menu *submenu;
};

class Menu{
private:
    Menu *supmenu;
    MItem mItem[10];
    int n;
    int selected;
    bool visible;

public:
    Menu();
    Menu(Menu *, int);
    ~Menu();
    void Add(int,int,int,int,char *);
    void setSubmenu(Menu *,int);
    void Show(void);
    void Hide(void);
    void setSelect(int);
    int getSelected(void);
    void setEnable(int);
    int isEnable(int);
    void setDisable(int);
    void Forward(void);
    void Backward(void);
    void Upward(void);
    void Downward(void);
    void setSubMenu(int, Menu *);
    Menu *getSubMenu(int);
};

#endif /* MENU_H */
