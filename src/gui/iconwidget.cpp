/*
    Copyright (c) 2013, Lukas Holecek <hluk@email.cz>

    This file is part of CopyQ.

    CopyQ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CopyQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with CopyQ.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "iconwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QString>

IconWidget::IconWidget(int icon, QWidget *parent)
    : QWidget(parent)
    , m_icon()
{
    QFont iconFont("FontAwesome");
    QFontMetrics fm(iconFont);
    QChar c(icon);
    if ( fm.inFont(c) )
        m_icon = QString(c);

    setFixedSize(sizeHint());
}

QSize IconWidget::sizeHint() const
{
    return m_icon.isEmpty() ? QSize(0, 0) : QSize(16, 16);
}

void IconWidget::paintEvent(QPaintEvent *)
{
    if (m_icon.isEmpty())
        return;

    QPainter p(this);

    QFont iconFont("FontAwesome");
    iconFont.setPixelSize(14);
    p.setFont(iconFont);
    p.setRenderHint(QPainter::TextAntialiasing, true);

    if (parentWidget())
        p.setPen( parentWidget()->palette().color(QPalette::Text) );
    p.drawText( QPoint(1, 15), m_icon);
}
