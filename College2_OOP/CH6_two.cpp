#include <iostream>
using namespace std;
class Tree
{
    int H;

public:
    Tree(int treeHeight = 0)
    {
        H = treeHeight;
        cout << "Tree(): " << H << endl;
    }
    void print() { cout << H << endl; }
    ~Tree()
    {
        cout << "~Tree(): " << H << endl;
    }
};
Tree outObj(10);
int main()
{
    Tree inObj(20);
    static Tree staticObj(30);
    Tree *t = new Tree(40);
    printf("%p\n%p\n%p\n", &inObj, &staticObj, t);
    //inObj分配在内存栈上，而staticObj分配在静态储存区，t分配在内存堆上
    delete t;
}
