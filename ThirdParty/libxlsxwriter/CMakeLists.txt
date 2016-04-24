GET_CURRENT_FOLDER( CURRENT_FOLDER )

SET(TARGET_NAME ${CURRENT_FOLDER})

INCLUDE_DIRECTORIES(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	$ENV{STENGINE_ROOT}/include
)

LINK_DIRECTORIES(
	$ENV{STENGINE_ROOT}/lib
)

#find_package( zlib )
#find_package( minizip )
#SET( TARGET_ADDED_LIBRARIES_RD zlib minizip )
SET( TARGET_COMMON_LIBRARIES zlib minizip )

FILE(GLOB H_FILE_LIST	"include/*.h" )
FILE(GLOB SRC_FILE_LIST	"src/*.c")

SET(TARGET_H	${H_FILE_LIST})
SET(TARGET_SRC
	${SRC_FILE_LIST} 
#	"examples/anatomy.c"
#	"examples/array_formula.c"
#	"examples/autofilter.c"
#	"examples/constant_memory.c"
#	"examples/dates_and_times01.c"
#	"examples/dates_and_times02.c"
#	"examples/dates_and_times03.c"
#	"examples/defined_name.c"
#	"examples/demo.c"
#	"examples/doc_properties.c"
#	"examples/format_font.c"
#	"examples/format_num_format.c"
#	"examples/headers_footers.c"
#	"examples/hello.c"
#	"examples/hide_row_col.c"
#	"examples/hide_sheet.c"
#	"examples/hyperlinks.c"
#	"examples/images.c"
#	"examples/merge_range.c"
#	"examples/panes.c"
#	"examples/tab_colors.c"
#	"examples/tutorial1.c"
#	"examples/tutorial2.c"
#	"examples/tutorial3.c"
#	"examples/utf8.c"
#	"examples/worksheet_protection.c"
)
#message( ${TARGET_SRC} )

#SETUP_PROJECT(${TARGET_NAME})

#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/anatomy.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/array_formula.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/autofilter.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/constant_memory.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/dates_and_times01.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/dates_and_times02.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/dates_and_times03.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/defined_name.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/demo.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/doc_properties.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/format_font.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/format_num_format.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/headers_footers.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/hello.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/hide_row_col.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/hide_sheet.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/hyperlinks.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/images.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/merge_range.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/panes.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/tab_colors.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/tutorial1.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/tutorial2.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/tutorial3.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/utf8.c" ）
#SETUP_MUTIPROJECT( ${TARGET_NAME} "examples/worksheet_protection.c" ）

FILE(GLOB EXAMPLE_FILE_LIST	"examples/*.c")

FOREACH( EXAMPLE ${EXAMPLE_FILE_LIST} )
	STRING( REGEX REPLACE ".*/(.*).c" "\\1" EXAMPLE_NAME ${EXAMPLE} )

	#message( ${EXAMPLE} )
	#message( ${EXAMPLE_NAME} )

	SET( TARGET_SRC ${SRC_FILE_LIST} ${EXAMPLE} )
	SET( TARGET_NAME ${CURRENT_FOLDER}_${EXAMPLE_NAME} )
	#SETUP_MUTIPROJECT( ${TARGET_NAME} )

	#message( ${TARGET_NAME} )

ENDFOREACH( EXAMPLE ${EXAMPLE_FILE_LIST} )
