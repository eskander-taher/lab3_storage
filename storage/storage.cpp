#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;
//functions for styling
void  highlight(string s);
void  yellow(string s);
void  grean(string s);
#include <iostream>


class Ancestor
{
public:
    virtual ~Ancestor()
    {
        grean("~Ancestor()");
    }

    virtual void draw() = 0;

    virtual void area(int x, int y) = 0;
};


int main()
{
    return 0;
}

