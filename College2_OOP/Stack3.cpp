#include "Stack3.h"
#include <stdio.h>
using namespace std;
Stack::Link::Link(void *dat, Link *nxt)
{
    data = dat;
    next = nxt;
}
Stack::Link::~Link() {}
Stack::Stack() { head = 0; }
void Stack::push(void *dat)
{
    head = new Link(dat, head);
}
//瞄一眼stack
void *Stack::peek()
{
    if (head == 0)
    {
        printf("Stack empty\n");
        return NULL;
    }
    return head->data;
}
void *Stack::pop()
{
    if (head == 0)
        return 0;
    void *result = head->data;
    Link *oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}
Stack::~Stack()
{
    while (head != 0)
    {
        Stack::pop();
    }
}
int main()
{
    Stack stk;
    int a = 1, b = 2;
    stk.push(&a);
    stk.push(&b);
    stk.~Stack();
    stk.peek();
}