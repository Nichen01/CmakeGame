# Install script for directory: C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/glfw-3.3.2/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/glad/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/stb_image/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/stb_truetype/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/enet-1.3.17/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/raudio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/glm/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/imgui-docking/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/safeSave/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/profilerLib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/gl2d/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/thirdparty/glui/cmake_install.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/Nicholas/Downloads/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/CmakeGame/cmakeSetup-96112bf767238f78e54a413670b32920f06e14b9/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
