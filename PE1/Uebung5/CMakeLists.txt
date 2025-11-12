project(Uebung5 C)

set(CMAKE_C_STANDARD 17)

add_executable(Uebung5 main.c)

# 👇 This line fixes the exp() linking issue
target_link_libraries(Uebung5 m)
