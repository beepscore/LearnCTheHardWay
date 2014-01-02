// if _object_h is already defined,
// #ifndef skips all code through #endif
// This way, multiple files can include object.h
// without causing problems by defining multiple times
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
    void (*move)(void *self, Direction direction);
    int (*attack)(void *self, int damage);
} Object;

// forward declarations
int Object_init(void *self);
void Object_describe(void *self);
void Object_destroy(void *self);
void Object_move(void *self, Direction direction);
void Object_attack(void *self, int damage);
void Object_new(size_t size, Object proto, char *description);

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N

#endif

