#include <iostream>
#include <string>
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


class Reqtangle : public Ancestor
{
protected:
    int length;
    int width;

public:
    Reqtangle()
    {
        length = 0;
        width = 0;
    }

    Reqtangle(int req_length, int req_width)
    {
        this->length = req_length;
        this->width = req_width;
    }

    Reqtangle(Reqtangle& obj)
    {
        length = obj.length;
        width = obj.width;
    }

    ~Reqtangle() override
    {
    }

    void draw() override
    {
        grean("draw()");
    }

    void area(int length, int width) override
    {
        string area = to_string((length * width));
        grean("area = " + area);
    }
};


int main()
{
    return 0;
}

