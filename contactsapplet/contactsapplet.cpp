#include "contactsapplet.h"

#include <QtCore/QSizeF>
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
    : Plasma::PopupApplet(parent, args),
      m_contactsCount(0),
      m_layout(0),
      m_engine(0),
      m_contactsWidget(0),
      m_scrollWidget(0)
{
    setBackgroundHints(DefaultBackground);
    setHasConfigurationInterface(true);
    setAspectRatioMode(Plasma::IgnoreAspectRatio);
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
    m_engine->connectSource("count", this, 5000);
    QSizeF appletMinimumSize(100, 100);
    sizeHint(Qt::MinimumSize, appletMinimumSize);
}

QGraphicsWidget* contactsapplet::graphicsWidget()
{
    if (m_scrollWidget) {
        return m_scrollWidget;
    }
    
    m_scrollWidget = new Plasma::ScrollWidget(this);
    
    m_contactsWidget = new Plasma::ScrollWidget(m_scrollWidget);
    m_layout = new QGraphicsLinearLayout(Qt::Vertical, m_contactsWidget);
    m_contactsWidget->setLayout(m_layout);
    m_scrollWidget->setWidget(m_contactsWidget);
    
    Plasma::Label *contactsListLabel = new Plasma::Label;
    contactsListLabel->setText("Contacts List");
    m_layout->addItem(contactsListLabel);
    
    QSizeF listMinimumSize(200, 300);
    m_scrollWidget->setMinimumSize(listMinimumSize);
    
    return m_scrollWidget;
}

void contactsapplet::dataUpdated(const QString& sourceName, const Plasma::DataEngine::Data& data)
{
    if (sourceName == "count" && m_contactsCount != data["Contact count"].toInt()) {
        m_contactsCount = data["Contact count"].toInt();
        for (int i = 0; i < data["Contact count"].toInt(); ++i) {
            QString num;
            num.setNum(i);
            Plasma::DataEngine::Data contact = m_engine->query(num);
            Plasma::Label *contactLabel = new Plasma::Label;
            contactLabel->setText(contact["Identifier"].toString());
            
            m_layout->addItem(contactLabel);
        }
    }
}

#include "contactsapplet.moc"
