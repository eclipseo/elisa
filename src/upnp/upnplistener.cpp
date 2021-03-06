/*
 * Copyright 2016-2017 Matthieu Gallien <matthieu_gallien@yahoo.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "upnplistener.h"

#include "databaseinterface.h"
#include "upnpdiscoverallmusic.h"
#include "upnpssdpengine.h"

class UpnpListenerPrivate
{
public:

    UpnpDiscoverAllMusic mUpnpManager;

    UpnpSsdpEngine mSsdpEngine;

};

UpnpListener::UpnpListener(QObject *parent) : QObject(parent), d(new UpnpListenerPrivate)
{
    d->mSsdpEngine.initialize();
    d->mSsdpEngine.searchAllUpnpDevice();

    d->mUpnpManager.setDeviceId(QStringLiteral("urn:schemas-upnp-org:service:ContentDirectory:1"));

    connect(&d->mSsdpEngine, &UpnpSsdpEngine::newService,
            &d->mUpnpManager, &UpnpDiscoverAllMusic::newDevice);
    connect(&d->mSsdpEngine, &UpnpSsdpEngine::removedService,
            &d->mUpnpManager, &UpnpDiscoverAllMusic::removedDevice);
}

UpnpListener::~UpnpListener()
= default;

DatabaseInterface *UpnpListener::databaseInterface() const
{
    return nullptr;
}

void UpnpListener::setDatabaseInterface(DatabaseInterface *model)
{
    d->mUpnpManager.setAlbumDatabase(model);

    Q_EMIT databaseInterfaceChanged();
}

void UpnpListener::applicationAboutToQuit()
{
}


#include "moc_upnplistener.cpp"
