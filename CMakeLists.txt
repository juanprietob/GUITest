cmake_minimum_required (VERSION 2.8)

project(MyProject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

QT5_WRAP_UI(source_files_ui src/mainwindow.ui)
QT5_WRAP_CPP(source_files_moc src/mainwindow.cxx)


file( GLOB_RECURSE
        source_files
        src/*.hxx
        src/*.cxx
)

set(EXECUTABLE_OUTPUT_PATH build)

add_executable(main ${source_files} ${source_files_ui} ${source_files_moc})

qt5_use_modules(main Widgets Core)

target_link_libraries(main Qt5::Widgets)

