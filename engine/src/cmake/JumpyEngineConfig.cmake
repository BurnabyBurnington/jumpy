get_filename_component(CUSTOM_SCHEMAS_DIRECTORY "${CMAKE_CURRENT_LIST_FILE}" PATH)

if(NOT TARGET jumpy_engine::jumpy_engine)
    include("${CUSTOM_SCHEMAS_DIRECTORY}/JumpyEngineTargets.cmake")
endif()
