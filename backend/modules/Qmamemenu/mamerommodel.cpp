#include "mamerommodel.h"
#include "mame.h"
#include <QDir>
#include <QDebug>

MameRomModel::MameRomModel(QObject *parent)
: QAbstractListModel(parent), mMameDir(QDir::home().absoluteFilePath("mame")),
  mRomDir(mMameDir.filePath("roms")), mSnapshotDir(mMameDir.absoluteFilePath("snaps"))
{
    loadGames();
}

int MameRomModel::rowCount(const QModelIndex &parent) const
{
    return mRoms.count();
}

QHash<int, QByteArray> MameRomModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[DescriptionRole] = "description";
    roles[SnapshotPathRole] = "snapshotPath";
    return roles;
}

QVariant MameRomModel::data(const QModelIndex &index, int role) const
{
    QVariant result;
    if (index.row() < 0 || index.row() >= mRoms.count()) {
        return result;
    }

    MameRom rom = mRoms[index.row()];
    switch (role) {
    case IdRole:
        result = rom.id;
        break;
    case DescriptionRole:
        result = rom.description;
        break;
    case SnapshotPathRole:
        result = rom.snapshotPath;
        break;
    }
    return result;
}

void MameRomModel::runRom(const QString &romId)
{
    Mame::run(romId);
}

void MameRomModel::loadGames()
{
    QStringList roms = mRomDir.entryList(QDir::Files);

    Q_FOREACH(QString romId, roms) {

        // ignore those support files
        if (romId.startsWith("namco")) {
            continue;
        }
        qDebug() << "Adding rom " << romId;

        romId.remove(".zip");
        MameRom rom;
        rom.id = romId;
        rom.description = Mame::getRomDescription(romId);
        if (mSnapshotDir.exists(romId + ".png")) {
            rom.snapshotPath = mSnapshotDir.absoluteFilePath(romId + ".png");
        }
        mRoms.append(rom);
    }

    beginInsertRows(QModelIndex(), 0, mRoms.count()-1);
    endInsertRows();
}

