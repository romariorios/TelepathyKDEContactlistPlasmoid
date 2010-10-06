project(plasma-engine-contacts)

set(CMAKE_MODULE_PATH
"${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
${CMAKE_MODULE_PATH}
)

find_package(KDE4 REQUIRED)
find_package(TelepathyQt4 REQUIRED)
find_package(KTelepathy REQUIRED)

include(KDE4Defaults)
include(MacroLibrary)

add_definitions(
${KDE4_DEFINITIONS}
)

include_directories(
${CMAKE_CURRENT_SOURCE_DIR}
${CMAKE_CURRENT_BINARY_DIR}
${KDE4_INCLUDES}
${TELEPATHY_QT4_INCLUDE_DIR}
${KTELEPATHY_INCLUDE_DIRS}
)

set(contacts_engine_SRCS
contactsengine.cpp
)

kde4_add_plugin(plasma_engine_contacts ${contacts_engine_SRCS})
target_link_libraries(plasma_engine_contacts
${KDE4_KDECORE_LIBS}
${KDE4_PLASMA_LIBS}
${TELEPATHY_QT4_LIBRARIES}
${KTELEPATHY_LIBRARIES}
)

install(TARGETS plasma_engine_contacts DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES plasma-engine-contacts.desktop DESTINATION ${SERVICES_INSTALL_DIR})