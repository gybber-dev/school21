#
# run from the folder of your project
#
#

mkdir -p Google_tests && cd Google_tests
git clone https://github.com/google/googletest.git lib
#rm -fR ./lib/googletest-master/.git* && echo "DELTEED" || echo "some error"

#echo 'add_subdirectory(lib/googletest-master)' >> CMakeLists.txt
#echo 'include_directories(lib/googletest-master/googletest/include)' >> CMakeLists.txt
#echo 'include_directories(lib/googletest-master/googlemock/include)' >> CMakeLists.txt
#echo "target_link_libraries(minishell gtest gtest_main)" >> CMakeLists.txt

