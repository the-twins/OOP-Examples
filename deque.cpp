#include <iostream>

using namespace std;

class DequeItem {
    public:
        int value;
        DequeItem * next;
        DequeItem * prev;
        
    public:
        DequeItem(int numb)
        {
            value = numb;
            next = NULL;
            prev = NULL;
        }
};

class Deque {
        DequeItem * first;
        DequeItem * last;
        unsigned int count;
        
    public:
        Deque()
        {
            first = NULL;
            last = NULL;
            count = 0;
        }
        
        ~Deque()
        {
            cout << "Calling destructor" << endl;
            DequeItem * item = first;
            DequeItem * temp_item;
            while(item != NULL)
            {
                temp_item = item->next;
                delete item;
                item = temp_item;
            }
        }
         
        void add(int n)
        {   
            DequeItem * fresh = new DequeItem(n);
            if(first == NULL)
                first = fresh;
            else
            {
                last->next = fresh;;
                fresh->prev = last;
            }
            last = fresh;
            count++;
            cout << "Add: " << n << endl; 
        }
        
        void add_left(int n)
        {
            DequeItem * fresh = new DequeItem(n);
            if(first == NULL)
                last = fresh;
            else
            {
                fresh->next = first;
                first->prev = fresh;
            }
            first = fresh;
            count++;
            cout << "Add: " << n << endl; 
        }
        
        int pop()
        {
            if (!count)
                throw "Queue is empty.";
            DequeItem * item = last;
            int value = item->value;
            if(count == 1)
                first = last = NULL;
            else
                last = item->prev;
            delete item;
            count--;                
            return value;
        }
            
        int pop_left()
            {
                if (!count)
                    throw "Queue is empty.";
                DequeItem * item = first;
                int value = item->value;
                if(count == 1)
                    first = last = NULL;
                else
                    first = item->next;
                delete item;
                first->prev = NULL;
                count--;                
                return value;
            }

            unsigned int get_count()
            {
                return count;
            }
            
            void print()
            {
                DequeItem * item = first;
                while(item != NULL)
                {
                    cout << item->value << " ";
                    item = item->next;
                }
                cout << endl;
            }
            
            void print_back()
        {
            DequeItem * item = last;
            while(item != NULL)
            {
                cout << item->value << " ";
                item = item->prev;
            }
            cout << endl;
        }
};

void test_deque()
{
    Deque deque;
    deque.add(1);
    deque.add(2);
    cout << "Total " << deque.get_count() << endl;
    deque.add_left(3);
    deque.add_left(4);
    cout << "Total " << deque.get_count() << endl;
    deque.print();
    deque.print_back();
    cout << "Deleted: " << deque.pop() << endl;
    cout << "Total " << deque.get_count() << endl;
    cout << "Deleted: " << deque.pop_left() << endl;
    deque.add(20);
    deque.print();
    deque.print_back();
    cout << "Total " << deque.get_count() << endl;
    cout << "Deleted: " << deque.pop_left() << endl;
    cout << "Deleted: " << deque.pop_left() << endl;
    cout << "Total " << deque.get_count() << endl;
}

int main()
{
    try
    {
        test_deque();
    }
    catch (const char* exp)
    {
        cout << exp << endl;
        return 1;
    }
    return 0;
}
