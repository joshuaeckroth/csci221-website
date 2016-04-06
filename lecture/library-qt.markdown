---
layout: default
title: "Library: Qt"
---

[Qt](http://qt-project.org/) is a massive library (or set of libraries) for low-level C++, GUIs, networking, multimedia, Unicode, string translation, etc. It also includes QML, a new language that simplifies GUI development. Qt supports mobile app development (Android, IOS, etc.) as well. Furthermore, it has a cool IDE, [Qt Creator](http://qt-project.org/doc/qtcreator-3.2/index.html) with a built-in help system, debugger, and drag-and-drop GUI designer. Best of all, the GUIs and other code work the same on Windows, Linux, and Mac OS X, and they even look "native" on each platform.

These notes will explore some of the fundamental features of Qt. There is extensive documentation for Qt in the Qt Creator IDE as well as their [website](http://qt-project.org/doc/qt-5/reference-overview.html).

## Meta-object compiler

Qt originated in a time (1991) when C++ compilers were immature. In order to use advanced features in C++ code, the Qt library includes a program called `moc` (meta-object compiler) which transforms Qt-style C++ into real C++. It is executed before the C++ compiler looks at the code. By using `moc`, we can use advanced features like signals and slots (described below), reflection, and "dynamic object properties" (which we won't get into).

You can use `moc` in a `Makefile` in the way described on [this page](http://qt-project.org/doc/qt-5/moc.html#writing-make-rules-for-invoking-moc). But simpler is to use the `qmake` program provided with Qt. Check out the [qmake](http://qt-project.org/doc/qt-5/qmake-manual.html) documentation for details about how to write a `.pro` file (project file) instead of a `Makefile`. (Note: `qmake` generates a `Makefile` from your `.pro` file.)

## Quick overview of some features

Qt has new implementations of STL-style containers. As mentioned above, Qt originated in the early days of C++, when STL containers were subpar. In any event, the Qt containers are possibly faster and more consistent than STL containers. [This page](http://qt-project.org/doc/qt-5/containers.html) has a good overview of Qt containers.

[...]

## Signals and slots

A core concept in Qt is "signals and slots." This is how objects communicate with each other. Signals and slots are used extensively in GUI applications: clicking a button generates a signal, which is picked up by a slot in some other class.

We'll look at a simple example, borrowed from Qt's own [tutorial](http://qt-project.org/doc/qt-4.8/signalsandslots.html). To use signals and slots, your class needs to inherit from `QObject` (possibly among others), and needs the `Q_OBJECT` macro at the top of the class definition. This is noticed by `moc`, which generates the necessary C++ code to deal with signals and slots.

Here is `counter.h`:

```
// counter.h
#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter() { m_value = 0; }
    int value() const { return m_value; }

public slots:
    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};

#endif // COUNTER_H
```

Here is `counter.cpp`:

```
// counter.cpp
#include "counter.h"

void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}
```

Here is the main file:

```
#include <iostream>
#include "counter.h"
using namespace std;

int main()
{
    Counter a, b;
    QObject::connect(&a, SIGNAL(valueChanged(int)),
                     &b, SLOT(setValue(int)));
    a.setValue(12);     // a.value() == 12, b.value() == 12
    cout << "a = " << a.value() << ", b = " << b.value() << endl;
    b.setValue(48);     // a.value() == 12, b.value() == 48
    cout << "a = " << a.value() << ", b = " << b.value() << endl;
    return 0;
}
```

Boost also has signals/slots support. See their [tutorial](http://www.boost.org/doc/libs/1_38_0/doc/html/signals/tutorial.html), and this [StackOverflow post](http://stackoverflow.com/questions/768351/complete-example-using-boostsignals-for-c-eventing).

## Simple GUI

Let's take a quick look at the default GUI application template. Here is `main.cpp`:

```
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
```

The `QApplication` line establishes a global pointer `qApp` (which you don't ever need to use) that manages the GUI application. It also parses command line arguments. The `QApplication` object should be created before any GUI objects are created.

`MainWindow` is a class defined in `mainwindow.h`:

```
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
```

Here is `mainwindow.cpp`:

```
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
```

All the `MainWindow` class accomplishes is to set up the GUI layout defined in `mainwindow.ui`. However, this `MainWindow` class would be expanded to respond to mouse clicks, key presses, etc. in the future in order to make the GUI actually do something. Signals and slots would be used for that purpose.

The `mainwindow.ui` file is XML:

```
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow" >
  <property name="geometry" >
   <rect>
    <x>0</x>
    <y>0</y>
    <width>400</width>
    <height>300</height>
   </rect>
  </property>
  <property name="windowTitle" >
   <string>MainWindow</string>
  </property>
  <widget class="QMenuBar" name="menuBar" />
  <widget class="QToolBar" name="mainToolBar" />
  <widget class="QWidget" name="centralWidget" />
  <widget class="QStatusBar" name="statusBar" />
 </widget>
 <layoutDefault spacing="6" margin="11" />
 <pixmapfunction></pixmapfunction>
 <resources/>
 <connections/>
</ui>
```

But you probably don't want to edit that directly. Use Qt Creator's built in GUI form editor:

![Qt Creator form editor](/images/qt-creator-form-editor.png)

We'll add a button, and create a signal/slot connection. First, we need to make the slot. Go to the `mainwindow.h` file and add this slot:

```
public slots:
    void doit();
```

We want a slot with no arguments because the `clicked()` signal has no arguments. Slots (and signals) are always `void` methods. Slots have access qualifiers (public, private, protected) because you might want to restrict how other classes execute your methods (a slot is basically a class method). On the other hand, signals have no access protection since the class itself emits signals.

In `mainwindow.cpp`, define what the `doit()` function does:

```
void MainWindow::doit()
{
    qDebug("hello world!"); // print a console message
}
```

Now, in the `MainWindow` constructor, connect the signal and slot:

```
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(doit()));
}
```

Now run the application.


