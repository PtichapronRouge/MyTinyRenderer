file(GLOB
    src
    line.cpp
)

file(GLOB
    headers
    line.hpp
)

add_library(raster
    SHARED
    ${src}
)

target_include_directories(raster PUBLIC
    "${CURRENT_SOURCE_DIR}"
)

target_link_libraries(raster PUBLIC tga)

target_include_directories(raster PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/tga")

install(TARGETS raster
    DESTINATION lib
)

install(FILES ${headers}
    DESTINATION include/${CMAKE_PROJECT_NAME}
)
