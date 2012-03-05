TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.c \
    router.c \
    list.c

HEADERS += \
    router.h \
    main.h \
    list.h

OTHER_FILES += \
    Makefile

