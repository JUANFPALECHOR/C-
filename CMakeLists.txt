cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(MyProject)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)

# Incluir directorios de encabezados
include_directories(${PROJECT_SOURCE_DIR}/src/controllers)
include_directories(${PROJECT_SOURCE_DIR}/src/models)
include_directories(${PROJECT_SOURCE_DIR}/src/utils)

# Agregar todos los archivos fuente
file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/controllers/*.cpp
    ${PROJECT_SOURCE_DIR}/src/models/*.cpp
    ${PROJECT_SOURCE_DIR}/src/utils/*.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

# Crear el ejecutable
add_executable(MyProject ${SOURCES})
