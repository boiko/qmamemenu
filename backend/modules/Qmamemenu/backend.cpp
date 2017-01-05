#include <QtQml>
#include <QtQml/QQmlContext>
#include "backend.h"
#include "mamerommodel.h"


void BackendPlugin::registerTypes(const char *uri)
{
    Q_ASSERT(uri == QLatin1String("Qmamemenu"));

    qmlRegisterType<MameRomModel>(uri, 1, 0, "MameRomModel");
}

void BackendPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    QQmlExtensionPlugin::initializeEngine(engine, uri);
}
