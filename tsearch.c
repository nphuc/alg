#include <search.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
      int key;
      char* value;
} intStrMap;

int compar(const void *l, const void *r)
{
    const intStrMap *lm = l;
    const intStrMap *lr = r;
    return lm->key - lr->key;
}

int main(int argc, char **argv)
{
    void *root = 0;

    intStrMap *a = malloc(sizeof(intStrMap));
    intStrMap *b = malloc(sizeof(intStrMap));
    intStrMap *c = malloc(sizeof(intStrMap));
    a->key = 2;
    a->value = strdup("two");
    b->key=1;
    c->key=3;
    c->value=strdup("dot");
    b->value=strdup("hehe");
    tsearch(a, &root, compar); /* insert */
    tsearch(b, &root, compar); /* insert */
    tsearch(c, &root, compar); /* insert */

    intStrMap *find_a = malloc(sizeof(intStrMap));
    find_a->key = 3;

    void *r = tfind(find_a, &root, compar); /* read */
    printf("%s", (*(intStrMap**)r)->value);

    return 0;
}
