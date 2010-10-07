/*
    KTelepathy List of Contacts.
    Copyright (C) 2010  Luiz Romário Santana Rios

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include "contactsapplet.h"

#include "contactswidget.h"

#include <QtCore/QSizeF>
#include <QtGui/QGraphicsLinearLayout>
#include <QtGui/QGraphicsWidget>
#include <QtGui/QPainter>

#include <Plasma/DataEngine>
#include <Plasma/Label>
#include <Plasma/ScrollWidget>
#include <Plasma/Theme>

#include <KIconLoader>
#include <KTelepathy/ContactsListModel>
#include <QtGui/QPixmap>

contactsapplet::contactsapplet(QObject *parent, const QVariantList &args)
    : Plasma::PopupApplet(parent, args),
      m_contactsCount(0),
      m_layout(0),
      m_engine(0),
      m_contactsWidget(0),
      m_scrollWidget(0)
{
    setBackgroundHints(DefaultBackground);
    setHasConfigurationInterface(false);
    setAspectRatioMode(Plasma::IgnoreAspectRatio);
    QPixmap icon(32, 32);
    icon = KIconLoader::global()->loadIcon("telepathy", KIconLoader::Panel, 32);
    setPopupIcon(icon);
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
    QSizeF appletMinimumSize(200, 300);
    setMinimumSize(appletMinimumSize);
    
    resize(300, 550);
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
        QString num;
        for (int i = 0; i < data["Contact count"].toInt(); ++i) {
            num.setNum(i);
            Plasma::DataEngine::Data contact = m_engine->query(num);
            ContactsWidget *contactWidget = new ContactsWidget(m_scrollWidget);
            contactWidget->setData(contact);
            
            m_layout->addItem(contactWidget);
        }
    }
}

#include "contactsapplet.moc"
