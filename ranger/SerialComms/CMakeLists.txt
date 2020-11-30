cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Robot-See-Robot-Do)

# Xlib
find_package(X11 REQUIRED)
link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

# libserial
PKG_CHECK_MODULES(LIBSERIAL REQUIRED libserial)
include_directories("/usr/include/libserial")
link_directories("/usr/include/libserial")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")
add_executable(brain commands.cpp run.cpp SerialController.cpp subsystems.cpp)
TARGET_LINK_LIBRARIES(brain ${GTK3_LIBRARIES})
TARGET_LINK_LIBRARIES(brain ${LIBSERIAL_LIBRARIES})
target_link_libraries(brain ${GAZEBO_LIBRARIES})
target_link_libraries(brain ${OpenCV_LIBS})
