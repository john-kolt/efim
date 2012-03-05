FLAGS= -Wall -O3 -s
FLAGSD= -Wall -O2 -g
FLAGSW= $(FLAGS) -static -Wl,-Bstatic -mwindows

PROJECT=efim-alpha

all: debug
debug: linux-debug
release: linux64 win32-static

linux-debug: main.c main.h router.h router.c
	gcc $(FLAGSD) main.c -o bin/$(PROJECT)

linux64: main.c main.h router.h router.c
	# --------------------------------------------------------------- #
	# - - - - - - - - -  КОМПИЛЯЦИЯ ПОД LINUX X64 - - - - - - - - - - #
	# --------------------------------------------------------------- #
	gcc $(FLAGS) main.c -o bin/$(PROJECT)

#linux32: main.c main.h router.h router.c
#	# --------------------------------------------------------------- #
#	# - - - - - - - - -  КОМПИЛЯЦИЯ ПОД LINUX X86 - - - - - - - - - - #
#	# --------------------------------------------------------------- #
#	gcc $(FLAGS) -m32 main.c -o bin/$(PROJECT)

win32-static: main.c main.h router.h router.c
	# --------------------------------------------------------------- #
	# - - - - - - - - -  КОМПИЛЯЦИЯ ПОД WIN32     - - - - - - - - - - #
	# --------------------------------------------------------------- #
	i486-mingw32-gcc main.c -o bin/$(PROJECT).exe $(FLAGSW)

clean:
	rm bin/$(PROJECT).exe  bin/$(PROJECT)

.PHONY: all clean debug release
