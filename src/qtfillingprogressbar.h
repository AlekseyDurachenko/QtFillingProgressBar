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
#ifndef QTFILLINGPROGRESSBAR_H
#define QTFILLINGPROGRESSBAR_H

#include <QWidget>

class QtFillingProgressBar : public QWidget
{
    Q_OBJECT
public:
    explicit QtFillingProgressBar(QWidget *parent = 0);
    inline double maximum() const;
    inline double minimum() const;
    inline double value() const;

protected:
    void paintEvent(QPaintEvent *paintEvent);
    void resizeEvent(QResizeEvent *resizeEvent);

public slots:
    void setRange(double min, double max);
    void setValue(double value);
    void reset();

private:
    double m_min, m_max, m_value;
    QFont m_percentFont;
    QColor m_progressColor;
    QColor m_backgroundColor;
    QColor m_percentColor;

};

double QtFillingProgressBar::maximum() const
{
    return m_max;
}

double QtFillingProgressBar::minimum() const
{
    return m_min;
}

double QtFillingProgressBar::value() const
{
    return m_value;
}

#endif // QTFILLINGPROGRESSBAR_H
