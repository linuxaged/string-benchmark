#include <benchmark/benchmark.h>
#include <absl/strings/str_split.h>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <Corrade/Utility/String.h>
#include <array>

std::vector<std::string> split_move(const std::string& string, const char delimiter) {
	std::vector<std::string> parts;
	std::size_t oldpos = 0, pos = std::string::npos;

	while((pos = string.find(delimiter, oldpos)) != std::string::npos) {
		parts.emplace_back(std::move(string.substr(oldpos, pos - oldpos)));
		oldpos = pos + 1;
	}

	if(!string.empty())
		parts.emplace_back(std::move(string.substr(oldpos)));

	return parts;
}

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

void split_corrade_move() {
	std::string text("asfasdfas asf asdf s asdf asdf asdf fdfd fda");
	std::vector<std::string> substrs = split_move(text, ' ');
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

static void BM_corrade_move(benchmark::State& state) {
	for(auto _ : state) {
		split_corrade_move();
	}
}

BENCHMARK(BM_absl);
BENCHMARK(BM_boost);
BENCHMARK(BM_corrade);
BENCHMARK(BM_corrade_move);

BENCHMARK_MAIN();
