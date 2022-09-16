/***************************************************************************
 *   elokab Copyright (C) 2014 AbouZakaria <yahiaui@gmail.com>             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "edir.h"
#include<QApplication>

#include<QDesktopServices>

//_________________________________________________________________
QString Edir::progPath(const QString &prog)
{
    // "/usr/bin/prog"
    QDir dir(QApplication::applicationDirPath());

    if(QFile::exists(dir.absoluteFilePath(prog))){
        return dir.absoluteFilePath(prog);
    } else{
        QString path = qgetenv("PATH");
        foreach(QString dir, path.split(":"))
        {

            if (QFile::exists(dir + QDir::separator() + prog)){
                return dir + QDir::separator() + prog;
            }
        }
    }
    return prog;
}

//_________________________________________________________________
QString Edir::dataDir()
{
    //  "/usr/share/elokab
    QDir appDir=QApplication::applicationDirPath();
    QString dirPath;
    dirPath = appDir.cd(appDir.path()+"/data");

    return appDir.absolutePath();
}

//_________________________________________________________________
QString Edir::dataAppDir()
{
  //  "/usr/share/elokab/elokab-appname"
    QString appName=QApplication::applicationName();
    return dataDir()+QDir::separator()+appName;
}


//_________________________________________________________________

QString Edir::dataHomeDir()
{
	//"$Home/.local/share
    QDir appDir=QApplication::applicationDirPath();
    QString dirPath;
    dirPath = appDir.cd(appDir.path()+"/data");

    return appDir.absolutePath();
}

//_________________________________________________________________
QString Edir::dataHomeAppDir()
{
    //"$Home/.local/share/elokab/elokab-appname
    QString appName=QApplication::applicationName();
    return dataHomeDir()+"/"+appName;
}

//_________________________________________________________________
QString Edir::libDir()
{
   // "/usr/lib/elokab"
  // QString appName=QApplication::applicationName();
   QDir pluginsDir(qApp->applicationDirPath());
    pluginsDir.cdUp();
    if(QFile::exists(pluginsDir.path()+"/lib")){
        pluginsDir.cd(pluginsDir.path()+"/lib");
    }else if(QFile::exists(pluginsDir.path()+"/lib64")){
        pluginsDir.cd(pluginsDir.path()+"/lib64");
    }
    return pluginsDir.absolutePath();
}

//_________________________________________________________________
QString Edir::configDir()
{
    //"$Home/.config/elokab"
    QDir dir(configHomeDir()+"/Qtracker");
    if(!dir.exists())
        dir.mkpath(".");
    return dir.absolutePath();
}

//_________________________________________________________________
QString Edir::configHomeDir()
{
    //"$Home/.config"
    QString location;
#if QT_VERSION >= 0x050000
    location=QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
#else
    location=QDesktopServices::storageLocation(QDesktopServices::ConfigLocation);
#endif

	QDir dir(location);
    if(!dir.exists())
        dir.mkpath(".");
    return dir.absolutePath();
}

//_________________________________________________________________
QStringList Edir::applicationsDirs()
{
    return QStringList()<<applicationsHomeDir()
                       <<"/applications";
}

//_________________________________________________________________
QString Edir::applicationsHomeDir()
{
    QDir dir(configDir()+"/applications");
    if(!dir.exists())
        dir.mkpath(".");
    return dir.absolutePath();
}
//_________________________________________________________________
QString Edir::thumbnaileCachDir()
{
    QString cacheDir;

    // Follow the FreeDesktop Spec
    const QByteArray arr = qgetenv("XDG_CACHE_HOME");
    if (!arr.isEmpty()) {
        QFileInfo fi(arr);
        if (fi.exists() && fi.isReadable()) {
            cacheDir = fi.absoluteFilePath();
            cacheDir += QStringLiteral("/thumbnails/");
        }
    }

    if (cacheDir.isEmpty()) {
        cacheDir = QDir::homePath() + 
        	QStringLiteral("/config/cache/thumbnails/");
    }

    // check if
    if (!cacheDir.isEmpty()) {
        QDir dir(cacheDir);
        if(!dir.exists())
            dir.mkpath(".");
        // FIXME: check for all the other sizes
        QDir dirNormal(cacheDir+"normal/");
        if(!dirNormal.exists())
            dirNormal.mkpath(".");
    }
    return cacheDir;
}

//_________________________________________________________________

QString Edir::cachDir()
{
//    QString location;
//#if QT_VERSION >= 0x050000
//    location=QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
//#else
//    location=QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
//#endif
//
//    QDir dir(location);
//    if(!dir.exists())
//        dir.mkpath(".");
//    return location;
	return NULL;	
}

//_________________________________________________________________
QString Edir::desktopDir()
{
    QString location;
#if QT_VERSION >= 0x050000
    location=QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
#else
    location=QDesktopServices::storageLocation(QDesktopServices::DesktopLocation);
#endif

    return location;
}

//_________________________________________________________________
QString Edir::documentsDir()
{
    QString location;
#if QT_VERSION >= 0x050000
    location=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
#else
    location=QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation);
#endif

    return location;
}

//_________________________________________________________________
QString Edir::musicDir()
{
    QString location;
#if QT_VERSION >= 0x050000
    location=QStandardPaths::writableLocation(QStandardPaths::MusicLocation);
#else
    location=QDesktopServices::storageLocation(QDesktopServices::MusicLocation);
#endif

    return location;
}

//_________________________________________________________________
QString Edir::moviesDir()
{
    QString location;
#if QT_VERSION >= 0x050000
    location=QStandardPaths::writableLocation(QStandardPaths::MoviesLocation);
#else
    location=QDesktopServices::storageLocation(QDesktopServices::MoviesLocation);
#endif

    return location;
}

//_________________________________________________________________
QString Edir::picturesDir()
{
    QString location;
#if QT_VERSION >= 0x050000
    location=QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
#else
    location=QDesktopServices::storageLocation(QDesktopServices::PicturesLocation);
#endif

    return location;
}

//_________________________________________________________________
QString Edir::trashDir()
{
    QDir dir(QDir::rootPath()+"/boot/trash");
    if(dir.exists())
        return dir.absolutePath();

    dir.setPath(configDir()+ "/Trash" );
    if(!dir.exists())
        dir.mkpath(".");

     return dir.absolutePath();
}

QString Edir::trashFiles()
{

    QDir dir(trashDir()+ "/" );
    if(!dir.exists())
        dir.mkpath(".");


    return dir.absolutePath();

}

QString Edir::trashInfo()
{
    QDir dir(configDir()+ "/Trash/info" );
    if(!dir.exists())
        dir.mkpath(".");


    return dir.absolutePath();


}
