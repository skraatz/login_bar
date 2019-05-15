simple toolbar, implemented in QT5, providing a clock widget as well as reboot and shutdown buttons, intended to be used with xdm/xenodm

![alt text](https://raw.githubusercontent.com/skraatz/login_bar/master/screenshot.png)

### this toolbar is build using cmake

 * clone the repo
 * cd login_bar
 * mkdir build && cd build
 
 // this next  step is probably specific to OpenBSD, where I wrote it
 // under Linux your QT libraries are likely somewhere else
 * export Qt5Widgets_DIR=/usr/local/lib/qt5/cmake/Qt5Widgets/ 
 * cmake ..
 * make

### requirements

I have not tested for all requirements, but this requires at least some version
of the qt5 libraries installed

those are the packages I installed on OpenBSD for getting this work on a fresh installation
 * git
 * cmake
 * qt5 (beware, this is a meta package, that pulls a lot of dependencies)

### "installation"
 
 For it to be used at the login screen of xdm or xenodm, it needs tp be called from the startup scripts of them.
 If you want to play with it yourself under OpenBSD, your can modify /etc/X11/xenodm/Xsetup_0 to contain the following lines
 
 ```
 /path/to/login_bar &
 echo $! > /var/run/login_bar.pid
 ```
 
 this will start login_bar and create a pid file, so you can kill the toolbar from a script, once you logged in
