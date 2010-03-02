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

#ifndef PORTRAITRESOLVER_H
#define PORTRAITRESOLVER_H

#include <QDir>
#include <QFile>
#include <QHttp>
#include <QBuffer>
#include <QObject>
#include "PortraitRequest.h"

class	PortraitResolver : public QObject
{
	Q_OBJECT
	
public:
	PortraitResolver(void);
	~PortraitResolver(void);
	void	addRequest(const QStringList& logins);
	void	addRequest(const QString& login, bool fun);

	static QString	buildFilename(const QString& login, bool fun);
	
public slots:
	void	finished(int id, bool error);

signals:
	void	downloadedPortrait(const QString&);

private:
	void			setupPortraitDirectory(void);

	QDir					_dir;
	QHttp					_http;
	QList<PortraitRequest*>	_requests;
};

#endif // PORTRAITRESOLVER_H