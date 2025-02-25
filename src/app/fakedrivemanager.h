/*
 * AOSC Media Writer
 * Copyright (C) 2016 Martin Bříza <mbriza@redhat.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef FAKEDRIVEMANAGER_H
#define FAKEDRIVEMANAGER_H

#include <QObject>

#include "drivemanager.h"

class FakeDriveProvider : public DriveProvider
{
    Q_OBJECT
public:
    FakeDriveProvider(DriveManager *parent);
public slots:
    void createNewRestoreable();
    void createNewGetsDisconnected();
private slots:
    void connectDrives();
};

/**
 * @brief The Drive class
 *
 * Contains a fake drive implementation
 */
class FakeDrive : public Drive
{
    Q_OBJECT
public:
    FakeDrive(FakeDriveProvider *parent, const QString &name, uint64_t size, bool containsLive = false);

    Q_INVOKABLE virtual bool write(ReleaseVariant *data) override;
    Q_INVOKABLE virtual void cancel() override;
    Q_INVOKABLE virtual void restore() override;

private slots:
    void writingAdvanced();
    void restoringFinished();
    void selfdestruct();

private:
    bool m_writtenTo{false};
};

#endif // FAKEDRIVEMANAGER_H
