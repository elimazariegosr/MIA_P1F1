QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ast_node.cpp \
        ast_node_controller.cpp \
        main.cpp \
        mkdisk_controller.cpp \
        parser.cpp \
        scanner.cpp \
        struct_adm.cpp \
    reports.cpp \
    data_mount.cpp \
    data_mount_controller.cpp \
    system_controller.cpp \
    helper.cpp \
    login.cpp \
    user_controller.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ast_node.h \
    ast_node_controller.h \
    mkdisk_controller.h \
    parser.h \
    scanner.h \
    struct_adm.h \
    reports.h \
    data_mount.h \
    data_mount_controller.h \
    system_controller.h \
    helper.h \
    login.h \
    user_controller.h

DISTFILES += \
    lex.l \
    syntactic.yy
