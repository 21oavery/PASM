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

void *erealloc(void *ptr, size_t size) {
    void *ret = realloc(ptr, size);
    if (ret == NULL) {
        fputs("REALLOC ERROR", stderr);
        exit(1);
    }
    return ret;
}

// Returns the origional on failure
void *shrink(void *ptr, size_t size) {
    void *ret = realloc(ptr, size);
    if (ret == NULL) return ptr;
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

#define ARRAY_INIT_SIZE 16
#define ARRAY_GROW 2

struct funct {
    uint8_t paramCnt;
    uint8_t localCnt;

int interpret(FILE *in, FILE *out) {
    struct linked_node *linkedOps;
    {
        char *tmpData;
        size_t lastPos = 0;
        size_t tmpMemLen;
        size_t tmpDataLen;
        uint8_t isOnWord = 0;
        while (1) {
            char t;
            {
                int r;
                if (!fread(&r, 1, 1, in) {
                    if (ferror(in)) {
                        fputs("File read error");
                        return -1;
                    } else {
                        if (isOnWord) {
                            
                    t = r & 0x7F;
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
                    tmpData = emalloc()
                    tmpDataLen = 0;
                }
            }
        }
    }
    struct linked_node *end = linkedOps->prv;
}
