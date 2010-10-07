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
#include "contactsengine.h"

#include <KTelepathy/ContactsListModel>

#include <QDebug>

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
    if (source == "count") {
        setData(source, "Contact count", m_model->rowCount());
        qDebug() << m_model->rowCount();
        return true;
    }
    if (source.toInt() == 0 and source != "0") {
        return false;
    }
    QModelIndex mi = m_model->index(source.toInt(), 0);
    setData(source, "Identifier", mi.data());
    setData(source, "Status icon", mi.data(Qt::DecorationRole));
    
    return true;
}

K_EXPORT_PLASMA_DATAENGINE(contacts, ContactsEngine)

#include "contactsengine.moc"
