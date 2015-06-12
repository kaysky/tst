#include <iostream>
#include <cstdlib>

using namespace std;

const unsigned int N = 8;   //quantity of elements in an array
static int globBuff[1024];
static unsigned int Q = 0;  // variable to count and control memory leaking

/*
    F-n prints all items of an array
*/
void print(int *a, const unsigned int n, const char *str)
{
    cout << str;
//    printf("%s",str);
    for(int i = 0; i < n; ++i)
        cout << a[i] << "  ";
    cout << endl;
}

//original function
int* GetSomeIDs()
{
    int  ids[N];
    /* The ids are defined here */
    for(int i = 0; i < N; ++i)
    {
        ids[i] = i*10;

    }
    print(ids,N,"GetSomeIDs => ");
    return  ids;
}

/*
    original function changed to better practice
    NOTE: that 'buff' should be big enough to get all length of ids[]
    it is not the best practice but better than last one
    for better practice I would use safe - arrays or class-wrapper
*/
int* GetSomeSafeIDs(int* buff, const unsigned int n)
{
    //    int  ids[N];
    int  *ids = buff;
    // some ids stuff
    for(int i = 0; i < n; ++i)
    {
        ids[i] = i*10;

    }
    print(ids,N,"GetSomeSafeIDs => ");
    return  ids;
}

void incAlg(int &el)
{

    el += 1;
}

void decAlg(int &el)
{

    el -= 1;
}


void invAlg(int &el)
{

    el = -el;
}

/*
    F-n  changes each element of an array
    1-st parameter is a pointer to global buffer
    2-nd parameter is a number of our array
    3-d parameter is a pointer to algorithm - function
    NOTE: we can use different algorithms to modify each elements of array
    but prototype can be only void FunName(int &)
*/

void arrayModefier(int *buff, const unsigned int n, void (*pf)(int &))
{
    for(int i = 0; i < n; ++i)
    {
        pf(buff[i]);
    }
}

/*
    local structure to create  of doubly-linked list
*/
struct lst
{
    lst *next;
    lst *prev;
    int data;

};


/*
    wrapper to count allocated object
*/
lst* make_lst(void)
{
    ++Q;
    lst *tmp = (lst*)malloc(sizeof(lst));
    if (tmp) return tmp;
    else return NULL;
}

/*
    wrapper to count deleted object
*/
void free_lst(lst* ls)
{
    --Q;
    if(ls) free(ls);
}

/*
    F-n converts array buffer to doubly-linked list
    1st parameter is pointer to array
    2nd parameter is a number of elements in an array
    F-n returns pointer to the first element of list
    NOTE: F-n allocates memory sizeof(lst)*n size
          don't forget to use eraser() - f-n to free
          all allocated memmory
*/
lst* arrayConverter(int *buff, const unsigned int n)
{
    lst *first = make_lst();
    lst *current = NULL;
    lst *next = NULL;

    if(buff && first)
    {
        first->data = buff[0];
        first->prev = NULL;
        current = first;
    }
    else return NULL;

    for(int i = 1; i < n; ++i)
    {
        next = make_lst();
        if(next)
        {
            next->data = buff[i];
            next->prev = current;
            current->next = next;
            current = next;
        }
    }

    return first;
}

/*
    1st parameter is a pointer to the first element of list
    F-n frees all allocated memory with arrayConverter
*/
void eraser(lst *begin)
{
    while(begin)
    {
        lst *tmp = begin->next;
        if(begin)
            free_lst(begin);
        begin = tmp;
    }
}


/*
    F-n prints all items of list
*/
void printArray(lst *begin, const char *str )
{
    cout << str;
    while(begin)
    {
        cout << begin->data << "  ";
        begin = begin->next;
    }
    cout << endl;
}


int main()
{
    cout << "Tests jtests ..." << endl;
    cout << "Q:" << Q << endl;

    int  *someIDs;
    int  *r;
    int  theFirst;

    cout << "job of unsafe function" << endl;
    someIDs = GetSomeIDs();
    cout << someIDs << " contain :" << *someIDs << endl;
    theFirst = someIDs[0];
    cout << "theFirst contain :" << theFirst << endl;
    print(someIDs, N, "someIDs : ");

    cout << "job of safe function" << endl;
    someIDs = GetSomeSafeIDs(globBuff, N);
    cout << someIDs << " contain :" << *someIDs << endl;
    print(someIDs, N, "someIDs : ");

    cout << "job of arrayModefier function" << endl;
    arrayModefier(globBuff, N, &incAlg);
    print(globBuff,N,"buff contains after increase-alg : ");

    arrayModefier(globBuff, N, &invAlg);
    print(globBuff,N,"buff contains after invert-alg : ");

    lst *arrayList = NULL;
    cout << "job of arrayConverter function" << endl;
    arrayList = arrayConverter(globBuff, N);
    printArray(arrayList, "list contains : ");
    eraser(arrayList);

    cout << "Q:" << Q << endl;

    return 0;
}







