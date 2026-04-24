cmake_minimum_required(VERSION 3.10)
project(LaMoKey VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Fcitx5 package
find_package(ECM REQUIRED 1.0.0)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_MODULE_PATH})
find_package(Fcitx5Module REQUIRED)

# Include engine source files
set(ENGINE_SOURCES
    ../engine/Engine.cpp
    ../engine/ConvertTool.cpp
    ../engine/Macro.cpp
    ../engine/SmartSwitchKey.cpp
    ../engine/Vietnamese.cpp
)

# Fcitx5 client sources
set(CLIENT_SOURCES
    fcitx5-lamokey/lamokey_engine.cpp
)

include_directories(
    ../engine
)

add_library(lamokey MODULE ${ENGINE_SOURCES} ${CLIENT_SOURCES})

target_link_libraries(lamokey Fcitx5::Core Fcitx5::Config)
set_target_properties(lamokey PROPERTIES PREFIX "")

# Install rules
install(TARGETS lamokey DESTINATION ${FCITX5_INSTALL_ADDONDIR})
install(FILES fcitx5-lamokey/lamokey-addon.conf.in.in DESTINATION ${FCITX5_INSTALL_ADDONDIR})
install(FILES fcitx5-lamokey/lamokey.conf.in DESTINATION ${FCITX5_INSTALL_INPUTMETHODDIR})

# Packaging with CPack
set(CPACK_PACKAGE_NAME "fcitx5-lamokey")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "LaMoKey Vietnamese Input Method for Fcitx5")
set(CPACK_PACKAGE_VENDOR "LaMoKey Project")
set(CPACK_PACKAGE_CONTACT "lamokey@example.com")

set(CPACK_GENERATOR "DEB;RPM")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "LaMoKey Project")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "fcitx5")

include(CPack)
