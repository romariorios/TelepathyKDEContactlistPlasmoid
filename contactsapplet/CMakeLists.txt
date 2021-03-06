# Project Needs a name ofcourse
project(plasma-contactsapplet)

set(CMAKE_MODULE_PATH
"${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
${CMAKE_MODULE_PATH}
)
 
# Find the required Libaries
find_package(KDE4 REQUIRED)
find_package(TelepathyQt4 REQUIRED)
find_package(KTelepathy REQUIRED)

include(KDE4Defaults)
include(MacroLibrary)
 
add_definitions (
${QT_DEFINITIONS}
${KDE4_DEFINITIONS}
)
include_directories(
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_BINARY_DIR}
${KDE4_INCLUDES}
${TELEPATHY_QT4_INCLUDE_DIR}
${KTELEPATHY_INCLUDE_DIRS}
)
 
# We add our source code here
set(contactsapplet_SRCS
contactswidget.cpp
contactsapplet.cpp
)
 
# Now make sure all files get to the right place
kde4_add_plugin(plasma_applet_contactsapplet ${contactsapplet_SRCS})
target_link_libraries(plasma_applet_contactsapplet 
${KDE4_PLASMA_LIBS}
${KDE4_KDEUI_LIBS}
${TELEPATHY_QT4_LIBRARIES}
${KTELEPATHY_LIBRARIES}
)
 
install(TARGETS plasma_applet_contactsapplet DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES plasma-applet-contactsapplet.desktop DESTINATION ${SERVICES_INSTALL_DIR})
