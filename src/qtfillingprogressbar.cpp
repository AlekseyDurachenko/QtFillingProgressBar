// Copyright (C) 2013-2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
#include "qtfillingprogressbar.h"
#include <QPaintEvent>
#include <QPainter>

QtFillingProgressBar::QtFillingProgressBar(QWidget *parent) : QWidget(parent)
{
    m_max = 100.0;
    m_min = 0.0;
    m_value = 0.0;
    m_progressColor = Qt::darkBlue;
    m_backgroundColor = Qt::gray;
    m_percentColor = Qt::white;
    m_format = "%p%";
    m_precision = 1;
}

void QtFillingProgressBar::setPercentColor(const QColor &percentColor)
{
    if (m_percentColor != percentColor)
    {
        m_percentColor = percentColor;
        emit update();
    }
}

void QtFillingProgressBar::setPercentFont(const QFont &percentFont)
{
    if (m_percentFont != percentFont)
    {
        m_percentFont = percentFont;
        emit update();
    }
}

void QtFillingProgressBar::setBackgroundColor(const QColor &backgroundColor)
{
    if(m_backgroundColor != backgroundColor)
    {
        m_backgroundColor = backgroundColor;
        emit update();
    }
}

void QtFillingProgressBar::setProgressColor(const QColor &progressColor)
{
    if (m_progressColor != progressColor)
    {
        m_progressColor = progressColor;
        emit update();
    }
}

void QtFillingProgressBar::setFormat(const QString &format)
{
    if (m_format != format)
    {
        m_format = format;
        emit update();
    }
}

void QtFillingProgressBar::setPrecision(int precision)
{
    if (m_precision != precision)
    {
        m_precision = precision;
        emit update();
    }
}

void QtFillingProgressBar::paintEvent(QPaintEvent *)
{
    if (height() > 0 && width() > 0)
    {
        int w = qRound(width()*(m_value-m_min)/(m_max-m_min));
        double percent = 100*(m_value-m_min)/(m_max-m_min);
        QString percentText = m_format;
        percentText.replace("%p", QString::number(percent, 'f', m_precision));

        QPainter painter(this);
        painter.setPen(m_progressColor);
        painter.setBrush(m_progressColor);
        painter.drawRect(0, 0, w, height());
        painter.setPen(m_backgroundColor);
        painter.setBrush(m_backgroundColor);
        painter.drawRect(w, 0, width() - w, height());
        painter.setFont(m_percentFont);
        painter.setPen(m_percentColor);
        painter.drawText(rect(), Qt::AlignCenter, percentText);
    }
}

void QtFillingProgressBar::resizeEvent(QResizeEvent *)
{
    if (m_percentFont.pixelSize() != height())
        m_percentFont.setPixelSize(height());
}

void QtFillingProgressBar::setRange(double min, double max)
{
    m_min = min;
    m_max = max;

    update();
}

void QtFillingProgressBar::setValue(double value)
{
    if (value > m_max)
        m_value = m_max;
    else if (m_value < m_min)
        m_value = m_min;
    else
        m_value = value;

    update();
}

void QtFillingProgressBar::reset()
{
    m_value = m_min;

    update();
}
