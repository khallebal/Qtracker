
TEMPLATE    = subdirs
SUBDIRS	    =\
    library\
    Qtracker \
     Qtracker-fa

CONFIG += qt \
          release


INCLUDEPATH +=common\
              usr\
              etc

PKG_CONFIG_PATH = /boot/system/develop/lib/x86/pkgconfig

LIBS += $(SUBLIBS)  -L/usr/lib -lQtDBus -lQtXml -lQtGui -lQtCore -lpthread
linux-g++*: {
             # Provide relative path from application to elokab librarys
             # ex:app=usr/bin/elokab-applications  library=usr/lib/libelokabmimicon.so
             QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../lib
             }

#---------------------------------------------
#                   INSTALL
#---------------------------------------------

#---config files---------
 elokabConfig.files =etc/xdg/*
 elokabConfig.path=/etc/xdg/

#---DATA files---------------
 elokabData.files=usr/share/qtracker/*
 elokabData.path=/usr/share/qtracker

 INSTALLS +=    elokabConfig \
                elokabData

