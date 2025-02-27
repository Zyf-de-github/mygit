# CMakeList.txt: my_cmake_try 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET my_cmake_try PROPERTY CXX_STANDARD 20)
endif()

project(my_cmake_try LANGUAGE CXX) 

message(${PROGECT_NAUM})

add_executable (my_cmake_try "my_cmake_try.cpp" "my_cmake_try.h")

# TODO: 如有需要，请添加测试并安装目标。
