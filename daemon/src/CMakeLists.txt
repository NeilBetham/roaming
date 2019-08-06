project(roaming-daemon)

include_directories(${oatpp_SOURCE_DIR}/src/)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} oatpp)

INSTALL(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION /usr/bin/)
