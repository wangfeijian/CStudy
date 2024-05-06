cmake_minimum_required(VERSION 3.15)

# 设置一个项目名称，设置程序的版本号
project(Tutorial VERSION 1.0.3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加版本号的头文件，需要在目录中新建一个TutorialConfig.h.in源文件
configure_file(TutorialConfig.h.in TutorialConfig.h)


# 设置多个源文件
SET(SRC_LIST tutorial.cpp)

# 用来生成可执行的文件，需要指定生成执行文件的名称和相关源文件
add_executable(${PROJECT_NAME} ${SRC_LIST})


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

string(TIMESTAMP COMPILE_TIME)
