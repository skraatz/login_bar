cmake_minimum_required(VERSION 3.0)
project(login_bar)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

# Populate a CMake variable with the sources
set(login_bar_SRCS
    main.cpp
    mainwindow.cpp
    mainwindow.h
    clockwidget.h
    clockwidget.cpp
)
# Tell CMake to create the helloworld executable
add_executable(login_bar ${login_bar_SRCS})
# Use the Widgets module from Qt 5
target_link_libraries(login_bar Qt5::Widgets)

