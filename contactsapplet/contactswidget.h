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


#ifndef CONTACTSWIDGET_H
#define CONTACTSWIDGET_H

#include <Plasma/Frame>
#include <Plasma/DataEngine>

#include <QtCore/QList>
#include <QtCore/QPointer>

class QGraphicsAnchorLayout;
class QGraphicsLinearLayout;
namespace Plasma
{
    class IconWidget;
    class Label;
    class ToolButton;
}

class ContactsWidget : public Plasma::Frame
{
    Q_OBJECT
    
    Plasma::IconWidget *m_avatar;
    Plasma::Label *m_identifier;
    QGraphicsAnchorLayout *m_layout;
    Plasma::Frame *m_contactsFrame;
    QGraphicsLinearLayout *m_contactsLayout;
    QList<QPointer<Plasma::Label> > *m_contacts;
    Plasma::ToolButton *m_talk;
    
public:
    ContactsWidget(QGraphicsWidget* parent);
    void setData(const Plasma::DataEngine::Data& data);
    
public slots:
    void dataUpdated(const QString &sourceName, const Plasma::DataEngine::Data &data);
};

#endif // CONTACTSWIDGET_H
