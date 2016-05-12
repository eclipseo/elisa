/*
 * Copyright 2016 Matthieu Gallien <matthieu_gallien@yahoo.fr>
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

#ifndef MUSICALBUM_H
#define MUSICALBUM_H

#include "musicaudiotrack.h"

#include <QtCore/QString>
#include <QtCore/QUrl>
#include <QtCore/QMap>

class MusicAlbum
{

public:

    MusicAlbum();

    QString mId;

    QString mParentId;

    int mTracksCount = 0;

    QString mTitle;

    QString mArtist;

    QUrl mAlbumArtURI;

    QUrl mResourceURI;

    QMap<quintptr, MusicAudioTrack> mTracks;

    QList<quintptr> mTrackIds;

};

#endif // MUSICALBUM_H