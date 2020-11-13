#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>



struct node1d* find(struct node2d *init, char *word);
struct node1d* append_1d_end(struct node2d *init, char *word);
struct node1d* append_1d_after(struct node2d *init, char *after, char *word);
void print_1D(struct node2d *init);

struct node1d* find(struct node2d *init, char *word){
    struct node2d *iterator = init;
    while  (iterator->next != NULL){
        struct node1d *node = iterator->data;
        while (node->next != NULL){
            if (strcmp(node->name,word)==0){
                return node;
            }
            node = node->next;
        }
        iterator = iterator->next;
    }
    struct node1d *node = NULL;
    return node;
}

struct node1d* append_1d_end(struct node2d *init, char *word){
    struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
    struct node1d *node = init->data;
    while (node->next != NULL){
        node = node->next;
    }
    temp-> name = word;
    temp-> next = NULL;
    node-> next = temp;
    return temp;
}

struct node1d* append_1d_after(struct node2d *init, char *after, char *word){
    struct node1d *found = find(init, after);
    struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
    temp->name = word;
    temp->next = NULL;
    found->next = temp;
    return temp;
}

void print_1D(struct node2d *init){
    struct node1d *node = init->data;
    while (node->next != NULL){
        printf("%s,",node->name);
    }
    return;
}

