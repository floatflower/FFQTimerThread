#ifndef FFQTIMERTHREAD_GLOBAL_H
#define FFQTIMERTHREAD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(FFQTIMERTHREAD_LIBRARY)
#  define FFQTIMERTHREADSHARED_EXPORT Q_DECL_EXPORT
#else
#  define FFQTIMERTHREADSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // FFQTIMERTHREAD_GLOBAL_H
