/***************************************************************************
**                                                                        **
**  QGrostlHash, an API wrapper bringing the optimized implementation of  **
**  Grøstl (http://www.groestl.info/) to Qt.                              **
**  Copyright (C) 2012 Emanuel Eichhammer                                 **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Emanuel Eichhammer                                   **
**  Website/Contact: http://www.WorksLikeClockwork.com/                   **
**             Date: 12.01.12                                             **
****************************************************************************/

#ifndef QGROSTLHASH_H
#define QGROSTLHASH_H

#include <QString>
#include <QByteArray>
#include <QFile>

namespace GrostlImpl {
class hashState;
}

class QGrostlHash
{
public:
  enum HashBits {hb256, hb512};
  QGrostlHash();
  QGrostlHash(const QString &asciiMessage, HashBits hashBits=hb256);
  ~QGrostlHash();
  QByteArray toRaw() const;
  QByteArray toHex() const;
  QString toHexString() const;
  bool file(const QString &fileName, HashBits hashBits=hb256, int blockSize=8388608); // 8 KiB default blockSize
  bool startBatch(HashBits hashBits=hb256);
  bool putBatch(const QByteArray &ba);
  bool putBatch(const char *data, int size);
  bool stopBatch();
  bool isBatchRunning() const;
protected:
  bool setHashBitLength(HashBits hashBits);
  GrostlImpl::hashState *mState;
  QByteArray mHashResult;
  int mHashBitLength;
};

#endif // QGROSTLHASH_H
