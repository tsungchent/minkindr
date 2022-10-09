cmake_minimum_required(VERSION 3.5)
project(minkindr)

# find_package(catkin_simple REQUIRED)
find_package(ament_cmake REQUIRED)
# catkin_simple(ALL_DEPS_REQUIRED)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 14)

find_package(Threads)
find_package(eigen_vendor REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(glog_vendor REQUIRED)
find_package(eigen_checks REQUIRED)

find_package(ament_cmake_gtest REQUIRED)

ament_add_gtest(${PROJECT_NAME}_tests 
  test/test-main.cc
  test/test-rotation.cc
  test/test-sim3.cc
  test/test-transformation.cc
  test/test-transformation-2d.cc
)

ament_target_dependencies(${PROJECT_NAME}_tests
    eigen_checks
    glog_vendor
    eigen_vendor
)

target_link_libraries(${PROJECT_NAME}_tests ${CMAKE_THREAD_LIBS_INIT})

target_include_directories(
  ${PROJECT_NAME}_tests PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Add all files to show up in QtCreator.
FILE(GLOB_RECURSE LibFiles "include/*")
add_custom_target(headers SOURCES ${LibFiles})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)

ament_package()



