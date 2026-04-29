#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10

typedef struct {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
[span_0](start_span)}

bool isFull(CircularBuffer *cb) {
    return cb->count == SIZE;
}[span_0](end_span)

bool isEmpty(CircularBuffer *cb) {
    return cb->count == 0;
[span_1](start_span)[span_2](start_span)}

void write(CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\nBuffer Overflow\n");
        return;
    }[span_1](end_span)[span_2](end_span)
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
    cb->count++;
}

char read(CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\nBuffer Underflow\n");
        return '\0';
    [span_3](start_span)}
    char data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    CircularBuffer cb;
    init(&cb);[span_3](end_span)

    char name[100];
    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin)) {
        name[strcspn(name, "\n")] = 0;
    [span_4](start_span)[span_5](start_span)}

    strcat(name, "CE-ESY");[span_4](end_span)[span_5](end_span)

    printf("Writing to buffer...\n");
    for (int i = 0; name[i] != '\0'; i++) {
        write(&cb, name[i]);
    [span_6](start_span)[span_7](start_span)}

    printf("Reading from buffer: ");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }[span_6](end_span)[span_7](end_span)
    printf("\n");

    if (isEmpty(&cb)) {
        printf("Buffer is now empty.\n");
    [span_8](start_span)}[span_8](end_span)

    return 0;
}