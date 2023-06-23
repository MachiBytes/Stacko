/*
Program that tries to simulate a block stacking game using a Linked list
- User will be asked for the color of block that they want
- Then the color that they chose will be displayed visually on screen
- Program stops when user enters 0

Sample output:
===
===
===

Choose a color:
1 - red
2 - green
3 - blue
0 - exit

Choice: 

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Block {
    int color;
    struct Block *prev;
    struct Block *next;
};

#define FRED     "\x1b[31m"
#define FGREEN   "\x1b[32m"
#define FBLUE    "\x1b[34m"
#define FWHITE   "\x1b[37m"

void add_block(struct Block *head, int choice);
void show_blocks(struct Block *head);

int main (int argc, char *argv[]) {
    // Initialize linked list
    struct Block *head = malloc(sizeof(struct Block));
    head->prev = NULL;
    head->next = NULL;

    printf("WELCOME TO STACKO!\n");
    printf("\n");
    printf("==========\n");
    printf("\n");
    
    int choice;

    do {
        printf("Choose a color!\n");
        printf("\t1 - Red\n");
        printf("\t2 - Green\n");
        printf("\t3 - Blue\n");
        printf("\t0 - Exit\n");
        printf("\n");

        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        printf("\n");

        if (choice == 0) {
            printf("Exiting program...");
            continue;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again!\n");
            printf("\n");
            continue;
        }

        add_block(head, choice);

        show_blocks(head);

    } while (choice != 0);
    

    return 0;
}

void add_block(struct Block *head, int choice) {
    struct Block *temp = malloc(sizeof(struct Block));
    temp->color = choice;
    temp->prev = NULL;
    temp->next = NULL;

    if (head->next == NULL) {
        head->next = temp;
        temp->prev = head;
        return;
    }

    struct Block *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;
}

void show_blocks(struct Block *head) {
    struct Block *ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    while(ptr->prev != NULL) {
        int color = ptr->color;

        if (color == 1) {
            printf("%s==========\n", FRED);
        } else if (color == 2) {
            printf("%s==========\n", FGREEN);
        } else if (color == 3) {
            printf("%s==========\n", FBLUE);
        }
        ptr = ptr->prev;
    }
    printf("%s==========\n", FWHITE);
    printf("\n");
}
