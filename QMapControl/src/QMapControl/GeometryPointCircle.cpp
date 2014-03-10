/*
*
* This file is part of QMapControl,
* an open-source cross-platform map widget
*
* Copyright (C) 2007 - 2008 Kai Winter
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with QMapControl. If not, see <http://www.gnu.org/licenses/>.
*
* Contact e-mail: kaiwinter@gmx.de
* Program URL   : http://qmapcontrol.sourceforge.net/
*
*/

#include "GeometryPointCircle.h"

namespace qmapcontrol
{
    GeometryPointCircle::GeometryPointCircle(const QPointF& point_coord, const int& radius_px, const AlignmentType& alignment_type, const QPen& pen, const int& zoom_minimum, const int& zoom_maximum)
            : GeometryPoint(point_coord, QPixmap(radius_px, radius_px), alignment_type, pen, zoom_minimum, zoom_maximum)
    {
        // Update the pixmap.
        updatePixmap();
    }

    GeometryPointCircle::GeometryPointCircle(const QPointF& point_coord, const AlignmentType& alignment_type, const QPen& pen, const int& zoom_minimum, const int& zoom_maximum)
            : GeometryPoint(point_coord, QPixmap(10.0, 10.0), alignment_type, pen, zoom_minimum, zoom_maximum)
    {
        // Update the pixmap.
        updatePixmap();
    }

    void GeometryPointCircle::updatePixmap()
    {
        // Fetch the current pixmap.
        QPixmap pixmap = getPixmap();

        // Reset the pixmap.
        pixmap.fill(Qt::transparent);

        // Create a painter for the pixmap.
        QPainter painter(&pixmap);

//#if !defined Q_WS_MAEMO_5 //FIXME Maemo has a bug - it will antialias our point out of existence
        painter.setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing);
//#endif

        // Set the pen.
        painter.setPen(getPen());

        // Draw the ellipse.
        painter.drawEllipse(QRectF(0.0, 0.0, pixmap.width(), pixmap.height()));

        // Set the new pixmap.
        setPixmap(pixmap);
    }
}