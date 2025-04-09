#include <iostream>
#include <math.h>

using namespace std;

// Point - class
// p - object
// x, y, print, move - members (члены)
// x, y, - attributes (атрибуты, поля)
// print, move - methods
// members: private and public
// public members - interface
class Point {
    private:
        float x;
        float y;
    
    public:
        Point(float init_x, float init_y) // constructor
        {
            x = init_x;
            y = init_y;            
        }        
    
        void print()
        {
            cout << "(" << x << ", " << y << ")" << endl;
        }

        void move(float angle, float distance)
        {
            x = x + distance * cos(angle);
            y = y + distance * sin(angle);
        }
};

int main(void)
{
    Point p(4, 3);  
    p.print();
    p.move(0.785398, 1.42);
    p.print();
    
    return 0;
}