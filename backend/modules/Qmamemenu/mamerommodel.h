#ifndef MAMEROMMODEL_H
#define MAMEROMMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QDir>

class MameRom {
public:
    QString id;
    QString description;
    QString snapshotPath;
};

class MameRomModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum RomRole {
        IdRole = 0,
        DescriptionRole,
        SnapshotPathRole
    };

    MameRomModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const override;
    QHash<int,QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role) const override;

    Q_INVOKABLE void runRom(const QString &romId);

protected:
    void loadGames();

private:
    QList<MameRom> mRoms;
    QDir mMameDir;
    QDir mRomDir;
    QDir mSnapshotDir;
};

#endif // MAMEROMMODEL_H
