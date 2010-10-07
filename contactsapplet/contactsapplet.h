// Here we avoid loading the header multiple times
#ifndef CONTACTSAPPLET_HEADER
#define CONTACTSAPPLET_HEADER
// We need the Plasma Applet headers
#include <KIcon>

#include <Plasma/DataEngine>
#include <Plasma/PopupApplet>
#include <Plasma/TreeView>

class QSizeF;

class QGraphicsLinearLayout;
class QGraphicsWidget;
class QMutex;

namespace Plasma
{
    class ScrollWidget;
}

namespace KTelepathy
{
    class ContactsListModel;
}

// Define our plasma Applet
class contactsapplet : public Plasma::PopupApplet
{
    Q_OBJECT
    
    int m_contactsCount;
    QGraphicsLinearLayout *m_layout;
    QMutex *m_dataUpdatedMutex;
    Plasma::DataEngine *m_engine;
    QGraphicsWidget *m_contactsWidget;
    Plasma::ScrollWidget *m_scrollWidget;
    
public:
    // Basic Create/Destroy
    contactsapplet(QObject *parent, const QVariantList &args);
    ~contactsapplet();

    QGraphicsWidget *graphicsWidget();
    void init();
    
public slots:
    void dataUpdated(const QString &sourceName, const Plasma::DataEngine::Data &data);
};
 
// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(contactsapplet, contactsapplet)
#endif
