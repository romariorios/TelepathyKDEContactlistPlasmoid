# Install script for directory: /home/kde4/kdesvn/contacts-dataengine

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/kde4/kde")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/home/kde4/kde/lib/kde4/plasma_engine_contacts.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/kde4/kde/lib/kde4/plasma_engine_contacts.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/kde4/kde/lib/kde4/plasma_engine_contacts.so"
         RPATH "/home/kde4/kde/lib:/home/kde4/kde/lib:/opt/qt-devel/lib")
  ENDIF()
  FILE(INSTALL DESTINATION "/home/kde4/kde/lib/kde4" TYPE MODULE FILES "/home/kde4/kdesvn/contacts-dataengine/build/lib/plasma_engine_contacts.so")
  IF(EXISTS "$ENV{DESTDIR}/home/kde4/kde/lib/kde4/plasma_engine_contacts.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/kde4/kde/lib/kde4/plasma_engine_contacts.so")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/kde4/kde/lib/kde4/plasma_engine_contacts.so"
         OLD_RPATH "/home/kde4/kde/lib:/opt/qt-devel/lib:::::::::::::::::::"
         NEW_RPATH "/home/kde4/kde/lib:/home/kde4/kde/lib:/opt/qt-devel/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/kde4/kde/lib/kde4/plasma_engine_contacts.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "/home/kde4/kde/share/kde4/services" TYPE FILE FILES "/home/kde4/kdesvn/contacts-dataengine/plasma-engine-contacts.desktop")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/kde4/kdesvn/contacts-dataengine/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/kde4/kdesvn/contacts-dataengine/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
