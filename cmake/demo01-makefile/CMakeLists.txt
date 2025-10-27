#cmake最低版本要求
cmake_minimum_required(VERSION 3.10)

#项目名
project(HelloWorld)

#声明变量
set(SOURCES main.c message.c)

#声明make目标
add_executable(hello ${SOURCES})

