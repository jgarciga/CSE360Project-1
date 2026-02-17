# Example GUI App CMakeLists.txt

cmake_minimum_required(VERSION 3.22)

project(CSE360Project VERSION 0.0.1)

set(JUCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../JUCE")
add_subdirectory("${JUCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/JUCE")

juce_add_gui_app(CSE360Project
    PRODUCT_NAME "CSE360 Project")

target_sources(CSE360Project
    PRIVATE
        Main.cpp
        MainComponent.cpp)

target_compile_definitions(CSE360Project
    PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:CSE360Project,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:CSE360Project,JUCE_VERSION>")

target_link_libraries(CSE360Project
    PRIVATE
        juce::juce_gui_extra
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)