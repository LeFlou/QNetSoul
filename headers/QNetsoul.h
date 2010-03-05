/*
  Copyright 2009 Dally Richard
  This file is part of QNetSoul.
  QNetSoul is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  QNetSoul is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with QNetSoul.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QNETSOUL_H_
#define QNETSOUL_H_

#include <QtGui>
#include <QCryptographicHash>
#include "Chat.h"
#include "Options.h"
#include "Network.h"
#include "Contact.h"
#include "AddContact.h"
#include "ui_QNetsoul.h"
#include "PortraitResolver.h"
#include "VieDeMerde.h"
#include "ChuckNorrisFacts.h"

class	QMenu;
class	QAction;
class	QLabel;
class	QSystemTrayIcon;
class	ContactWidget;

class	QNetsoul : public QMainWindow, public Ui_QNetsoul
{
  Q_OBJECT

    public:
  QNetsoul(QWidget* parent = 0);
  virtual ~QNetsoul(void);

 protected:
  void	closeEvent(QCloseEvent*);

  private slots:
  void	connectToServer(void);
  void	disconnect(void);
  void	updateMenuBar(const QAbstractSocket::SocketState&);
  void	updateStatusBar(const QAbstractSocket::SocketState&);
  void	updateStatusComboBox(const QAbstractSocket::SocketState&);

  void	showMessageInBalloon(const QString& message);
  void	toggleConnection(void);
  void	saveStateBeforeQuiting(void);
  void	showConversation(const QModelIndex&);
  void	openAddContactDialog(void);
  void	openOptionsDialog(QLineEdit* newLineFocus = 0);
  void	loadContacts(void);
  void	saveContactsAs(void);
  void	toggleSortContacts(void);
  void	handleClicksOnTrayIcon(QSystemTrayIcon::ActivationReason);
  void	addContact(void);
  void	addContact(const QList<Contact>);
  void	addContact(const QString&, const QString& alias = "");
  void	removeSelectedContact(void);
  void	refreshContacts(void) const;
  void	sendStatus(const int&) const;
  void	changeStatus(const QString&, const QString&, const QString&);
  void	updateContact(const QStringList&);
  void	showConversation(const QString& login, const QString& message = "");
  void	processHandShaking(int, QStringList);
  void	transmitMsg(const QString&, const QString&);
  void	transmitTypingStatus(const QString&, bool);
  void	notifyTypingStatus(const QString&, bool);
  void	setPortrait(const QString&);
  void	aboutQNetSoul(void);
  void	setProxy(const QNetworkProxy& proxy = QNetworkProxy());

 private:
  void				configureProxy(void);
  Chat*				getChat(const QString&);
  bool				doesThisContactAlreadyExist(const QString&) const;
  ContactWidget*		getContact(const QString&) const;
  QStringList			getContactLogins(void) const;
  QList<ContactWidget*>		getContactWidgets(void) const;
  void				watchLogContacts(void);
  void				watchLogContact(const QString&);
  void				refreshContact(const QString&) const;
  void				resetAllContacts(void);
  void				setupTrayIcon(void);
  void				setupStatusButton(void);
  void				readSettings(void);
  void				writeSettings(void);
  void				loadContacts(const QString&);
  void				saveContacts(const QString&);
  void				connectQNetsoulItems(void);
  void				connectActionsSignals(void);
  void				connectNetworkSignals(void);
  Chat*				createWindowChat(const QString&);
  void				deleteAllWindowChats(void);

  QPushButton*			_statusPushButton;
  Network*			_network;
  Options*			_options;
  AddContact*			_addContact;
  QStandardItemModel*		_standardItemModel;
  QSystemTrayIcon*		_trayIcon;
  QHash<QString, Chat*>		_windowsChat;
  QString			_timeStamp;
  QPoint			_oldPos;
  PortraitResolver		_portraitResolver;
  VieDeMerde			_vdm;
  ChuckNorrisFacts		_cnf;
};

#endif // QNETSOUL_H_
