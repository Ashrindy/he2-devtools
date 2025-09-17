cmake_minimum_required(VERSION 3.28)
project(imviewguizmo LANGUAGES CXX)

add_library(imviewguizmo INTERFACE)
target_link_libraries(imviewguizmo INTERFACE glm::glm)
target_sources(imviewguizmo
    INTERFACE FILE_SET HEADERS BASE_DIRS ImViewGuizmo FILES
        ImViewGuizmo/ImViewGuizmo.h
)
