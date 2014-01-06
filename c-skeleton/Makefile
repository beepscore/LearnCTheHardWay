# https://www.owasp.org/index.php/C-Based_Toolchain_Hardening
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

# list of .c files, by wildcard search
SOURCES=$(wildcard src/**/*.c src/*.c)
# list of .o files, using SOURCES file list, changing extension from .c to .o
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
# list of test files, using TEST_SRC file list, deleting .c extension
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
# if user doesn't specify a target, by default make runs the first target
# here the first target is all:, make will build TARGET library and tests.
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

# add option fPIC to CFLAGS
$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	# create build and bin directories
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
# add TARGET to CFLAGS so each test program will be linked to TARGET library
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	# run shell script to run tests
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	# Delete files in .dSYM directory.
	# Delimiter on web page is backtick. Use apostrophe instead.
	rm -rf 'find . -name "*.dSYM" -print'

# The Install
# set target install: to depend upon all:
install: all
	# By convention, installers often define variable DESTDIR or PREFIX
	# If they are defined, use them
	install -d $(DESTDIR)/$(PREFIX)/lib/
	# PREFIX may be used to override default /usr/local
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
# look for "bad" string functions and unprotected buffer functions such as strcpy.
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)'
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true
