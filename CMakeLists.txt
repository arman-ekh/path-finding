cmake_minimum_required(VERSION 4.1)
project(path_finding)

set(CMAKE_CXX_STANDARD 20)


set(RAYLIB_INCLUDE_DIR "C:/raylib/w64devkit/include")
set(RAYLIB_LIB_PATH "C:/raylib/w64devkit/lib/libraylib.a")

add_executable(path_finding main.cpp
        Header/Graph_Node.h
        Header/Graph.h
        include/Graph/Graph.h
        include/Graph/Graph_Node.h
        include/Graph/Edge.h
        include/Algorithms/Algorithm.h
        include/Algorithms/DFS.h
        include/Algorithms/BFS.h
        include/Algorithms/DLS.h
        include/Algorithms/IDS.h
        include/Algorithms/UCS.h
        include/Visualization/Graph_Renderer.h
        include/Visualization/Algorithm_Renderer.h
        include/Visualization/UI.h
        include/EDITOR/GraphEditor.h
        src/Algorithms/Algorithm.cpp
        src/Algorithms/BFS.cpp
        src/Algorithms/DFS.cpp
        src/Algorithms/DLS.cpp
        src/Algorithms/IDS.cpp
        src/Algorithms/UCS.cpp
        src/EDITOR/GraphEditor.cpp
        src/Graph/Graph.cpp
        src/Graph/Edge.cpp
        src/Graph/Graph_Node.cpp
        src/Visualization/Algorithm_Renderer.cpp
        src/Visualization/Graph_Renderer.cpp
        src/Visualization/UI.cpp
)


target_include_directories(path_finding PRIVATE ${RAYLIB_INCLUDE_DIR})


target_link_libraries(path_finding
        ${RAYLIB_LIB_PATH}
        opengl32
        gdi32
        winmm
)