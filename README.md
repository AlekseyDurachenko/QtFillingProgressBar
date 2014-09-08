QtFillingProgressBar
====================

About
-----

The progress bar widget for the Qt toolkit.

Website: https://github.com/AlekseyDurachenko/QtFillingProgressBar

Copyright (c) 2013-2014 Aleksey Durachenko (unless explicitly stated otherwise).

<p align=center>
<img src=https://raw.githubusercontent.com/AlekseyDurachenko/QtFillingProgressBar/master/doc/examples/statusbar/img/screenshot001.png>
</p>

Usage
-----

```cpp
...
#include <QtFillingProgressBar>
...
CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent)
{
...
m_progressBar = new QtFillingProgressBar(this);
m_progressBar->setRange(0.0, 1000.0);
m_progressBar->setFormat("Done %p%");
m_progressBar->setPrecision(2);
statusBar()->addWidget(m_progressBar, 1);
...
}
...
```

License
-------

<a href="https://github.com/AlekseyDurachenko/QtFillingProgressBar/blob/master/LICENSE">LGPLv2.1+</a>.
