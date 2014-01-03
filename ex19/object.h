// if _object_h is already defined,
// #ifndef skips all code through #endif
// This way, multiple files can include object.h
// without causing problems by double inclusion
// http://en.wikipedia.org/wiki/C_preprocessor
#ifndef _object_h
// #define _object_h to prevent multiple including
#define _object_h

typedef enum {
    NORTH, SOUTH, EAST, WEST
} Direction;

typedef struct {
    char *description;
    // function pointers
    int (*init)(void *self);
    void (*describe)(void *self);
    void (*destroy)(void *self);
    void *(*move)(void *self, Direction direction);
    int (*attack)(void *self, int damage);
} Object;

// forward declarations
int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);

// function-like macros
// #define <identifier>(<parameter list>) <replacement token list>
// T##Proto concatenates Proto to the end of T
// NEW(Room, "Hello") will become Object_new(sizeof(Room), RoomProto, "Hello")
#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
// use this to write obj->_(blah) as shorthand for obj->proto.blah
#define _(N) proto.N

#endif

