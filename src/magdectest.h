/*****************************************************************************
* Copyright 2015-2018 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef ATOOLSTEST_MAGDEC_TEST_H
#define ATOOLSTEST_MAGDEC_TEST_H

#include <QString>
#include <QtTest>

namespace atools {
namespace geo {
class Pos;
}
}

class MagdecTest :
  public QObject
{
  Q_OBJECT

public:
  MagdecTest();

  static void runtest(int argc, char *argv[]);

private slots:
  void initTestCase();
  void cleanupTestCase();

  void testOpen();
  void testMagdec_data();
  void testMagdec();

};

#endif // ATOOLSTEST_MAGDEC_TEST_H
