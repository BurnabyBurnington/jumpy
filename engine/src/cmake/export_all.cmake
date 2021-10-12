set(PLUGIN_TARGETS_NAME JumpyEngineTargets)
set(INSTALL_CONFIGURATION_DIRECTORY lib/cmake/jumpy_engine)

# 1. Export individual targets (even if it's only one)
install(
    TARGETS jumpy_engine
    EXPORT ${PLUGIN_TARGETS_NAME}
    LIBRARY DESTINATION lib
    INCLUDES DESTINATION include
)

# 2. Export everything
install(
    EXPORT ${PLUGIN_TARGETS_NAME}
    FILE ${PLUGIN_TARGETS_NAME}.cmake
    NAMESPACE jumpy_engine::
    DESTINATION ${INSTALL_CONFIGURATION_DIRECTORY}
)

# 3. Create a Config.cmake so we can use find_package with our exported engine
include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/JumpyEngineConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/JumpyEngineConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGURATION_DIRECTORY}
)

# 4. Copy the generated files
install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/JumpyEngineConfig.cmake
        DESTINATION ${INSTALL_CONFIGURATION_DIRECTORY}
)
