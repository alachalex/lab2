#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


struct node2d* append_rear_2d(struct node2d *init, char *word);
struct node2d* append_2d(struct node2d *init, char *word);
struct node2d* search_node2D(struct node2d *init, char *word);
struct node2d* insert_2d(struct node2d *init, char *word, char *name);
void charar_2dlist(struct node2d *init);
void find_print_2d(struct node2d *init, char *word);

struct node2d* append_rear_2d(struct node2d *init, char *word) {
    struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
    if(init!=NULL) {
        //creating a temporary node
        temp->name = word;
        //sets the name of the temporary node to the word given
        temp->next = init->next;
        temp->data = NULL;
        //sets the next value to the previous head's next
        //sets the new head to the temporary calye
        init -> next = temp;
    }else{
        temp-> name = word;
        temp-> data = NULL;
        temp-> next = NULL;
        init = temp;
    }
    return init;
}

struct node2d* append_2d(struct node2d *init, char *word){
    struct node2d *iterator = init;
    while (iterator->next != NULL){
        iterator = iterator->next;
    }
    struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
    temp-> name = word;
    temp-> data = NULL;
    temp-> next = NULL;
    iterator->next = temp;
    return init;
}

struct node2d* search_node2D(struct node2d *init, char *word) {
    if (init == NULL){
        //if the starting node is null, returns Null
        return init;
    }
    struct node2d *temp = init;
    while(temp!=NULL && strcmp(temp->name, word)!=0){
        //iterates through the nodes
        temp = temp->next;
    }
    if(strcmp(temp->name, word)==0){
        //if the  2d node with that name is not found, returns NULL
        temp = NULL;
        return temp;
    }
    return temp;
}

struct node2d* insert_2d(struct node2d *init, char *word, char *name) {
    if(init!=NULL) {
        //finds the node which we are looking for
        struct node2d *temp = search_node2d(init, word);
        insert_afterhead_2d(temp, name);
    }
    return init;
}

void charar_2dlist(struct node2d *init) {
    struct node2d *temp = init;
    while(temp!=NULL) {
        printf("%s,",temp->name);
        temp = temp->next;
    }
    return;
}

void find_print_2d(struct node2d *init, char *word){
    if (search_node2D(init, word) == init){
        printf("%s,","found");
    }else{
        printf("%s,","not found");
    }
    return;
}