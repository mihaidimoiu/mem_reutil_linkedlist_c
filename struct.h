#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

struct node
{
    unsigned int id;
    char *name;
    struct node *next;
};


#endif // STRUCT_H_INCLUDED
