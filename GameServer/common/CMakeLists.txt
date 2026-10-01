add_library(GameServerCommon INTERFACE)
add_library(Abyss::Common ALIAS GameServerCommon)

target_include_directories(GameServerCommon  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})