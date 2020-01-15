cmake_minimum_required(VERSION 3.14)

project(string-benchmark)

find_package(benchmark CONFIG REQUIRED)
find_package(absl CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS regex)
find_package(Corrade CONFIG REQUIRED Utility)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE 
	benchmark::benchmark 
	benchmark::benchmark_main
	absl::strings
	Boost::regex
	Corrade::Utility
)
