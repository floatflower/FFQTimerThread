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
