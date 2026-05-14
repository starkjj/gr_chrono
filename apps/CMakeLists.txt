cmake_minimum_required(VERSION 3.18)
cmake_policy(SET CMP0091 NEW)


set(CH_ENABLE_MODULE_VSG ON  CACHE BOOL "" FORCE )
set(CH_ENABLE_MODULE_VEHICLE  ON  CACHE BOOL "" FORCE)
set(CH_ENABLE_MODULE_VEHICLE_MODELS  ON  CACHE BOOL "" FORCE)

# Only build this app if the modules it needs are enabled in Chrono
if(NOT CH_ENABLE_MODULE_VEHICLE OR NOT CH_ENABLE_MODULE_VSG)
    message(STATUS "corolla_sim: skipped (needs Vehicle + VSG modules)")
    return()
endif()

message(STATUS "Adding application: corolla_sim")

# Specify project sources and add executable
set(GR_SRC corolla_sim/main.cpp)

add_executable(corollasim ${GR_SRC})

#--------------------------------------------------------------
# Set properties for the executable target
#--------------------------------------------------------------

# Link to Chrono targets for the requested modules
target_link_libraries(corollasim PRIVATE
        Chrono_core
        Chrono_vehicle
        Chrono_vsg
        Chrono_vehicle_vsg
        ChronoModels_vehicle
)

# Put the executable in Chrono's bin/ output dir alongside the demos
set_target_properties(corollasim PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        DEBUG_POSTFIX "_d"
)

# At runtime, your app needs to know where Chrono's data/ and the vehicle data live.
# Chrono provides CHRONO_DATA_DIR and CHRONO_VEHICLE_DATA_DIR as cache variables.
target_compile_definitions(corollasim PRIVATE
        CHRONO_DATA_DIR="${CMAKE_BINARY_DIR}/data/"
        CHRONO_VEHICLE_DATA_DIR="${CMAKE_BINARY_DIR}/data/vehicle/"
)


# Windows: copy Chrono's DLLs (and Irrlicht.dll) next to the .exe so it runs
if(WIN32)
    add_custom_command(TARGET corollasim POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_RUNTIME_DLLS:corollasim>
            $<TARGET_FILE_DIR:corollasim>
            COMMAND_EXPAND_LISTS)
endif()