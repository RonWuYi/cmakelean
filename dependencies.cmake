include(FetchContent)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG 76fb40d95455f249bd70824ecfcae7a8f0930fa3
)

FetchContent_MakeAvailable(spdlog)