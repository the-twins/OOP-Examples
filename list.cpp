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
    unsigned int count;

    public:
        List()
        {
            first = NULL;
            last = NULL;
            count = 0;
        }
        
        void add(int n)
        {
            ListItem * freash = new ListItem(n);
            if(first == NULL)
                first = freash;
            else
                last->next = freash;
            last = freash;
            count++;
        }
        
        ~List()
        {
            cout << "Calling destructor" << endl;
            ListItem * item = first;
            ListItem * temp_item;
            while(item != NULL)
            {
                temp_item = item->next;
                delete item;
                item = temp_item;
            }
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
        
        unsigned int get_count()
        {
            return count;
        }
        
        bool find(int n)
        {
            ListItem * item = first;
            while(item != NULL)
            {
                if(item->value == n)
                    return true;
                item = item->next;
            }
            return false;
        }
        
        void del_item(int n)
        {
            ListItem * item = first;
            ListItem * prev = NULL;
            while(item != NULL)
            {
                if(item->value == n)
                {
                    if(item == first)
                        first = item->next;
                    else
                        prev->next = item->next;
                    if(item == last)
                        last = prev;
                    delete item;
                    count--;
                    return;
                }
                prev = item;
                item = item->next;
            }
        }
};

int main()
{
    List list;
    list.print();
    cout << list.get_count() << endl;
    list.add(3);
    list.add(2);
    list.add(1);
    list.add(5);
    list.print();
    cout << list.get_count() << endl;
    cout << "Enter number to find: ";
    int num;
    cin >> num;
    if(list.find(num) == true)
        cout << "Found." << endl;
    if(list.find(num) == false)
        cout << "Not found." << endl;
    cout << "Enter number to delete: ";
    int del_num;
    cin >> del_num;
    list.del_item(del_num);
    list.print();
    cout << list.get_count() << endl;
    
    return 0;
}
