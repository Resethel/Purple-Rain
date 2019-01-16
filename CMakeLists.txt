cmake_minimum_required (VERSION 2.6)
project (Purple-Rain)
set (CMAKE_BUILD_TYPE Release)

# The version number.
set (Purple-Rain_VERSION_MAJOR 2)
set (Purple-Rain_VERSION_MINOR 0)

#
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)


# Finds SFML package
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package (SFML REQUIRED graphics window system)



# Creates the executable
add_executable(

    ${PROJECT_NAME}
    src/Main.cpp
    src/Constant.hpp
    src/Utils.hpp
    src/Utils.cpp
    src/HSL.hpp
    src/HSL.cpp

    src/GUI/Button.hpp
    src/GUI/Button.cpp
    src/GUI/Box.hpp
    src/GUI/Box.cpp
    src/GUI/Component.hpp
    src/GUI/Component.cpp
    src/GUI/Interface.hpp
    src/GUI/Interface.cpp
    src/GUI/Label.hpp
    src/GUI/Label.cpp
    src/GUI/Slider.hpp
    src/GUI/Slider.cpp

    src/Rain/Canvas.hpp
    src/Rain/Canvas.cpp
    src/Rain/Drop.hpp
    src/Rain/Drop.cpp

    media/Pixeled.ttf

)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${ADDITIONAL_LINK_FLAGS})
