cmake_minimum_required(VERSION 3.5)
project(minkindr_python)

# find_package(catkin_simple REQUIRED)
# catkin_simple(ALL_DEPS_REQUIRED)
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

find_package(eigen_vendor REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(glog_vendor REQUIRED)

# (minkindr REQUIRED)
# Find python before pybind11
# find_package(python_cmake_module REQUIRED)
# find_package(PythonExtra REQUIRED)

# set(_PYTHON_EXECUTABLE "${PYTHON_EXECUTABLE}")
# if(WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Debug")
  # Set the python debug interpreter.
  # pybind11 will setup the build for debug now.
#  set(PYTHON_EXECUTABLE "${PYTHON_EXECUTABLE_DEBUG}")
# endif()

find_package(pybind11_vendor REQUIRED)
find_package(pybind11 REQUIRED)

set (CMAKE_CXX_FLAGS "-Wall  ${CMAKE_CXX_FLAGS}")

# Enable C++11 support.
if (CMAKE_VERSION VERSION_LESS "3.1")
  if (MSVC)
    message(FATAL_ERROR "CMake version 3.1 or later is required to compiler ${PROJECT_NAME} with Microsoft Visual C++")
  endif ()
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
  else ()
    set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
  endif ()
else ()
  set (CMAKE_CXX_STANDARD 11)
endif ()

# Set up the python exports.
SET(PY_PROJECT_NAME minkindr_python)
# SET(PY_PACKAGE_DIR python/minkindr)

pybind11_add_module(${PY_PROJECT_NAME} SHARED
  src/module.cpp
  src/export-rotation-quaternion.cc
  src/export-transformation.cc
)

ament_target_dependencies(
  ${PY_PROJECT_NAME} PUBLIC
  eigen_vendor
  glog_vendor
)

target_include_directories(${PY_PROJECT_NAME} 
  PUBLIC ${CMAKE_INSTALL_PREFIX}/include
)

# install(TARGETS ${PY_PROJECT_NAME} EXPORT export_${PY_PROJECT_NAME}
#  ARCHIVE DESTINATION lib
#  LIBRARY DESTINATION lib
#  RUNTIME DESTINATION bin
#)
# ament_target_dependencies(${PY_PROJECT_NAME}
#   minkindr
#   pybind11_vendor
# )
# Install Python modules
ament_python_install_package(${PY_PROJECT_NAME})
install(TARGETS ${PY_PROJECT_NAME} DESTINATION ${PYTHON_INSTALL_DIR}/${PROJECT_NAME}/)

ament_package()
