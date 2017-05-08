#include "qtimerthread.h"

FF::QTimerThread::QTimerThread(QObject *parent)
    :QThread(parent)
{
    this->m_timer = new QTimer;
    this->m_timerThread = new QThread;
    m_timer->moveToThread(m_timerThread);
    connect(m_timer, SIGNAL(timeout()), this, SIGNAL(timeout()));
    connect(this, SIGNAL(timerStart()), m_timer, SLOT(start()));
}

FF::QTimerThread::~QTimerThread()
{
    delete this->m_timer;
    delete this->m_timerThread;
}

void FF::QTimerThread::timerQuit()
{
    m_timer->stop();
    m_timerThread->quit();
}

void FF::QTimerThread::setInterval(int msec)
{
    m_timer->setInterval(msec);
}

void FF::QTimerThread::run()
{
    m_timerThread->start();
    emit timerStart();
    exec();
}

void FF::QTimerThread::doRoutine()
{

}
