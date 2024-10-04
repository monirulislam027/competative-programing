
struct A
{
    char a;
    char b;
    int c;
};
struct B
{
    char a;
    int c;
    char b;
};

int main()
{
    struct A a;
    printf("Size of a %d\n", sizeof(a));

    struct B b;
    printf("Size of b %d\n", sizeof(b));

    return 0;
}