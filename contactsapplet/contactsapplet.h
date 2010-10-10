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

#ifndef CONTACTSAPPLET_HEADER
#define CONTACTSAPPLET_HEADER

#include <Plasma/DataEngine>
#include <Plasma/PopupApplet>
#include <QtCore/QList>

class ContactsWidget;

class QSizeF;

class QGraphicsLinearLayout;
class QGraphicsWidget;

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
    QGraphicsLinearLayout *m_contactsLayout, *m_layout;
    QList<ContactsWidget*> *m_contactsWidgetList;
    Plasma::DataEngine *m_engine;
    QGraphicsWidget *m_contactsWidget, *m_mainWidget;
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
