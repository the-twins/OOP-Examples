#include <iostream>

using namespace std;

class ListItem {
    public:
        int value;
        ListItem * next;
    
    public:
        ListItem(int number)
        {
            value = number;
            next = NULL;
        }
};          

class List {
    ListItem * first;
    ListItem * last;

    public:
        List()
        {
            first = NULL;
            last = NULL;
        }
        
        void add(int n)
        {
            ListItem * freash = new ListItem(n);
            if(first == NULL)
                first = freash;
            else
                last->next = freash;
            last = freash;
        }
        
        void print()
        {
            ListItem * item = first;
            while(item != NULL)
            {
                cout << item->value << " ";
                item = item->next;
            }
            cout << endl;
        }
};

int main()
{
    List list;
    list.print();
    list.add(3);
    list.add(2);
    list.add(1);
    list.print();
    
    return 0;
}
