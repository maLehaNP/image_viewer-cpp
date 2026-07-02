cmake_minimum_required(VERSION 3.19)
project(ImVi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_BUILD_PARALLEL_LEVEL 8)

# Добавляем пакет Quick
#find_package(Qt6 6.5
#  REQUIRED COMPONENTS
#    Quick Widgets
#)

find_package(Qt6 REQUIRED COMPONENTS Quick Widgets)

qt_standard_project_setup()

# Определяем компилируемые файлы
qt_add_executable(ImVi
  src/main.cpp
  src/backend.cpp
)

target_include_directories(ImVi
  PUBLIC
    include
)

# Добавляем файлы qml
qt_add_qml_module(ImVi
  # ссылка, по которой будут загружаться файлы qml
  URI path
  VERSION 1.0
  QML_FILES
    src/main.qml
  # доступный ресурс
  #RESOURCES
  #  test_images/69f86e59a86e8162aea80769f971435a.jpg
  SOURCES
    include/backend.h
    src/backend.cpp
)

target_link_libraries(ImVi
  PRIVATE
    Qt6::Quick
    Qt6::Widgets
)

# include(GNUInstallDirs)
install(TARGETS ImVi
  BUNDLE  DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

