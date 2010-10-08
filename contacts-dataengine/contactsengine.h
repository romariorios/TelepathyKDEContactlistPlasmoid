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
#ifndef CONTACTSENGINE
#define CONTACTSENGINE

#include <Plasma/DataEngine>

#include <KTelepathy/PeopleManager>

class ContactsEngine:public Plasma::DataEngine
{
    Q_OBJECT
    
    KTelepathy::PersonSetPtr m_personSet;
public:
    ContactsEngine(QObject *parent, const QVariantList &args);
    ~ContactsEngine();
    void init();

protected:
    bool sourceRequestEvent(const QString& name);
    bool updateSourceEvent(const QString& source);
};

#endif