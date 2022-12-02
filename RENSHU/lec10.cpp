#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class A
{
private:
    char *name = NULL;

public:
    A()
    {
        printf("A Default Constructor\r\n");
    }
    A(const char *name)
    {
        printf("A Constructor\r\n");
        printf("    name = %s\r\n", name);
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
    }
    ~A()
    {
        printf("A Destructor\r\n");
        if (name != NULL)
        {
            printf("    delete name = %s\r\n", name);
            delete (name);
        }
    }
};

class B : A
{
private:
    char *name = NULL;

public:
    B()
    {
        printf("B Default Constructor\r\n");
    }
    B(const char *name)
    {
        printf("B Constructor\r\n");
        printf("    name = %s\r\n", name);
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
    }
    ~B()
    {
        printf("B Destructor\r\n");
        if (name != NULL)
        {
            printf("    delete name = %s\r\n", name);
            delete (name);
        }
    }
};
int main(int argc, char **argv)
{
    A a;
    A aa("aa");

    A *pa = new A("pa");
    delete pa;

    B b;
    B bb("bb");

    B *pb = new B("pb");
    delete pb;

    return 0;
}