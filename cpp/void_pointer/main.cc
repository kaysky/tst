/*
an exemple of work with (void*) pointer
two  f-ns save and get information at some global buffer

*/

#include <iostream>
using std::cout;
using std::endl;

static char buff[1024];

struct proto
{
	int a;
	int b;
	int c;
	void  show_data()
	{
		cout << "==> a/b/c : " << a << "/" << b << "/" << c << endl;
	}
};

void reciver(void *p)
{
	proto *prt = (proto*)p;
	prt->show_data();
}

void sender(void *p, int a, int b, int c)
{
	proto * prt = (proto*)p;
	prt->a = a;
	prt->b = b;
	prt->c = c;
}

 
int main()
{
//=====================================
	void *p = &buff[0];
	sender(p,10,20,30);
	reciver(p);
//=====================================
    int b=7;
    int* ptr_b=&b;
    cout <<*ptr_b<<endl;
 
    void* a;
    a=ptr_b;
    //cout <<*a<<endl;//owibka: void ne type ykazatel9 na ob6ekt
     
    //chtobu izvlech dannue nyjno cdelat6 preobrazovani9
    int* a_preobr=static_cast<int*>(a);
     
    cout <<*a_preobr<<endl;
     
    //либо в короткой записи
    cout <<*(int*)a<<endl;
     
    //указателю на воид можно присвоить любой указатель
    char c[]="hellow world gacpada";
    a=c;
    cout <<(char*)a<<endl;
     
    return 0;
}
