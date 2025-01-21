#include <iostream>

using namespace std;

class QueueItem {
    public:
        int value;
        QueueItem * next;
        
    public:
        QueueItem(int n)
        {
            value = n;
            next = NULL;
        }
};
        
class Queue {
        QueueItem * first;
        QueueItem * last;
        unsigned int count;
        
        public:
            Queue()
            {
                first = NULL;
                last = NULL;
                count = 0;
            }

            void enqueue(int numb)
            {
                QueueItem * freash = new QueueItem(numb);
                if(first == NULL)
                    first = freash;
                else
                    last->next = freash;
                last = freash;
                count++;
            }
            
            ~Queue()
            {
                cout << "Calling destructor" << endl;
                QueueItem * item = first;
                QueueItem * temp_item;
                while(item != NULL)
                {
                    temp_item = item->next;
                    delete item;
                    item = temp_item;
                }
            }

            int dequeue()
            {
                QueueItem * item = first;
                int value = 0;
                value = item->value;
                if(count == 1)
                    first = last = NULL;
                if(count == 2)
                {
                    first = item->next;
                    last = NULL;
                }
                else
                    first = item->next;
                delete item;
                count--;
                
                return value;
            }

            unsigned int get_count()
            {
                return count;
            }
            
            int peek()
            {
                QueueItem * item = first;
                return item->value;
            }
};

int main()
{
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    cout << "Total " << queue.get_count() << endl;
    queue.enqueue(3);
    queue.enqueue(4);
    cout << "Total " << queue.get_count() << endl;
    cout << "Deleted: " << queue.dequeue() << endl;
    cout << "Total " << queue.get_count() << endl;
    cout << queue.peek() << endl;
    queue.enqueue(20);
    cout << "Total " << queue.get_count() << endl;
    cout << "Deleted: " << queue.dequeue() << endl;
    cout << "Deleted: " << queue.dequeue() << endl;
    cout << "Deleted: " << queue.dequeue() << endl;
    cout << queue.peek() << endl;
    
    
    return 0;
}
