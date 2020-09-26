add_library(LxRunOfflineDll SHARED
	main.cpp
	res/resources.rc)

configure_file(config.h.in config.h)
target_include_directories(LxRunOfflineDll PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(LxRunOfflineDll PRIVATE LibLxRunOffline)

if(MSVC)
	target_link_options(LxRunOfflineDll PRIVATE /MANIFEST:NO)
endif()

install(TARGETS LxRunOfflineDll RUNTIME DESTINATION .)
