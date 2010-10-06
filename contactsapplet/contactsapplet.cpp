#include "contactsapplet.h"

#include <QtCore/QSizeF>
#include <QtCore/QMutex>
#include <QtGui/QFontMetrics>
#include <QtGui/QGraphicsLinearLayout>
#include <QtGui/QGraphicsWidget>
#include <QtGui/QPainter>

#include <Plasma/DataEngine>
#include <Plasma/Label>
#include <Plasma/ScrollWidget>
#include <Plasma/Theme>

#include <KTelepathy/ContactsListModel>

contactsapplet::contactsapplet(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args),
      m_contactsCount(0),
      m_layout(0),
      m_engine(0),
      m_contactsWidget(0)
{
    setBackgroundHints(DefaultBackground);
    setHasConfigurationInterface(true);
    setAspectRatioMode(Plasma::IgnoreAspectRatio);
    
    resize(300, 600);
}


contactsapplet::~contactsapplet()
{
    if (hasFailedToLaunch()) {
        // Do some cleanup here
    } else {
        // Save settings
    }
}

void contactsapplet::init()
{
    m_engine = dataEngine("contacts");
    m_engine->connectSource("count", this, 1000);
}

QGraphicsWidget* contactsapplet::graphicsWidget()
{
    if (m_contactsWidget) {
        return m_contactsWidget;
    }
    
    m_contactsWidget = new Plasma::ScrollWidget(this);
    m_layout = new QGraphicsLinearLayout(Qt::Vertical, m_contactsWidget);
    m_contactsWidget->setLayout(m_layout);
    
    Plasma::Label *contactsListLabel = new Plasma::Label;
    contactsListLabel->setText("Contacts List");
    m_layout->addItem(contactsListLabel);
    
    return m_contactsWidget;
}

void contactsapplet::dataUpdated(const QString& sourceName, const Plasma::DataEngine::Data& data)
{
    if (sourceName == "count") {
        m_dataUpdatedMutex->lock();
        for (int i = 0; i < data["Contact count"].toInt(); ++i) {
            QString num;
            num.setNum(i);
            Plasma::DataEngine::Data contact = m_engine->query(num);
            Plasma::Label *contactLabel = new Plasma::Label;
            contactLabel->setText(contact["Identifier"].toString());
            
            m_layout->addItem(contactLabel);
        }
        m_dataUpdatedMutex->unlock();
    }
}

#include "contactsapplet.moc"
