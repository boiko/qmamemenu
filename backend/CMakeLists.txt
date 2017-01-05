include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
    Qmamemenubackend_SRCS
    modules/Qmamemenu/backend.cpp
    modules/Qmamemenu/mame.cpp
    modules/Qmamemenu/mamerommodel.cpp
)

# Make the unit test files visible on qtcreator
add_custom_target(Qmamemenubackend_UNITTEST_QML_FILES ALL SOURCES "tests/unit/tst_mytype.qml")

add_library(Qmamemenubackend MODULE
    ${Qmamemenubackend_SRCS}
)

set_target_properties(Qmamemenubackend PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY Qmamemenu)

qt5_use_modules(Qmamemenubackend Gui Qml Quick)

# Copy qmldir file to build dir for running in QtCreator
add_custom_target(Qmamemenubackend-qmldir ALL
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/modules/Qmamemenu/qmldir ${CMAKE_CURRENT_BINARY_DIR}/Qmamemenu
    DEPENDS ${QMLFILES}
)

# Install plugin file
install(TARGETS Qmamemenubackend DESTINATION ${QT_IMPORTS_DIR}/Qmamemenu/)
install(FILES   modules/Qmamemenu/qmldir DESTINATION ${QT_IMPORTS_DIR}/Qmamemenu/)
