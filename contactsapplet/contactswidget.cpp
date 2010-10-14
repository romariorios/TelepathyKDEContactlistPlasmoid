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
#include "contactswidget.h"

#include <Plasma/IconWidget>
#include <Plasma/Label>
#include <Plasma/ToolButton>
#include <QtGui/QGraphicsAnchorLayout>
#include <QtGui/QGraphicsLinearLayout>
#include <QtGui/QPainter>
#include <QtGui/QPixmap>

#include <QDebug>

ContactsWidget::ContactsWidget(QGraphicsWidget* parent) :
        Plasma::Frame(parent),
        m_avatar(new Plasma::IconWidget(this)),
        m_identifier(new Plasma::Label(this)),
        m_layout(new QGraphicsAnchorLayout(this)),
        m_contactsFrame(new Plasma::Frame(this)),
        m_contactsLayout(new QGraphicsLinearLayout(Qt::Vertical, m_contactsFrame)),
        m_contacts(new QList<QPointer<Plasma::Label> >),
        m_talk(new Plasma::ToolButton(this))
{
    m_talk->setText(i18n("Talk"));
    
    m_layout->setSpacing(5);
    m_layout->addCornerAnchors(m_layout, Qt::TopLeftCorner, m_avatar, Qt::TopLeftCorner);
    m_layout->addCornerAnchors(m_avatar, Qt::TopRightCorner, m_identifier, Qt::TopLeftCorner);
    m_layout->addCornerAnchors(m_layout, Qt::BottomRightCorner, m_talk, Qt::BottomRightCorner);
    m_layout->addCornerAnchors(m_avatar, Qt::BottomLeftCorner, m_contactsFrame, Qt::TopLeftCorner);
    
    m_contactsFrame->setLayout(m_contactsLayout);
    
    setMinimumHeight(m_identifier->minimumHeight() + m_talk->minimumHeight() + 15);
}
void ContactsWidget::setData(const Plasma::DataEngine::Data& data)
{
    setMinimumHeight(m_identifier->minimumHeight() + m_talk->minimumHeight() + 15);
    m_identifier->setText(data["Identifier"].toString());
    QPixmap *avatar = reinterpret_cast<QPixmap*>(const_cast<void*>(data["Avatar"].data()));
    m_avatar->setIcon(*avatar);
    QStringList contacts = data["Contacts"].toStringList();
    for (int i = 0; i < contacts.count(); ++i) {
        qDebug() << i;
        qDebug() << contacts.count();
        qDebug() << m_contacts->count();
        if (i < m_contacts->count()) {
            qDebug() << "Contact succesfully reused.";
            m_contacts->at(i)->setText(contacts[i]);
        }
        else {
            Plasma::Label *contactLabel = new Plasma::Label(this);
            contactLabel->setText(contacts[i]);
            m_contacts->append(contactLabel);
            m_contactsLayout->addItem(contactLabel);
            setMinimumHeight(minimumHeight() + contactLabel->size().height());
        }
        qDebug() << "---";
    }
}

void ContactsWidget::dataUpdated(const QString& sourceName, const Plasma::DataEngine::Data& data)
{
    if (!(sourceName.toInt() == 0 && sourceName != "0" && sourceName.toInt() >= data["Contact count"].toInt())) {
        setData(data);
    }
}
