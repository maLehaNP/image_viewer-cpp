cmake_minimum_required(VERSION 3.19)
project(ImVi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_BUILD_PARALLEL_LEVEL 8)

# Добавляем пакет Quick
#find_package(Qt6 6.5
#  REQUIRED COMPONENTS
#    Quick Widgets
#)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

# Определяем компилируемые файлы
qt_add_executable(ImVi
  src/main.cpp
  src/buttonHandler.cpp
)

target_include_directories(ImVi
  PUBLIC
    include
)

# Добавляем файлы qml
qt_add_qml_module(ImVi
  URI path      # ссылка, по которой будут загружаться файлы qml
  VERSION 1.0
  QML_FILES src/main.qml
  RESOURCES test_images/69f86e59a86e8162aea80769f971435a.jpg  # доступный ресурс
)

target_link_libraries(ImVi
  PRIVATE
    Qt6::Quick
    #Qt6::Widgets
)

# include(GNUInstallDirs)
install(TARGETS ImVi
  BUNDLE  DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

