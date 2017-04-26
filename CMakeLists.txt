cmake_minimum_required(VERSION 2.8.11)
project(Tarea_2)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

set(tarea_2_SRC
  src/main.cpp
  src/Model.cpp
  src/View.cpp
  src/Vertex.cpp
  src/Triangle.cpp
)

# Tell CMake to create the executable
add_executable(lepp-delaunay ${tarea_2_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(lepp-delaunay Qt5::Widgets)

# Install the executable
install(TARGETS lepp-delaunay DESTINATION bin)
