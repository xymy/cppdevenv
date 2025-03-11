add_executable(sizeof "main.cpp")
target_compile_features(sizeof PRIVATE cxx_std_20)
target_link_libraries(sizeof PRIVATE fmt::fmt)
