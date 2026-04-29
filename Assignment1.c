#include <stdio.h>
#include <string.h>

#define bf 50

typedef struct {
    char data[bf];
    int head;
    int tail;
    int a;
} x;



void c(x *b) {
    b->head = 0;
    b->tail = 0;
    b->a = 0;
}

int full(x *b) {
    return b->a == bf; }


int e(x *b) {
    return b->a == 0;
}



void r(x *b, char val) {
    if (!full(b)) {
        b->data[b->tail] = val;
        b->tail = (b->tail + 1) % bf;
        b->a++;
    } }

char read(x *b) {
    if (!e(b)) {
        char val = b->data[b->head];
        b->head = (b->head + 1) % bf;
        b->a--;
        return val;
    }
    return '\0';
}


int main() {
    x my_b;
    c(&my_b);
    char my_name[100];
    char extra[] = "-CE-ESY";

    printf("Enter name: ");
    if (fgets(my_name, sizeof(my_name), stdin) != NULL) {
        my_name[strcspn(my_name, "\n")] = 0; }

    strcat(my_name, extra);
    printf("Text to save: %s\n", my_name);

    for (int i = 0; i < strlen(my_name); i++) {
        r(&my_b, my_name[i]);
    }

    printf("Output from Buffer: ");
    while (!e(&my_b)) {
        char res = read(&my_b);
        if (res != '\0') {
            printf("%c", res);
    }
    }
    printf("\n");

    return 0;
}