// Copyright (C) 2014, Durachenko Aleksey V. <durachenko.aleksey@gmail.com>
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
#include "cmainwindow.h"
#include <QStatusBar>
#include <QMenuBar>
#include <QLayout>
#include <QPushButton>

CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle("The progress bar example");
    setStatusBar(new QStatusBar(this));
    setMenuBar(new QMenuBar(this));
    QMenu *fileMenu = menuBar()->addMenu("File");
    QAction *startAction = fileMenu->addAction("&Start progress bar");
    QAction *stopAction = fileMenu->addAction("&Stop progress bar");
    fileMenu->addSeparator();
    QAction *quitAction = fileMenu->addAction("&Quit");
    quitAction->setStatusTip("Quit");
    connect(startAction, SIGNAL(triggered()), this, SLOT(onStartProgressBar()));
    connect(stopAction, SIGNAL(triggered()), this, SLOT(onStopProgressBar()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(new QHBoxLayout(centralWidget));
    QPushButton *startButton = new QPushButton("Start progress bar", this);
    QPushButton *stopButton = new QPushButton("Stop progress bar", this);
    centralWidget->layout()->addWidget(startButton);
    centralWidget->layout()->addWidget(stopButton);
    setCentralWidget(centralWidget);
    connect(startButton, SIGNAL(clicked()), this, SLOT(onStartProgressBar()));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(onStopProgressBar()));

    m_timer = new QTimer(this);
    m_timer->setInterval(10);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerTimeOut()));

    m_progressBar = new QtFillingProgressBar(this);
    m_progressBar->setRange(0.0, 1000.0);
    m_progressBar->setFormat("Done %p%");
    m_progressBar->setPrecision(2);
    statusBar()->addWidget(m_progressBar, 1);
    m_progressBar->hide();
}

void CMainWindow::onStartProgressBar()
{
    m_progressBar->show();
    m_progressBar->reset();
    m_timer->start();
}

void CMainWindow::onStopProgressBar()
{
    m_progressBar->hide();
    m_timer->stop();
}

void CMainWindow::onTimerTimeOut()
{
    m_progressBar->setValue(m_progressBar->value() + 1.0);
    if (m_progressBar->value() >= 1000.0)
        onStopProgressBar();
}
