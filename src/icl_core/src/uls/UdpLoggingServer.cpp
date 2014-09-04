// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Klaus Uhl <uhl@fzi.de>
 * \date    2010-06-16
 *
 */
//----------------------------------------------------------------------
#include <QtCore/QByteArray>
#include <QtCore/QStringList>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <iostream>

#include "UdpLoggingServer.h"

UdpLoggingServer::UdpLoggingServer(const QString& db_filename)
{
  // UDP socket stuff.
  m_udp_socket = new QUdpSocket(this);
  m_udp_socket->bind(60000, QUdpSocket::ShareAddress);

  connect(m_udp_socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));

  // Database stuff
  m_db = QSqlDatabase::addDatabase("QSQLITE");
  m_db.setDatabaseName(db_filename);
  m_db.open();

  bool log_entries_exists = false;
  foreach(QString table, m_db.tables(QSql::AllTables))
  {
    if (table == "log_entries")
    {
      log_entries_exists = true;
    }
  }
  if (!log_entries_exists)
  {
    m_db.exec("CREATE TABLE log_entries ("
              "system_name TEXT,"
              "timestamp TEXT, timestamp_ns INTEGER, "
              "log_level TEXT, log_stream TEXT, "
              "file TEXT, line INTEGER, "
              "class TEXT, object TEXT, function TEXT, "
              "message TEXT)");
  }
}

UdpLoggingServer::~UdpLoggingServer()
{
}

void UdpLoggingServer::processPendingDatagrams()
{
  while (m_udp_socket->hasPendingDatagrams())
  {
    QByteArray datagram;
    datagram.resize(m_udp_socket->pendingDatagramSize());
    m_udp_socket->readDatagram(datagram.data(), datagram.size());

    QString sql = "INSERT INTO log_entries VALUES (";
    sql.append(datagram.data());
    sql.append(")");
    m_db.exec(sql);
  }
}
