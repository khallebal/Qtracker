
TEMPLATE    = subdirs
SUBDIRS	    =\
    library\
    qtracker \
     qtracker-fa

CONFIG += qt \
          release


INCLUDEPATH +=common\
              usr\
              etc

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
 elokabData.path=usr/share/qtracker
 INSTALLS +=    elokabConfig \
                elokabData

