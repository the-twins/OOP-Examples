#include <iostream>

using namespace std;

class StackItem
{
    public:
        int value;
        StackItem * next;
    public:
        StackItem(int n)
        {
            value = n;
            next = NULL;
        }
};
class Stack
{
    StackItem * first;
    unsigned int count;
    
    public:
        Stack()
        {
            first = NULL;
            count = 0;
        }
        ~Stack()
        {
            cout << "Calling destructor" << endl;
            StackItem * item = first;
            StackItem * temp_item;
            while(item != NULL)
            {
                temp_item = item->next;
                delete item;
                item = temp_item;
            }
        }
        void push(int numb)
        {
            StackItem * fresh = new StackItem(numb);
            if(first == NULL)
                first = fresh;
            else
            {
                fresh->next = first;
                first = fresh;
            }
            count++;
        }
        
        int pop()
        {
            if (!count)
                throw "Queue is empty.";
            StackItem * item = first;
            int number = item->value;
            if(count == 1)
            {
                delete item;
                first = NULL;
            }
            else
            {
                first = item->next;
                delete item;
            }
            count--;
            return number;
        }
        
        unsigned int get_count()
        {
            return count;
        }
        
        void print()
        {
            StackItem * item = first;
            while(item != NULL)
            {
                cout << item->value << " ";
                item = item->next;
            }
            cout << endl;
        }
};
        
void test_stack()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << "Total " << stack.get_count() << endl;
    stack.print();
    cout << "Deleted: " << stack.pop() << endl;
    cout << "Total " << stack.get_count() << endl;
    cout << "Deleted: " << stack.pop() << endl;
    cout << "Total " << stack.get_count() << endl;
    stack.print();
    stack.push(1);
    cout << "Deleted: " << stack.pop() << endl;
    cout << "Total " << stack.get_count() << endl;
    stack.print();
}

int main()
{
    try
    {
        test_stack();
    }
    catch (const char* exp)
    {
        cout << exp << endl;
        return 1;
    }
    return 0;
}
