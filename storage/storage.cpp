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


    void addObjects(int index, Ancestor* object)
    {
        size = index + 1;
        Ancestor** new_objects = new Ancestor * [size];

        for (int i = 0; i < index; i++)
            new_objects[i] = objects[i];

        delete[] objects;

        objects = new_objects;

        objects[index] = object;
    }

    void deleteObject(int index)
    {
        size--;

        Ancestor** new_objects = new Ancestor * [size];

        for (int i = 0; i < index; i++)
        {
            new_objects[i] = objects[i];
        }

        for (int i = index; i < size; i++)
        {
            new_objects[i] = objects[i + 1];
        }

        delete[] objects;

        objects = new_objects;
    }

    int getVolume()
    {
        int volume = 0;

        for (int i = 0; i < size; i++)
            if (objects[i] != NULL)
                volume++;

        return volume;
    }
};


void test_storage(int size)
{
    time_t start, end;

    time(&start);

    srand(time(NULL));

    Storage s1(size);

    for (int i = 0; i < s1.getCount(); i++)
    {
        s1.setObject(i, new Rectangle(i / 5, i / 10));
    }

    for (int i = 0; i < s1.getCount(); i++)
    {
        if (rand() % 2 == 0)
            s1.getObject(i).draw();
        else
            s1.getObject(i).area(1, 1);
    }

    yellow("Initial size = " + to_string(s1.getCount()));

    s1.addObjects(s1.getCount(), new RoundedRectangle());

    yellow("Size after adding Rounded Rectangle = " + to_string(s1.getCount()));

    s1.nullObject(rand() % size);

    yellow("Size after initializing the ojb with null = " + to_string(s1.getCount()));

    yellow("Size of used objects " + to_string(s1.getVolume()));

    s1.deleteObject((rand() * rand()) % size);

    yellow("Size after object deletion " + to_string(s1.getCount()));
    
    yellow("Size of used objects " + to_string(s1.getVolume()));


    time(&end);

    highlight("Execution time" + to_string(difftime(end, start)));

}


int main()
{
    test_storage(100);

    test_storage(1000);

    test_storage(10000);

    system("pause");
    return 0;
}


void grean(string s) { printf("\033[1;32m"); cout << " " << s << " "; printf("\033[0m"); }
void yellow(string s) { printf("\033[1;33m"); cout << endl << s << endl ; printf("\033[0m"); }
void highlight(string s) { printf("\033[1;7m"); cout << endl << s << endl ; printf("\033[0m"); }