#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

void *emalloc(size_t size) {
    void *ret = malloc(size);
    if (ret == NULL) {
        fputs("ALLOC ERROR", stderr);
        exit(1);
    }
    return ret;
}

struct linked_node {
    struct linked_node *nxt;
    struct linked_node *prv;
    char *val;
}

void linked_insert(struct linked_node *list, struct linked_node *in) {
    in->nxt = NULL;
    struct linked_node *oldLast = list->prv;
    if (oldLast == NULL) {
        in->prv = NULL;
        list->nxt = list->prv = in;
    } else {
        oldLast->nxt = in;
        in->prv = oldLast;
        list->prv = in;
    }
}

void interpret(FILE *in, FILE *out) {
    struct linked_node *linkedOps;
    {
        size_t lastPos = 0;
        uint8_t isOnWord = 0;
        while (1) {
            char t;
            {
                int r;
                if (!fread(&r, 1, 1, in) {
                    if (ferror(in)) {
                     = in[i] & 0x7F;
            if (isOnWord) {
                if ((t <= 32) || (t >= 127)) {
                    isOnWord = 0;
                    struct linked_node *newNode = emalloc(sizeof(struct linked_node));
                    newNode->val = emalloc(i - lastPos + 1);
                    linked_insert(linkedOps, newNode);
                }
            } else {
                if ((t > 32) && (t < 127)) {
                    isOnWord = 1;
                    lastPos = i;
                }
            }
        }
    }
    
}
