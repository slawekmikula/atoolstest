/*****************************************************************************
* Copyright 2015-2020 Alexander Barthel alex@littlenavmap.org
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

#include "scenerycfgtest.h"

#include "fs/scenery/scenerycfg.h"
#include "fs/scenery/addonpackage.h"
#include "fs/xp/scenerypacks.h"

using atools::fs::scenery::SceneryCfg;
using atools::fs::scenery::SceneryArea;
using atools::fs::scenery::AddOnPackage;

using atools::fs::xp::SceneryPack;
using atools::fs::xp::SceneryPacks;

SceneryCfgTest::SceneryCfgTest()
{

}

void SceneryCfgTest::runtest(int argc, char *argv[])
{
  SceneryCfgTest tst;
  QTest::qExec(&tst, argc, argv);
}

void SceneryCfgTest::testXplane()
{
  // I
  // 1000 Version
  // SCENERY
  //
  // SCENERY_PACK Custom Scenery/Norway ENBN tdg/
  // SCENERY_PACK Custom Scenery/Svalbard1/
  // SCENERY_PACK Custom Scenery/LNMY Test Intl äöü ÄÖÜß_'
  // SCENERY_PACK Custom Scenery/WA0B Susi Air Idedua Airstrip/
  // SCENERY_PACK_DISABLED /home/USER/Projekte/atoolstest/testdata/X-Plane Landmarks - Sydney/
  // SCENERY_PACK ../X-Plane Landmarks - Sydney/
  // SCENERY_PACK Custom Scenery/Does not exist/
  // SCENERY_PACK Custom Scenery/No apt.dat/
  // SCENERY_PACK Custom Scenery/ZYYJ_Yanji/
  // SCENERY_PACK Custom Scenery/ZBYN v1/
  // SCENERY_PACK Custom Scenery/Global Airports/
  // SCENERY_PACK_DISABLED Custom Scenery/ZYYJ_Yanji/

  SceneryPacks packs;
  packs.read("testdata/X-Plane");

  QCOMPARE(packs.getEntries().size(), 9);

  int idx = 0;
  // SCENERY_PACK Custom Scenery/Norway ENBN tdg/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.endsWith(QString("Norway ENBN tdg") + QDir::separator() +
                                                        "Earth nav data" + QDir::separator() + "apt.dat"), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx).valid, true);
  QCOMPARE(packs.getEntries().at(idx++).errorText.isEmpty(), true);

  // SCENERY_PACK Custom Scenery/Svalbard1/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.endsWith(QString("Svalbard1") + QDir::separator() + "Earth nav data" +
                                                        QDir::separator() + "apt.dat"), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx).valid, true);
  QCOMPARE(packs.getEntries().at(idx++).errorText.isEmpty(), true);

  // SCENERY_PACK Custom Scenery/LNMY Test Intl äöü ÄÖÜß_'/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.endsWith(QString("LNMY Test Intl äöü ÄÖÜß_'") + QDir::separator() +
                                                        "Earth nav data" + QDir::separator() + "apt.dat"), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx).valid, true);
  QCOMPARE(packs.getEntries().at(idx++).errorText.isEmpty(), true);

  // SCENERY_PACK Custom Scenery/WA0B Susi Air Idedua Airstrip/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.endsWith(QString("WA0B Susi Air Idedua Airstrip") + QDir::separator() +
                                                        "Earth nav data" + QDir::separator() + "apt.dat"), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx).valid, true);
  QCOMPARE(packs.getEntries().at(idx++).errorText.isEmpty(), true);

  // SCENERY_PACK /home/USER/Projekte/atoolstest/testdata/X-Plane Landmarks - Sydney/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.contains(QString( "X-Plane Landmarks - Sydney")), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx).valid, false);
  QCOMPARE(packs.getEntries().at(idx++).errorText.isEmpty(), false);

  // SCENERY_PACK ../X-Plane Landmarks - Sydney/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.endsWith(QString("X-Plane Landmarks - Sydney") + QDir::separator() +
                                                        "Earth nav data" + QDir::separator() + "apt.dat"), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx).valid, true);
  QCOMPARE(packs.getEntries().at(idx++).errorText.isEmpty(), true);

  // SCENERY_PACK Custom Scenery/Does not exist/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.contains(QString("Does not exist")), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx).valid, false);
  QCOMPARE(packs.getEntries().at(idx++).errorText.isEmpty(), false);

  // SCENERY_PACK Custom Scenery/No apt.dat/
  // ignored

  // SCENERY_PACK_BROKEN Custom Scenery/Broken/
  QCOMPARE(packs.getEntries().at(0).disabled, false);
  QCOMPARE(packs.getEntries().at(0).valid, true);

  // SCENERY_PACK Custom Scenery/ZYYJ_Yanji/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.endsWith(QString("ZYYJ_Yanji") + QDir::separator() + "Earth nav data" +
                                                        QDir::separator() + "apt.dat"), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, false);
  QCOMPARE(packs.getEntries().at(idx++).valid, true);

  // SCENERY_PACK Custom Scenery/ZBYN v1/
  // ignored

  // SCENERY_PACK_DISABLED Custom Scenery/ZYYJ_Yanji/
  qInfo() << packs.getEntries().at(idx).filepath;
  qInfo() << packs.getEntries().at(idx).errorText;
  QCOMPARE(packs.getEntries().at(idx).filepath.endsWith(QString("ZYYJ_Yanji") + QDir::separator() + "Earth nav data" +
                                                        QDir::separator() + "apt.dat"), true);
  QCOMPARE(packs.getEntries().at(idx).disabled, true);
  QCOMPARE(packs.getEntries().at(idx++).valid, true);

  const SceneryPack *entry = packs.getEntryByPath(packs.getEntries().first().filepath);
  QCOMPARE(entry->filepath.endsWith(QString("Norway ENBN tdg") + QDir::separator() + "Earth nav data" +
                                    QDir::separator() + "apt.dat"), true);
  QCOMPARE(entry->disabled, false);
  QCOMPARE(entry->valid, true);

  const SceneryPack *entry2 = packs.getEntryByPath(packs.getEntries().last().filepath);
  QCOMPARE(entry2->filepath.endsWith(QString("ZYYJ_Yanji") + QDir::separator() + "Earth nav data" + QDir::separator() +
                                     "apt.dat"), true);
  QCOMPARE(entry2->disabled, true);
  QCOMPARE(entry2->valid, true);

  const SceneryPack *entry3 = packs.getEntryByPath("Not existing filepath");
  QVERIFY(entry3 == nullptr);
}

void SceneryCfgTest::testFsx()
{
  QString specialCharsPath(QString("Addon Scenery") + QDir::separator() + "TEST äöü~ÄÖÜß§^°|" + QDir::separator());
  QString specialCharsTitle("TEST äöü~ÄÖÜß§^°|\\");

  QString codec("Windows-1252");
  SceneryCfg cfg(codec);
  cfg.read(":/test/resources/scenery_fsx_cfg");

  const QList<SceneryArea>& areas = cfg.getAreas();
  QCOMPARE(areas.size(), 203);

  QCOMPARE(areas.at(areas.size() - 1).getTitle(), specialCharsTitle);
  QCOMPARE(areas.at(areas.size() - 2).getLocalPath(), specialCharsPath);
}

void SceneryCfgTest::testP3dv4()
{
  QString specialCharsPath(QString("Addon Scenery") + QDir::separator() + "TEST äöü~ÄÖÜß§^°|" + QDir::separator());
  QString specialCharsTitle("TEST äöü~ÄÖÜß§^°|\\");

  QString specialChars("TEST äöü~ÄÖÜß§^°|\\");
  QString codec("UTF-8");
  SceneryCfg cfg(codec);
  cfg.read(":/test/resources/scenery_p3dv4.cfg");

  const QList<SceneryArea>& areas = cfg.getAreas();
  QCOMPARE(areas.size(), 196);

  QCOMPARE(areas.at(areas.size() - 1).getTitle(), specialCharsTitle);
  QCOMPARE(areas.at(areas.size() - 2).getLocalPath(), specialCharsPath);
}

void SceneryCfgTest::testP3dv4AddOn()
{
  AddOnPackage package(":/test/resources/add-on.xml");

  QCOMPARE(package.getName(), QLatin1Literal("MyAddOn"));
  QCOMPARE(package.getDescription(), QString("My Add-on developed by My Company äöüß."));
  QCOMPARE(package.getBaseDirectory(), QString(":/test/resources"));
  QCOMPARE(package.getFilename(), QString(":/test/resources/add-on.xml"));

  QCOMPARE(package.getComponents().at(0).getName(), QLatin1Literal("Scenery01"));
  QCOMPARE(package.getComponents().at(0).getPath(), QLatin1Literal("Content\\Scenery\\Scenery01"));
  QCOMPARE(package.getComponents().at(0).getCategory(), QLatin1Literal("Scenery"));
  QCOMPARE(package.getComponents().at(0).getLayer(), -1);

  QCOMPARE(package.getComponents().at(1).getName(), QLatin1Literal("Scenery02"));
  QCOMPARE(package.getComponents().at(1).getPath(), QLatin1Literal("C:\\Content\\Scenery\\Scenery02"));
  QCOMPARE(package.getComponents().at(1).getCategory(), QLatin1Literal("Scenery"));
  QCOMPARE(package.getComponents().at(1).getLayer(), 99);
}

void SceneryCfgTest::testP3dv4AddOn2()
{
  AddOnPackage package(":/test/resources/add-on_copy.xml");

  QCOMPARE(package.getName(), QString());
  QCOMPARE(package.getDescription(), QString());
  QCOMPARE(package.getBaseDirectory(), QString(":/test/resources"));
  QCOMPARE(package.getFilename(), QString(":/test/resources/add-on_copy.xml"));

  QCOMPARE(package.getComponents().at(0).getName(), QLatin1Literal("Scenery01"));
  QCOMPARE(package.getComponents().at(0).getPath(), QLatin1Literal("Content\\Scenery\\Scenery01"));
  QCOMPARE(package.getComponents().at(0).getCategory(), QLatin1Literal("Scenery"));
  QCOMPARE(package.getComponents().at(0).getLayer(), -1);

  QCOMPARE(package.getComponents().at(1).getName(), QLatin1Literal("Scenery02"));
  QCOMPARE(package.getComponents().at(1).getPath(), QLatin1Literal("C:\\Content\\Scenery\\Scenery02"));
  QCOMPARE(package.getComponents().at(1).getCategory(), QLatin1Literal("Scenery"));
  QCOMPARE(package.getComponents().at(1).getLayer(), 99);
}

void SceneryCfgTest::testP3dv4AddOnUtf16()
{
  AddOnPackage package(":/test/resources/add-on-utf-16.xml");

  QCOMPARE(package.getName(), QLatin1Literal("Flightbeam - KMSP"));
  QCOMPARE(package.getDescription(), QLatin1Literal("Flightbeam - Minneapolis St. Paul Intl. Airport for Prepar3D"));
  QCOMPARE(package.getBaseDirectory(), QLatin1Literal(":/test/resources"));
  QCOMPARE(package.getFilename(), QLatin1Literal(":/test/resources/add-on-utf-16.xml"));

  QCOMPARE(package.getComponents().at(0).getName(), QLatin1Literal("Flightbeam - KMSP scenery"));
  QCOMPARE(package.getComponents().at(0).getPath(),
           QLatin1Literal("G:\\Program Files\\Lockheed Martin\\Prepar3D v4\\Flightbeam\\Flightbeam - KMSP\\scenery"));
  QCOMPARE(package.getComponents().at(0).getCategory(), QLatin1Literal("Scenery"));
  QCOMPARE(package.getComponents().at(0).getLayer(), -1);

}

void SceneryCfgTest::testP3dv4AddOnEncodingMismatch()
{
  AddOnPackage package(":/test/resources/add-on_encoding_mismatch.xml");
  QCOMPARE(package.getDescription(), QString("Sends simulator reports to Navigraph Charts öäüÖÜ"));
}

void SceneryCfgTest::testP3dv4AddOnNoEncoding()
{
  AddOnPackage package(":/test/resources/add-on_win_encoding_no_bom.xml");
  QCOMPARE(package.getDescription(), QString("Sends simulator reports to Navigraph Charts öäüÖÄÜ"));

}
