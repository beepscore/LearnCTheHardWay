#include <stdio.h>
#include <assert.h>
// stdlib contains exit()
#include <stdlib.h>
// errno reports error codes at static location errno
// http://en.wikipedia.org/wiki/Errno.h
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATA 512
#define MAX_ROWS 100

/** Address struct is fixed size.
 * This is less space efficient but easier to read and write.
 */
struct Address {
    int id;
    bool is_set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

/** Database struct is fixed size, because it contains a fixed number of fixed size elements.
 */
struct Database {
    // rows array contains elements of type struct Address
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void die(const char *message) {
    if (errno) {
        // perror prints error message to stderr
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }
    // exit with non-zero code 1 to indicate a problem occurred
    exit(1);
}

void Address_print(struct Address *addr) {
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {
    // Reference: man 3 fread
    // fread() reads nitems objects, each size bytes long,
    // from the stream pointed to by stream,
    // storing them at the location given by ptr.
    // fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    // fread returns number of objects read
    if (rc != 1) die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode) {
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn) {
        die("Memory error");
    }

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db) {
        die("Memory error");
    }

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file) {
        die("Failed to open the file");
    }

    return conn;
}

void Database_close(struct Connection *conn) {
    if (conn) {
        if (conn->file) {
            fclose(conn->file);
        }
        if (conn->db) {
            free(conn->db);
        }
        free(conn);
    }
}

void Database_write(struct Connection *conn) {
    rewind(conn->file);

    // Reference: man 3 fwrite
    // fwrite() writes nitems objects, each size bytes long,
    // to the stream pointed to by stream, obtaining them from the location given by ptr.
    // fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    // fwrite returns number of objects written
    if (rc != 1) {
        die("Failed to write database.");
    }
    // fflush() forces a write of all buffered data for the given output or update stream
    rc = fflush(conn->file);
    if (rc == -1) {
        die("Cannot flush database.");
    }
}

void Database_create(struct Connection *conn) {
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .is_set = false};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
    struct Address *addr = &conn->db->rows[id];
    if (addr->is_set) {
        die("Already set, delete it first");
    }
    addr->is_set = true;

    // WARNING: bug, read the "How To Break It" and fix this
    // demonstrate the strncpy bug (Not an undocumented 'bug', but maybe poor design)
    // if name is as long or longer than MAX_DATA, strncpy won't set the last character null.
    // http://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/
    // http://stackoverflow.com/questions/14950241/pointer-to-one-struct-in-another-writing-and-reading-it-from-file-gives-segfaul
    char *res = strncpy(addr->name, name, MAX_DATA);
    // Ensure last character is null.
    addr->name[sizeof(addr->name) - 1] = '\0';

    if (!res) {
        die("Name copy failed");
    }

    res = strncpy(addr->email, email, MAX_DATA);
    // Ensure last character is null.
    addr->email[sizeof(addr->email) - 1] = '\0';
    if (!res) {
        die("Email copy failed");
    }
}

void Database_get(struct Connection *conn, int id) {
    struct Address *addr = &conn->db->rows[id];

    if (addr->is_set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id) {
    struct Address addr = {.id = id, .is_set = false};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn) {
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur->is_set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        die("USAGE: ex17 <dbfile> <action> [action params]");
    }

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if (argc > 3) {
        id = atoi(argv[3]);
    }
    if (id >= MAX_ROWS) {
        die("There's not that many records.");
    }

    switch (action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if (argc != 4) {
                die("Need an id to get");
            }
            Database_get(conn, id);
            break;

        case 's':
            if (argc != 6) {
                die("Need id, name, email to get");
            }
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if (argc != 4) {
                die("Need id to delete");
            }
            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;

        default:
            die("Invalid action, only: c=create, g=get, s=set, d=delete, l=list");
    }

    Database_close(conn);
    return 0;

}
