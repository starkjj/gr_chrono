cmake_minimum_required(VERSION 3.18)
cmake_policy(SET CMP0091 NEW)

# project name
project(corollasim)

find_package(Chrono
        COMPONENTS VSG
        COMPONENTS Vehicle
        CONFIG)

# Return now if Chrono or a required component was not found.
if (NOT Chrono_FOUND)
    message("Could not find Chrono or one of its required modules")
    return()
endif()

#--------------------------------------------------------------
# Enable creation of "application bundles" on MacOSX.
#--------------------------------------------------------------

# This is necessary for any Irrlicht-based project (like the example here).
# For OpenGL-based or non-graphics projects, this is optional and the block
# below can be removed (or else explcitly set CMAKE_MACOSX_BUNDLE to 'OFF').
# If creating application bundles, the build output will be named 'myexe.app'.
# Use the convenience script 'run_app.sh' available under 'contrib/appbundle-macosx/'
# to run:
#     start_demo.sh myexe.app

if(APPLE)
    set(CMAKE_MACOSX_BUNDLE ON)
endif()

# Specify project sources and add executable
set(GR_SRC corolla_sim/main.cpp)

add_executable(corollasim ${GR_SRC})

#--------------------------------------------------------------
# Set properties for the executable target
#--------------------------------------------------------------

# Here, we define a macro CHRONO_DATA_DIR which will contain the
# path to the Chrono data directory, either in its source tree
# (if using a build version of Chrono), or in its install tree
# (if using an installed version of Chrono).
target_compile_definitions(corollasim PRIVATE "CHRONO_DATA_DIR=\"${CHRONO_DATA_DIR}\"")

if(MSVC)
    set_target_properties(corollasim PROPERTIES MSVC_RUNTIME_LIBRARY ${CHRONO_MSVC_RUNTIME_LIBRARY})
endif()

# Link to Chrono targets for the requested modules
target_link_libraries(corollasim PRIVATE ${CHRONO_TARGETS})

#--------------------------------------------------------------
# 4. OPTIONAL (Windows only)
#
# Add a custom command for copying all Chrono and
# dependency DLLs to the appropriate binary output folder.
# This function has effect only on Windows.
#--------------------------------------------------------------

add_CHRONO_DLLS_copy_command()

# idk if this does anything tho?
