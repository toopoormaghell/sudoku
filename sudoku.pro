TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gamegrid.cpp

HEADERS += \
    crtp.h \
    gamegrid.h \
    crtp_impl.h
