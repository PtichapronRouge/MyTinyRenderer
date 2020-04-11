file(GLOB
    src
    tgaimage.cpp
)

file(GLOB
    headers
    tgaimage.h
)

add_library(tga
    SHARED
    ${src}
)

target_include_directories(tga PUBLIC
    "${CURRENT_SOURCE_DIR}"
)

install(TARGETS tga
    DESTINATION lib
)

install(FILES ${headers}
    DESTINATION include/${CMAKE_PROJECT_NAME}
)
