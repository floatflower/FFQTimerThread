FFQTimerThread
===

A thread class with timer developed with Qt C++ framework by FloatFlower.Huang.

## Information
+ Author: FloatFlower.Huang
+ Email: zxc110888asd@gmail.com
+ License: MIT

## Installation
Require Qt5
```shell
~$ qmake
~$ make
~$ sudo make install
```
To link this library to your project, put this to qmake project file.
```
LIB += -lffqtimerthread
```
By default, the library will be installed to /usr/include, To change "/usr" to another location, run:
For example, change to /usr/local/include
```
~$ qmake -r PREFIX=/usr/local
```

## Usage
Include the headers:
```cpp
#include <ff/qtimerthread.h>
```
There are two ways to use `QTimerThread`, first one is worker-object approach.
These two approach are similar to [QThread usage approach](http://doc.qt.io/qt-5/qthread.html#details).
```cpp
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0) {}
public slots:
    void onTimeout() {
        /* ... do someting when timeout. ... */
    }
};

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0)
    {
        Worker *worker = new Worker;
        m_thread = new FF::QTimerThread;
        m_thread->setInterval(2000);
        worker->moveToThread(m_thread);
        connect(m_thread, SIGNAL(timeout()), worker, SLOT(onTimeout()));
        m_thread->start();
    }

    ~Controller() {
        m_thread->timerQuit();
        m_thread->quit();
        m_thread->wait();
        delete m_thread;
    }
private:
    FF::QTimerThread *m_thread;
};
```
Second one is to inhreit `QTimerThread` class and reimplement `QTimerThread::doRoutine()`.
If you are going to use this approach,
don't forget to connect signal `QTimerThread::timeout()` to slot `QTimerThread::doRoutine()`
when subclassing `FFQTimerThread`
```cpp
class WorkerThread : public FF::QTimerThread
{

public:
    explicit WorkerThread() {
        connect(this, SIGNAL(timeout()), this, SLOT(doRoutine()));
    }
    virtual void doRoutine() {
        /* ... do something when timeout. ... */
    }
};


class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0)
    {
        m_thread = new WorkThread;
        m_thread->setInterval(2000);
        m_thread->start();
    }

    ~Controller() {
        m_thread->timerQuit();
        m_thread->quit();
        m_thread->wait();
        delete m_thread;
    }
private:
    WorkerThread *m_thread;
};
```
### Notice:
+ Keep in mind that calling `QTimerThread::timerQuit()` is crucial,
because `QTimerThread::wait()` will wait for the thread for QTimer quit.
+ Instantiating `QTimerThread` creates two thread pratically, one for timer,
the other for doing job.
