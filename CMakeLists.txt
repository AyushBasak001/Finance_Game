cmake_minimum_required(VERSION 3.14)

project(finance_game LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(finance_game
  main.cpp
  player/player.h player/player.cpp
  player/playerstats.h player/playerstats.cpp
  player/playerpanel.h player/playerpanel.cpp
  cashflow/cashflow.h cashflow/cashflow.cpp
  cashflow/cashflowmanager.h cashflow/cashflowmanager.cpp
  cashflow/cashflowpanel.h cashflow/cashflowpanel.cpp
  banking/banking.h banking/banking.cpp
  banking/bankingmanager.h banking/bankingmanager.cpp
  banking/bankingpanel.h banking/bankingpanel.cpp
  investment/investment.h investment/investment.cpp
  investment/investmentmanager.h investment/investmentmanager.cpp
  investment/investmentpanel.h investment/investmentpanel.cpp

)
target_link_libraries(finance_game Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS finance_game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
