add_executable(helloworld
	main.cpp
)

target_link_libraries(helloworld PRIVATE Qt6::Widgets)
#
#
#
# add_library(jumpy_engine
#     SHARED
#         main.cpp
# )
# target_link_libraries(jumpy_engine PRIVATE Qt6::Widgets)
#
# install(
#     TARGETS jumpy_engine
#     DESTINATION .
# )
