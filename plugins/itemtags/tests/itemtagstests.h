/*
    Copyright (c) 2014, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ITEMSYNCTESTS_H
#define ITEMSYNCTESTS_H

#include "tests/testinterface.h"

#include <QObject>

class ItemSyncTests : public QObject
{
    Q_OBJECT
public:
    explicit ItemSyncTests(const TestInterfacePtr &test, QObject *parent = NULL);

    static QStringList testTags();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void init();
    void cleanup();

    void userTags();
    void tag();
    void untag();
    void clearTags();
    void searchTags();

private:
    TestInterfacePtr m_test;
};

#endif // ITEMSYNCTESTS_H
