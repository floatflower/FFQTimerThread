#ifndef QTIMERTHREAD_H
#define QTIMERTHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>

#include "ffqtimerthread_global.h"

namespace FF {
class FFQTIMERTHREADSHARED_EXPORT QTimerThread : public QThread
{
    Q_OBJECT
public:
    QTimerThread(QObject *parent = 0);
    ~QTimerThread();
    void setInterval(int msec);
    virtual void run();
signals:
    void timeout();
    void timerStart();
public slots:
    virtual void doRoutine();
    void timerQuit();
private:
    QTimer *m_timer;
    QThread *m_timerThread;
};
}

#endif // QTIMERTHREAD_H
