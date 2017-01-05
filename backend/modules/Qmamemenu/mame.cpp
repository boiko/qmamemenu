#include "mame.h"
#include <QProcess>
#include <QDebug>
#include <QRegularExpression>

Mame::Mame(QObject *parent) : QObject(parent)
{

}

QString Mame::getRomDescription(const QString &romName)
{
    qDebug() << "Rom name:" << romName;
    QProcess proc;
    proc.start("/usr/games/mame", QStringList() << "-listfull" << romName);
    qDebug() << proc.arguments();
    proc.waitForFinished();
    QStringList output = QString(proc.readAllStandardOutput()).split("\n");
    if (output.count() < 2) {
        return QString();
    }
    return output[1].split("\"")[1].remove("\"");
}

void Mame::run(const QString &romName)
{
    QProcess *proc = new QProcess();
    QObject::connect(proc, SIGNAL(finished(int)), proc, SLOT(deleteLater()));
    proc->start("/usr/games/mame", QStringList() << "-skip_gameinfo" << romName);
}
