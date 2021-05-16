cmake_minimum_required (VERSION 3.8)

project ("CmakeVcpkgTestF")

if(WIN32)

#windows-specific stuff
   else()

   #linux-specific stuff
   set(MESSAGE_QUIET ON)
   MESSAGE("Searching X11")
   set(MESSAGE_QUIET OFF)
FIND_PACKAGE(X11 REQUIRED)
IF(X11_FOUND)
set(MESSAGE_QUIET ON)
    MESSAGE(" X11 include path: " ${X11_INCLUDE_DIR})
    MESSAGE(" X11 library path: " ${X11_LIBRARIES})
    set(MESSAGE_QUIET OFF)
ENDIF(X11_FOUND)

    set(CMAKE_CXX_COMPILER /usr/bin/g++-10)
endif()



find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Boost REQUIRED)
find_package(TMXLITE REQUIRED)


include_directories(${SFML_INCLUDE_DIR})


include_directories(${TMXLITE_INCLUDE_DIR})

include_directories( ${Boost_INCLUDE_DIR} )

file(GLOB_RECURSE SourceFiles src/*.cpp)
file(GLOB_RECURSE HeaderFiles src/*.h)

add_executable (CmakeVcpkgTestF ${SourceFiles} ${HeaderFiles})

target_link_libraries(CmakeVcpkgTestF PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
target_link_libraries(CmakeVcpkgTestF PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
target_link_libraries(CmakeVcpkgTestF PRIVATE ${Boost_LIBRARIES})
target_link_libraries(CmakeVcpkgTestF PUBLIC ${TMXLITE_LIBRARIES})