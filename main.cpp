#include <benchmark/benchmark.h>
#include <absl/strings/str_split.h>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <Corrade/Utility/String.h>
#include <array>

void split_absl() {
	std::string text("asfasdfas asf asdf s asdf asdf asdf fdfd fda");
	std::vector<std::string> substrs = absl::StrSplit(text, ' ');
}

void split_boost() {
	std::string text("asfasdfas asf asdf s asdf asdf asdf fdfd fda");
	std::vector<std::string> substrs;
	boost::split(substrs, text, boost::is_any_of(" "));
}

void split_corrade() {
	std::string text("asfasdfas asf asdf s asdf asdf asdf fdfd fda");
	std::vector<std::string> substrs = Corrade::Utility::String::splitWithoutEmptyParts(text, ' ');
}

static void BM_absl(benchmark::State& state) {
  for (auto _ : state) {
	  split_absl();
  }
}

static void BM_boost(benchmark::State& state) {
	for(auto _ : state) {
		split_boost();
	}
}

static void BM_corrade(benchmark::State& state) {
	for(auto _ : state) {
		split_corrade();
	}
}

BENCHMARK(BM_absl);
BENCHMARK(BM_boost);
BENCHMARK(BM_corrade);

BENCHMARK_MAIN();
