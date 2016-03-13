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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/call_by_reference.o \
	${OBJECTDIR}/call_by_value.o \
	${OBJECTDIR}/is_it_legal_triangle.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/triangle_angleA.o \
	${OBJECTDIR}/triangle_angleB.o \
	${OBJECTDIR}/triangle_angleC.o \
	${OBJECTDIR}/triangle_area.o \
	${OBJECTDIR}/triangle_constructor.o \
	${OBJECTDIR}/triangle_input.o \
	${OBJECTDIR}/triangle_is_a_right_angle_triangle.o \
	${OBJECTDIR}/triangle_output.o \
	${OBJECTDIR}/triangle_perimeter.o \
	${OBJECTDIR}/triangle_set.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw_3

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw_3: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw_3 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/call_by_reference.o: call_by_reference.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/call_by_reference.o call_by_reference.cpp

${OBJECTDIR}/call_by_value.o: call_by_value.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/call_by_value.o call_by_value.cpp

${OBJECTDIR}/is_it_legal_triangle.o: is_it_legal_triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/is_it_legal_triangle.o is_it_legal_triangle.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/triangle_angleA.o: triangle_angleA.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_angleA.o triangle_angleA.cpp

${OBJECTDIR}/triangle_angleB.o: triangle_angleB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_angleB.o triangle_angleB.cpp

${OBJECTDIR}/triangle_angleC.o: triangle_angleC.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_angleC.o triangle_angleC.cpp

${OBJECTDIR}/triangle_area.o: triangle_area.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_area.o triangle_area.cpp

${OBJECTDIR}/triangle_constructor.o: triangle_constructor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_constructor.o triangle_constructor.cpp

${OBJECTDIR}/triangle_input.o: triangle_input.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_input.o triangle_input.cpp

${OBJECTDIR}/triangle_is_a_right_angle_triangle.o: triangle_is_a_right_angle_triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_is_a_right_angle_triangle.o triangle_is_a_right_angle_triangle.cpp

${OBJECTDIR}/triangle_output.o: triangle_output.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_output.o triangle_output.cpp

${OBJECTDIR}/triangle_perimeter.o: triangle_perimeter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_perimeter.o triangle_perimeter.cpp

${OBJECTDIR}/triangle_set.o: triangle_set.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/triangle_set.o triangle_set.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hw_3

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
