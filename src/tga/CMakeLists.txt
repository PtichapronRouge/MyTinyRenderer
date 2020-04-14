file(GLOB
    src
    *.cpp
)

file(GLOB
    headers
    *.h *.hpp
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
