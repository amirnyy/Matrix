cmake_minimum_required(VERSION 3.0)
 
 set(CMAKE_CXX_STANDARD 11)
 set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
 option(BUILD_EXAMPLES "Build examples" OFF)
  
  project(Matrix)
  
  add_library(Matrix STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/Matrix.cpp)
  
  target_include_directories(Matrix PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
   $<INSTALL_INTERFACE:include>
 )
 
 if(BUILD_EXAMPLES)
   file(GLOB EXAMPLE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/examples/*.cpp")
   foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
     get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
     add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
     target_link_libraries(${EXAMPLE_NAME} Matrix)
     install(TARGETS ${EXAMPLE_NAME}
       RUNTIME DESTINATION bin
     )
   endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
 endif()
 
 install(TARGETS Matrix
     EXPORT matrix-config
     ARCHIVE DESTINATION lib
     LIBRARY DESTINATION lib
 )
