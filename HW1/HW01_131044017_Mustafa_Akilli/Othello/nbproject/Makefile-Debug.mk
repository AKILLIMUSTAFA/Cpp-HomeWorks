#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/board_size.o \
	${OBJECTDIR}/does_player_have_move.o \
	${OBJECTDIR}/does_player_have_move_is_it_legal_move.o \
	${OBJECTDIR}/does_player_have_move_reset_structs.o \
	${OBJECTDIR}/does_player_have_move_which_ones_has_computer_icon_on_around.o \
	${OBJECTDIR}/does_player_have_move_which_ones_is_player_icon.o \
	${OBJECTDIR}/first_view.o \
	${OBJECTDIR}/for_computer_do_best_move.o \
	${OBJECTDIR}/for_computer_is_it_legal_move.o \
	${OBJECTDIR}/for_computer_move.o \
	${OBJECTDIR}/for_computer_reset_structs.o \
	${OBJECTDIR}/for_computer_which_one_is_smartest_move.o \
	${OBJECTDIR}/for_computer_which_ones_has_player_icon_on_around.o \
	${OBJECTDIR}/for_computer_which_ones_is_empty_icon.o \
	${OBJECTDIR}/for_player_is_it_empty_icon.o \
	${OBJECTDIR}/for_player_is_it_legal_move.o \
	${OBJECTDIR}/for_player_move.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/paint_board.o \
	${OBJECTDIR}/scoreboard.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/othello

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/othello: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/othello ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/board_size.o: board_size.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/board_size.o board_size.cpp

${OBJECTDIR}/does_player_have_move.o: does_player_have_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/does_player_have_move.o does_player_have_move.cpp

${OBJECTDIR}/does_player_have_move_is_it_legal_move.o: does_player_have_move_is_it_legal_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/does_player_have_move_is_it_legal_move.o does_player_have_move_is_it_legal_move.cpp

${OBJECTDIR}/does_player_have_move_reset_structs.o: does_player_have_move_reset_structs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/does_player_have_move_reset_structs.o does_player_have_move_reset_structs.cpp

${OBJECTDIR}/does_player_have_move_which_ones_has_computer_icon_on_around.o: does_player_have_move_which_ones_has_computer_icon_on_around.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/does_player_have_move_which_ones_has_computer_icon_on_around.o does_player_have_move_which_ones_has_computer_icon_on_around.cpp

${OBJECTDIR}/does_player_have_move_which_ones_is_player_icon.o: does_player_have_move_which_ones_is_player_icon.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/does_player_have_move_which_ones_is_player_icon.o does_player_have_move_which_ones_is_player_icon.cpp

${OBJECTDIR}/first_view.o: first_view.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/first_view.o first_view.cpp

${OBJECTDIR}/for_computer_do_best_move.o: for_computer_do_best_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_computer_do_best_move.o for_computer_do_best_move.cpp

${OBJECTDIR}/for_computer_is_it_legal_move.o: for_computer_is_it_legal_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_computer_is_it_legal_move.o for_computer_is_it_legal_move.cpp

${OBJECTDIR}/for_computer_move.o: for_computer_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_computer_move.o for_computer_move.cpp

${OBJECTDIR}/for_computer_reset_structs.o: for_computer_reset_structs.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_computer_reset_structs.o for_computer_reset_structs.cpp

${OBJECTDIR}/for_computer_which_one_is_smartest_move.o: for_computer_which_one_is_smartest_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_computer_which_one_is_smartest_move.o for_computer_which_one_is_smartest_move.cpp

${OBJECTDIR}/for_computer_which_ones_has_player_icon_on_around.o: for_computer_which_ones_has_player_icon_on_around.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_computer_which_ones_has_player_icon_on_around.o for_computer_which_ones_has_player_icon_on_around.cpp

${OBJECTDIR}/for_computer_which_ones_is_empty_icon.o: for_computer_which_ones_is_empty_icon.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_computer_which_ones_is_empty_icon.o for_computer_which_ones_is_empty_icon.cpp

${OBJECTDIR}/for_player_is_it_empty_icon.o: for_player_is_it_empty_icon.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_player_is_it_empty_icon.o for_player_is_it_empty_icon.cpp

${OBJECTDIR}/for_player_is_it_legal_move.o: for_player_is_it_legal_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_player_is_it_legal_move.o for_player_is_it_legal_move.cpp

${OBJECTDIR}/for_player_move.o: for_player_move.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/for_player_move.o for_player_move.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/paint_board.o: paint_board.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/paint_board.o paint_board.cpp

${OBJECTDIR}/scoreboard.o: scoreboard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/scoreboard.o scoreboard.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/othello

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
