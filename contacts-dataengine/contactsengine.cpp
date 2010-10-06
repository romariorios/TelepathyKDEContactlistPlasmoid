#include "contactsengine.h"

#include <KTelepathy/ContactsListModel>

ContactsEngine::ContactsEngine(QObject* parent, const QVariantList& args): DataEngine(parent, args)
{
    Q_UNUSED(args);
    setMinimumPollingInterval(500);
    m_model = new KTelepathy::ContactsListModel;
}
ContactsEngine::~ContactsEngine()
{
    delete m_model;
}
void ContactsEngine::init()
{
    for (int i = 0; i < m_model->rowCount(); ++i) {
        QString s;
        updateSourceEvent(s.setNum(i));
    }
}

bool ContactsEngine::sourceRequestEvent(const QString& name)
{
    return updateSourceEvent(name);
}
bool ContactsEngine::updateSourceEvent(const QString& source)
{
    if (source.toInt() == 0 and source != "0") {
        return false;
    }
    if (source == "count") {
        setData(source, "Contact count", m_model->rowCount());
    }
    QModelIndex mi = m_model->index(source.toInt(), 0);
    setData(source, "Identifier", mi.data());
    setData(source, "Status icon", mi.data(Qt::DecorationRole));
    
    return true;
}

K_EXPORT_PLASMA_DATAENGINE(contacts, ContactsEngine)

#include "contactsengine.moc"
