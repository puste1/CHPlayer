cmake_minimum_required(VERSION 3.22)
project(CHPlayerQT)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Multimedia)
pkg_check_modules(VLC REQUIRED libvlc)
qt6_add_resources(MY_RESOURCES resources.qrc)
add_executable(my_app main.cpp mainwindow.cpp ${MY_RESOURCES} ${MY_FORMS_HEADERS})

qt_standard_project_setup()

qt_add_executable(CHPlayerQT main.cpp mainwindow.cpp)
target_link_libraries(CHPlayerQT PRIVATE Qt6::Core Qt6::Widgets Qt6::Multimedia ${VLC_LIBRARIES})



# Install the executable into "${CMAKE_INSTALL_PREFIX}/bin".
install(TARGETS CHPlayerQT
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Generate the deployment script for the target MyApp.
qt_generate_deploy_app_script(
    TARGET CHPlayerQT
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)

# Call the deployment script on "cmake --install".
install(SCRIPT ${deploy_script})
