BUILD_DIR=build
TARGET=thread

all:
	mkdir -p ${BUILD_DIR}
	cd ${BUILD_DIR} && cmake .. && make

clean:
	rm -rf ${BUILD_DIR}

rebuild: clean all

test: all
	cd ${BUILD_DIR} && ctest .. --verbose

run: test

