TEMPLATE = app
CONFIG += console
CONFIG -= qt

QMAKE_CFLAGS = -std=gnu99

SOURCES += main.c \
    router.c \
    list.c

HEADERS += \
    router.h \
    main.h \
    list.h

OTHER_FILES += \
    Makefile

