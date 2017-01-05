#ifndef MAME_H
#define MAME_H

#include <QObject>

class Mame : public QObject
{
    Q_OBJECT
public:
    explicit Mame(QObject *parent = 0);

    static QString getRomDescription(const QString &romName);

    static void run(const QString &romName);
};

#endif // MAME_H
