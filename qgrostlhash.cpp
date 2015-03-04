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

#include "qgrostlhash.h"
#include <QDebug>

#include "grostlimpl.cpp"

QGrostlHash::QGrostlHash() :
  mState(0),
  mHashBitLength(0)
{
}

QGrostlHash::QGrostlHash(const QString &asciiMessage, HashBits hashBits) :
  mState(0),
  mHashBitLength(0)
{
  if (!setHashBitLength(hashBits))
    return;
  
  bool success = false;
  QByteArray msg = asciiMessage.toUtf8();
  
  mState = new GrostlImpl::hashState;
  if (GrostlImpl::Init(mState, mHashBitLength) == GrostlImpl::SUCCESS)
  {
    if (GrostlImpl::Update(mState, (GrostlImpl::BitSequence*)msg.constData(), msg.size()*8) == GrostlImpl::SUCCESS)
    {
      if (GrostlImpl::Final(mState, (GrostlImpl::BitSequence*)mHashResult.data()) == GrostlImpl::SUCCESS)
        success = true;
    }
  }
  delete mState;
  mState = 0;
  
  if (!success)
  {
    mHashResult.clear();
    qDebug() << "QGrostlHash::QGrostlHash(): hash construction failed";
  }
}

QGrostlHash::~QGrostlHash()
{
  if (mState)
    delete mState;
}

QByteArray QGrostlHash::toRaw() const
{
  return mHashResult;
}

QByteArray QGrostlHash::toHex() const
{
  return mHashResult.toHex();
}

QString QGrostlHash::toHexString() const
{
  return QString(mHashResult.toHex());
}

bool QGrostlHash::file(const QString &fileName, HashBits hashBits, int blockSize)
{
  if (isBatchRunning() || blockSize < 1)
    return false;
  if (!setHashBitLength(hashBits))
    return false;
  QFile file(fileName);
  if (file.open(QFile::ReadOnly))
  {
    qint64 fileSize = file.size();
    qint64 readBytes = 0;
    if (!startBatch())
      return false;
    bool success = true;
    char *buffer = new char[blockSize];
    // repeatedly read blockSize bytes of the file to buffer and pass it to putBatch:
    while (file.error() == QFile::NoError)
    {
      readBytes = file.read(buffer, qMin(fileSize-file.pos(), (qint64)blockSize)); // read till end of file to buffer, but not more than blockSize bytes
      if (readBytes > 0)
      {
        if (!putBatch(buffer, readBytes))
        {
          success = false;
          break;
        }
        if (readBytes < blockSize) // that was the last block
          break;
      } else // error occured
      {
        success = false;
        break;
      }
    }
    delete buffer;
    if (!stopBatch())
      success = false;
    return success;
  } else
    return false;
}

bool QGrostlHash::startBatch(HashBits hashBits)
{
  if (isBatchRunning())
    return false;
  if (!setHashBitLength(hashBits))
    return false;
  mState = new GrostlImpl::hashState;
  bool success = GrostlImpl::Init(mState, mHashBitLength) == GrostlImpl::SUCCESS;
  if (!success)
  {
    delete mState;
    mState = 0;
    mHashResult.clear();
  }
  return success;
}

bool QGrostlHash::putBatch(const QByteArray &ba)
{
  return putBatch(ba.constData(), ba.size());
}

bool QGrostlHash::putBatch(const char *data, int size)
{
  if (!isBatchRunning() || mHashBitLength == 0)
    return false;
  bool success = GrostlImpl::Update(mState, (GrostlImpl::BitSequence*)data, size*8) == GrostlImpl::SUCCESS;
  if (!success)
  {
    delete mState;
    mState = 0;
    mHashResult.clear();
  }
  return success;
}

bool QGrostlHash::stopBatch()
{
  if (!isBatchRunning() || mHashBitLength == 0)
    return false;
  bool success = GrostlImpl::Final(mState, (GrostlImpl::BitSequence*)mHashResult.data()) == GrostlImpl::SUCCESS;
  delete mState;
  mState = 0;
  if (!success)
    mHashResult.clear();
  return success;
}

bool QGrostlHash::isBatchRunning() const
{
  return mState;
}

bool QGrostlHash::setHashBitLength(HashBits hashBits)
{
  switch (hashBits)
  {
    case hb256: mHashBitLength = 256; break;
    case hb512: mHashBitLength = 512; break;
    default: 
    {
      mHashBitLength = 0;
      qDebug() << "QGrostlHash::setHashBitLength(): invalid hash bit value" << (int)hashBits << ", must be hb256 or hb512";
      return false;
    }
  }
  mHashResult.fill(0, mHashBitLength/8);
  return true;
}

