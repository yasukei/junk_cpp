cmake_minimum_required(VERSION 3.2)

get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${DIR_NAME})

find_package (Threads)

add_executable(
	${PROJECT_NAME}
	"main.cpp"
	"cac.cpp"
	)

target_compile_features(
	${PROJECT_NAME}
	PUBLIC cxx_std_11
	)

target_link_libraries(
	${PROJECT_NAME}
	${CMAKE_THREAD_LIBS_INIT}
	)

add_test(
	NAME ${PROJECT_NAME}
	COMMAND $<TARGET_FILE:${PROJECT_NAME}>
	)

