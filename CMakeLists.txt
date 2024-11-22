cmake_minimum_required(VERSION 3.16)

project(trabxml VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Diretórios para cabeçalhos e fontes
include_directories(include)
file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

# Adicionar executável
add_executable(trabxml ${SOURCES} ${HEADERS} ui/mainwindow.ui)

# Encontrar bibliotecas
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Xml)
target_link_libraries(trabxml Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Xml)

# Bibliotecas externas
include_directories(external/include)
link_directories(external/lib)
target_link_libraries(trabxml libxml2)


