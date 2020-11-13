#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "lab2.h"
#include "node2d.c"
#include "node1d.c"


#define BUFSIZE 100
#define MAXWORDLENGTH 20


void ungetch(int c);
int getch(void);
void printAlll(struct node2d *init);
int getword(char *word, int lim);


char buf[BUFSIZE];
int bufp = 0;

struct node2d *init = NULL;
void ungetch(int c) {
    if (bufp >= BUFSIZE)
      printf("ungetch: too many chars\n");
    else
      buf[bufp++] = c;
}

int getch(void) {
    return (bufp>0) ? buf[--bufp] : getchar();
}

void printAlll(struct node2d *init){
    struct node2d *iterator = init;
    while  (iterator->next != NULL){
        struct node1d *node = iterator->data;
        printf("2d:",iterator->name);
        while (node->next != NULL){
            printf("1d:",iterator->name);
            node = node->next;
        }
        iterator = iterator->next;
    }
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch())) ;
    if (c != EOF)
      *w++ = c;
    if (!isalpha(c)) {
      *w = '\0';
      return c;
    }
    for ( ; --lim > 0; w++)
      if (!isalnum(*w = getch())) {
        ungetch(*w);
        break;
      }
    *w = '\0';
    return word[0];
}

int main(int n, char *args[]){
    FILE *fp = fopen(args[1],"r");
    char input[MAXWORDLENGTH];

    char appendRear2D[12] = "appendRear2D";
    char appendAfter2D[13] = "appendAfter2D";
    char appendRear1D[12] = "appendRear1D";
    char appendAfter1D[12] = "appendAfter1D";
    char printAll[8] = "printAll";
    char print1DList[11] = "print1DList";
    char find1D[6] = "find1D";
    char find2D[6] = "find2D";


    while(getword(input, MAXWORDLENGTH)!=EOF) {
        if (input == appendRear2D){
            getword(input, MAXWORDLENGTH);
            append_rear_2d(init, input);
        }else if (input == appendAfter2D){
            char name[MAXWORDLENGTH];
            getword(input, MAXWORDLENGTH);
            getword(name, MAXWORDLENGTH);
            insert_2d(init, input, name);
        }else if (input == appendRear1D){
            getword(input, MAXWORDLENGTH);
            append_1d_end(init, input);
        }else if (input == appendAfter1D){
            char name[MAXWORDLENGTH];
            getword(input, MAXWORDLENGTH);
            getword(name, MAXWORDLENGTH);
            append_1d_after(init, name,input);
        }else if (input == printAll){
            printAlll(init);
        }else if (input == print1DList){
            print_1D(init);
        } else if (input == find1D){
            getword(input, MAXWORDLENGTH);
            find(init,input);
        }else if (input == find2D){
            getword(input, MAXWORDLENGTH);
            find_print_2d(init, input);
        }  
    } 
}
