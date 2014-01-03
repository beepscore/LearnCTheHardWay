#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
    Object *obj = self;

    if (obj) {
        if (obj->description) {
            // free() return type is void, i.e. free() doesn't return a value.
            // So we don't need to check return value.
            free(obj->description);
        }
        free(obj);
    }
}

void Object_describe(void *self)
{
    Object *obj = self;
    printf("%s.\n", obj->description);
}

int Object_init(void *self)
{
    // do nothing really
    return 1;
}

void *Object_move(void *self, Direction direction)
{
    printf("You can't go that direction.\n");
    return NULL;
}

int Object_attack(void *self, int damage)
{
    printf("You can't attack that.\n");
    return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
    assert(size != 0);
    // http://stackoverflow.com/questions/2414809/default-value-of-an-objective-c-struct-and-how-to-test
    // http://stackoverflow.com/questions/141720/how-do-you-compare-structs-for-equality-in-c?lq=1
    assert(proto.description == NULL);

    printf("proto.attack %p\n", proto.attack);
    assert(proto.attack != NULL);

    printf("proto.init %p\n", proto.init);
    // assertion doesn't work. Sometimes proto.init is NULL, sometimes it isn't
    //assert(proto.init != NULL);

    printf("proto.move %p\n", proto.move);
    // assertion doesn't work. Sometimes proto.move is NULL, sometimes it isn't
    // assert(proto.move != NULL);

    assert(description != NULL);

    // setup the default functions in case they aren't set
    if (!proto.init) {
        proto.init = Object_init;
    }
    if (!proto.describe) {
        proto.describe = Object_describe;
    }
    if (!proto.destroy) {
        proto.destroy = Object_destroy;
    }
    if (!proto.attack) {
        proto.attack = Object_attack;
    }
    if (!proto.move) {
        proto.move = Object_move;
    }

    // this seems weird, but we can make a struct of one size,
    // then point a different pointer at it to "cast" it
    Object *el = calloc(1, size);
    assert(el != NULL);
    *el = proto;

    // copy the description argument to el
    el->description = strdup(description);

    // initialize it with whatever init we were given
    if (!el->init(el)) {
        // looks like it didn't initialize properly
        el->destroy(el);
        return NULL;
    } else {
        // all done, we made an object of any type
        return el;
    }
}
