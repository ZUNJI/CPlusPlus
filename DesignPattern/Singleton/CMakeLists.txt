﻿GET_CURRENT_FOLDER( CURRENT_FOLDER )

SET(TARGET_NAME ${CURRENT_FOLDER})

FILE(GLOB H_FILE_LIST	"Singleton.h")
FILE(GLOB SRC_FILE_LIST	"main.cpp")

SET(TARGET_H	${H_FILE_LIST})
SET(TARGET_SRC	${SRC_FILE_LIST})

SETUP_PROJECT(${TARGET_NAME})