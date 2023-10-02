cmake_minimum_required(VERSION 3.5)

project(PreGraphic VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets PrintSupport Concurrent)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)


add_executable(PreGraphic
    ${PROJECT_SOURCES}
)

#Необходимо при использовании динамической библиотеки QCustomPlot
add_compile_definitions(QCUSTOMPLOT_USE_LIBRARY)
#Добавляем путь где искать библиотеки
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(PreGraphic PRIVATE Qt6::Widgets
	                                                Qt6::Concurrent
													Qt6::PrintSupport
													qcustomplot2.dll)
qt_finalize_executable(PreGraphic)

