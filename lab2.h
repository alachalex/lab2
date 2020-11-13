#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct node1d {
    struct node1d *next;
    char *name;
};


struct node2d {
    char *name;
    struct node1d *data;
    struct node2d *next;
    int *count;
};