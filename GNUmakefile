# Developer convenience wrapper — takes precedence over CMake's generated Makefile.
# Delegates to an out-of-source cmake build so the source tree stays clean.
#
#   make              build the application  (build/)
#   make test         build + run all tests  (build-test/)
#   make coverage     test + HTML report     (build-cov/)
#   make mutate       mutation test run      (requires dextool)
#   make clean        remove all build dirs

BUILD     := build
BUILD_TST := build-test
BUILD_COV := build-cov
JOBS      := $(shell nproc 2>/dev/null || echo 4)
CMAKE     := cmake

.PHONY: all build test coverage mutate clean

all: build

build:
	$(CMAKE) -B $(BUILD) -DENABLE_TESTS=OFF
	$(CMAKE) --build $(BUILD) -j$(JOBS)

test:
	$(CMAKE) -B $(BUILD_TST) -DENABLE_TESTS=ON
	$(CMAKE) --build $(BUILD_TST) -j$(JOBS)
	ctest --test-dir $(BUILD_TST) -j$(JOBS) --output-on-failure

coverage:
	$(CMAKE) -B $(BUILD_COV) -DENABLE_TESTS=ON -DENABLE_COVERAGE=ON
	$(CMAKE) --build $(BUILD_COV) -j$(JOBS)
	$(CMAKE) --build $(BUILD_COV) --target coverage
	@echo "Report: $(BUILD_COV)/coverage-report/index.html"

mutate: test
	dextool mutate run --config dextool-mutate.toml

clean:
	rm -rf $(BUILD) $(BUILD_TST) $(BUILD_COV)
