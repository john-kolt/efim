FLAGS= -Wall -O3 -s -std=gnu99
FLAGSD= -Wall -O2 -g -std=gnu99
FLAGSW= $(FLAGS) -static -Wl,-Bstatic -mwindows

PROJECT=efim
all: debug
debug: linux-debug
release: linux64 win32-static

linux-debug: main.c main.h router.h router.c list.h list.c
	gcc $(FLAGSD) main.c -o $(PROJECT)

linux64: main.c main.h router.h router.c
	# --------------------------------------------------------------- #
	# - - - - - - - - -  КОМПИЛЯЦИЯ ПОД LINUX X64 - - - - - - - - - - #
	# --------------------------------------------------------------- #
	gcc $(FLAGS) main.c -o $(PROJECT)

win32-static: main.c main.h router.h router.c
	# --------------------------------------------------------------- #
	# - - - - - - - - -  КОМПИЛЯЦИЯ ПОД WIN32     - - - - - - - - - - #
	# --------------------------------------------------------------- #
	i486-mingw32-gcc main.c -o $(PROJECT).exe $(FLAGSW)

clean:
	rm $(PROJECT).exe  $(PROJECT)

.PHONY: all clean debug release
