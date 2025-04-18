add_executable(ebo "main.cpp")
target_compile_features(ebo PRIVATE cxx_std_20)
target_link_libraries(ebo PRIVATE fmt::fmt)
