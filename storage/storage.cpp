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


class Rectangle : public Ancestor
{
protected:
    int length;
    int width;

public:
    Rectangle()
    {
        length = 0;
        width = 0;
    }

    Rectangle(int req_length, int req_width)
    {
        this->length = req_length;
        this->width = req_width;
    }

    Rectangle(const Rectangle& obj)
    {
        length = obj.length;
        width = obj.width;
    }

    ~Rectangle() override
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


class RoundedRectangle : public Rectangle
{
protected:
    int radus;

public:
    RoundedRectangle() : Rectangle()
    {
        radus = 0;
    }

    RoundedRectangle(int req_length, int req_width, int req_radus) : Rectangle(req_length, req_width)
    {
        this->radus = req_radus;
    }

    RoundedRectangle(const RoundedRectangle& obj)
    {
        length = obj.length;
        width = obj.width;
        radus = obj.radus;
    }

    ~RoundedRectangle()
    {
    }

    void changeRadus(int new_radus)
    {
        radus = new_radus;
    }
};


class Storage
{
private:
    Ancestor** objects;
    int size;

public:
    Storage(int size)
    {
        this->size = size;
        objects = new Ancestor * [size];
    }

    ~Storage()
    {
        delete[] objects;
        printf("delete\n");
    }

    void setObject(int i, Ancestor* object)
    {
        objects[i] = object;
    }

    int getCount()
    {
        return size;
    }

    void nullObject(int i)
    {
        objects[i] = NULL;
    }

    Ancestor& getObject(int i)
    {
        return *objects[i];
    }

};


int main()
{
    return 0;
}

