#ifndef CONTACTSENGINE
#define CONTACTSENGINE

#include <Plasma/DataEngine>

namespace KTelepathy
{
    class ContactsListModel;
}

class ContactsEngine:public Plasma::DataEngine
{
    Q_OBJECT
    
    KTelepathy::ContactsListModel *m_model;
public:
    ContactsEngine(QObject *parent, const QVariantList &args);
    ~ContactsEngine();
    void init();

protected:
    bool sourceRequestEvent(const QString& name);
    bool updateSourceEvent(const QString& source);
};

#endif