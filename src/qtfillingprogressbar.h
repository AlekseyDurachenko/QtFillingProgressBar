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

    inline const QFont &percentFont() const;
    void setPercentFont(const QFont &percentFont);

    inline const QColor &percentColor() const;
    void setPercentColor(const QColor &percentColor);

    inline const QColor &progressColor() const;
    void setProgressColor(const QColor &progressColor);

    inline const QColor &backgroundColor() const;
    void setBackgroundColor(const QColor &backgroundColor);

    inline const QString &format() const;
    void setFormat(const QString &format);

    inline int precision() const;
    void setPrecision(int precision);
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
    QColor m_percentColor;
    QColor m_progressColor;
    QColor m_backgroundColor;
    QString m_format;
    int m_precision;
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

const QFont &QtFillingProgressBar::percentFont() const
{
    return m_percentFont;
}

const QColor &QtFillingProgressBar::percentColor() const
{
    return m_percentColor;
}

const QColor &QtFillingProgressBar::progressColor() const
{
    return m_progressColor;
}

const QColor &QtFillingProgressBar::backgroundColor() const
{
    return m_backgroundColor;
}

const QString &QtFillingProgressBar::format() const
{
    return m_format;
}

int QtFillingProgressBar::precision() const
{
    return m_precision;
}

#endif // QTFILLINGPROGRESSBAR_H
