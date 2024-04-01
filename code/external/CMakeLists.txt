add_subdirectory(Catch2)
add_subdirectory(GSL)
add_subdirectory(raylib EXCLUDE_FROM_ALL)

set(BOOST_INCLUDE_LIBRARIES interprocess date_time)
add_subdirectory(boost EXCLUDE_FROM_ALL)
