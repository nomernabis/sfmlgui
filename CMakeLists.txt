

set(LIB_SRC ui/Container.cpp ui/Container.h ui/Node.cpp ui/Node.h ui/Utils.cpp ui/Utils.h ui/elements/TextNode.cpp ui/elements/TextNode.h ui/elements/Button.cpp ui/elements/Button.h ui/MenuList.cpp ui/MenuList.h)
SET(LIB_TYPE STATIC)

add_library(ui ${LIB_TYPE} ${LIB_SRC})
file(COPY ui/resources DESTINATION ${CMAKE_BINARY_DIR})