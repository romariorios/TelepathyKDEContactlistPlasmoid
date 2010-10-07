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

#include <Plasma/Label>
#include <Plasma/ToolButton>
#include <QtGui/QGraphicsAnchorLayout>

ContactsWidget::ContactsWidget(QGraphicsWidget* parent) :
        Plasma::Frame(parent),
        m_identifier(new Plasma::Label),
        m_talk(new Plasma::ToolButton)
{
    m_talk->setText(i18n("Talk"));
    
    QGraphicsAnchorLayout *layout = new QGraphicsAnchorLayout(this);
    layout->setSpacing(5);
    layout->addAnchor(m_identifier, Qt::AnchorBottom, m_talk, Qt::AnchorTop);
}
void ContactsWidget::setData(const Plasma::DataEngine::Data& data)
{
    m_identifier->setText(data["Identifier"].toString());
}


