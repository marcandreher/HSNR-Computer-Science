project(Uebung6 C)

set(CMAKE_C_STANDARD 17)

add_executable(Uebung6 main.c)

# 👇 This line fixes the project linking issue
target_link_libraries(Uebung6 m)
