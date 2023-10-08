set(LIB_NAME database)
add_library(${LIB_NAME} STATIC)
set(SRC_FILES
Auto-odb.cxx
Person-odb.cxx
Route-odb.cxx
JournalRow-odb.cxx
Auto.cpp
Person.cpp
Route.cpp
JournalRow.cpp
DbApi.cpp
DatabaseConnection.cpp
)
target_sources(${LIB_NAME} PRIVATE ${SRC_FILES})