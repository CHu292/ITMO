#ifndef LISTBOX_H
#define LISTBOX_H

#ifndef STR_MAX
  #define STR_MAX 255
#endif
#define STR_LEN 79
#define LINE_HEIGHT 20

class ListBox;

class ListItem {
private:
    int x, y, w, h;
    ListBox *lbx;
public:
    char text[STR_LEN+1];
    ListItem(void);
    ListItem(int,int,int,int,char *);
    ~ListItem(void);
    void setText(char *);
    void Show(void);
    void Erase(void);
};

class ListBox {
private:
    int x, y, w, h;
    int n;
    ListItem *lItem[STR_MAX];

public:
    ListBox(void);
    ListBox(int,int,int,int);
    ~ListBox(void);
    void Add(char *);
    void AddSeveral(int);
    void UpdateRow(int,char *);
    void Clear(void);
    void Show(void);
    void Erase(void);
    void Count(void);
};

#endif /* LISTBOX_H */
