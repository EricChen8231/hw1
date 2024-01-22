#include "split.h"

void split(Node *&in, Node *&odds, Node *&evens)
{
    if (in == nullptr)
    {
        return;
    }
    Node *nextNode = in->next;
    if (in->value % 2 == 0)
    {
        in->next = evens;
        evens = in;
    }
    else
    {
        in->next = odds;
        odds = in;
    }

    in = nextNode;

    split(in, odds, evens);
}