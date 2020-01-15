# Install Dependencies

	vcpkg install benchmark
	vcpkg install abseil
	vcpkg install boost
	vcpkg install corrade

# Result

	01/15/20 09:06:18
	Running C:\workspace\string-benchmark\build\Release\main.exe
	Run on (6 X 2904 MHz CPU s)
	CPU Caches:
	  L1 Data 32K (x6)
	  L1 Instruction 32K (x6)
	  L2 Unified 262K (x6)
	  L3 Unified 9437K (x1)
	-----------------------------------------------------
	Benchmark           Time             CPU   Iterations
	-----------------------------------------------------
	BM_absl           434 ns          433 ns      1659259
	BM_boost         1102 ns         1099 ns       640000
	BM_corrade        711 ns          698 ns       896000