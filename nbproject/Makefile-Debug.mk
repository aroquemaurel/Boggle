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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/dictionnaire.o \
	${OBJECTDIR}/src/interfaceNcurses.o \
	${OBJECTDIR}/src/interfaceTexte.o \
	${OBJECTDIR}/src/jeu.o \
	${OBJECTDIR}/src/plateau.o \
	${OBJECTDIR}/src/resolveur.o \
	${OBJECTDIR}/src/solution.o \
	${OBJECTDIR}/src/util.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	tests/dicoTests \
	tests/jeuTest \
	tests/plateauTests \
	tests/solutionTests \
	tests/utilTests

# C Compiler Flags
CFLAGS=-lncurses -lpanel -lmenu

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-LCunit/lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk boggle

boggle: ${OBJECTFILES}
	${LINK.c} -o boggle ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/src/dictionnaire.o: nbproject/Makefile-${CND_CONF}.mk src/dictionnaire.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/dictionnaire.o src/dictionnaire.c

${OBJECTDIR}/src/interfaceNcurses.o: nbproject/Makefile-${CND_CONF}.mk src/interfaceNcurses.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/interfaceNcurses.o src/interfaceNcurses.c

${OBJECTDIR}/src/interfaceTexte.o: nbproject/Makefile-${CND_CONF}.mk src/interfaceTexte.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/interfaceTexte.o src/interfaceTexte.c

${OBJECTDIR}/src/jeu.o: nbproject/Makefile-${CND_CONF}.mk src/jeu.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/jeu.o src/jeu.c

${OBJECTDIR}/src/plateau.o: nbproject/Makefile-${CND_CONF}.mk src/plateau.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/plateau.o src/plateau.c

${OBJECTDIR}/src/resolveur.o: nbproject/Makefile-${CND_CONF}.mk src/resolveur.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/resolveur.o src/resolveur.c

${OBJECTDIR}/src/solution.o: nbproject/Makefile-${CND_CONF}.mk src/solution.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/solution.o src/solution.c

${OBJECTDIR}/src/util.o: nbproject/Makefile-${CND_CONF}.mk src/util.c 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/util.o src/util.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
tests/dicoTests: ${TESTDIR}/tests/dicoTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p tests
	${LINK.c} -LCunit/lib -lcunit  -o tests/dicoTests $^ ${LDLIBSOPTIONS} Cunit/lib/libcunit.so `cppunit-config --libs`   

tests/jeuTest: ${TESTDIR}/tests/jeuTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p tests
	${LINK.c} -LCunit/lib -lcunit  -o tests/jeuTest $^ ${LDLIBSOPTIONS} Cunit/lib/libcunit.so `cppunit-config --libs`   

tests/plateauTests: ${TESTDIR}/tests/plateauTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p tests
	${LINK.c} -LCunit/lib -lcunit  -o tests/plateauTests $^ ${LDLIBSOPTIONS} Cunit/lib/libcunit.so `cppunit-config --libs`   

tests/solutionTests: ${TESTDIR}/tests/solutionTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p tests
	${LINK.c} -LCunit/lib -lcunit  -o tests/solutionTests $^ ${LDLIBSOPTIONS} Cunit/lib/libcunit.so `cppunit-config --libs`   

tests/utilTests: ${TESTDIR}/tests/utilTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p tests
	${LINK.c} -LCunit/lib -lcunit  -o tests/utilTests $^ ${LDLIBSOPTIONS} Cunit/lib/libcunit.so `cppunit-config --libs`   


${TESTDIR}/tests/dicoTests.o: tests/dicoTests.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -ICunit/CUnit/Headers -std=c99 -lncurses -lpanel -lmenu -LCunit/lib -lcunit `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/dicoTests.o tests/dicoTests.c


${TESTDIR}/tests/jeuTest.o: tests/jeuTest.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -ICunit/CUnit/Headers -std=c99 -lncurses -lpanel -lmenu -LCunit/lib -lcunit `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/jeuTest.o tests/jeuTest.c


${TESTDIR}/tests/plateauTests.o: tests/plateauTests.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -ICunit/CUnit/Headers -std=c99 -lncurses -lpanel -lmenu -LCunit/lib -lcunit `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/plateauTests.o tests/plateauTests.c


${TESTDIR}/tests/solutionTests.o: tests/solutionTests.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -ICunit/CUnit/Headers -std=c99 -lncurses -lpanel -lmenu -LCunit/lib -lcunit `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/solutionTests.o tests/solutionTests.c


${TESTDIR}/tests/utilTests.o: tests/utilTests.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -g -Ilib -ICunit -ICunit/CUnit/Headers -std=c99 -lncurses -lpanel -lmenu -LCunit/lib -lcunit `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/utilTests.o tests/utilTests.c


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/src/dictionnaire_nomain.o: ${OBJECTDIR}/src/dictionnaire.o src/dictionnaire.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/dictionnaire.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/dictionnaire_nomain.o src/dictionnaire.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/dictionnaire.o ${OBJECTDIR}/src/dictionnaire_nomain.o;\
	fi

${OBJECTDIR}/src/interfaceNcurses_nomain.o: ${OBJECTDIR}/src/interfaceNcurses.o src/interfaceNcurses.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/interfaceNcurses.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/interfaceNcurses_nomain.o src/interfaceNcurses.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/interfaceNcurses.o ${OBJECTDIR}/src/interfaceNcurses_nomain.o;\
	fi

${OBJECTDIR}/src/interfaceTexte_nomain.o: ${OBJECTDIR}/src/interfaceTexte.o src/interfaceTexte.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/interfaceTexte.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/interfaceTexte_nomain.o src/interfaceTexte.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/interfaceTexte.o ${OBJECTDIR}/src/interfaceTexte_nomain.o;\
	fi

${OBJECTDIR}/src/jeu_nomain.o: ${OBJECTDIR}/src/jeu.o src/jeu.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/jeu.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/jeu_nomain.o src/jeu.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/jeu.o ${OBJECTDIR}/src/jeu_nomain.o;\
	fi

${OBJECTDIR}/src/plateau_nomain.o: ${OBJECTDIR}/src/plateau.o src/plateau.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/plateau.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/plateau_nomain.o src/plateau.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/plateau.o ${OBJECTDIR}/src/plateau_nomain.o;\
	fi

${OBJECTDIR}/src/resolveur_nomain.o: ${OBJECTDIR}/src/resolveur.o src/resolveur.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/resolveur.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/resolveur_nomain.o src/resolveur.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/resolveur.o ${OBJECTDIR}/src/resolveur_nomain.o;\
	fi

${OBJECTDIR}/src/solution_nomain.o: ${OBJECTDIR}/src/solution.o src/solution.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/solution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/solution_nomain.o src/solution.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/solution.o ${OBJECTDIR}/src/solution_nomain.o;\
	fi

${OBJECTDIR}/src/util_nomain.o: ${OBJECTDIR}/src/util.o src/util.c 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/util.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Ilib -ICunit -std=c99 -lncurses -lpanel -lmenu -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/util_nomain.o src/util.c;\
	else  \
	    ${CP} ${OBJECTDIR}/src/util.o ${OBJECTDIR}/src/util_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    tests/dicoTests || true; \
	    tests/jeuTest || true; \
	    tests/plateauTests || true; \
	    tests/solutionTests || true; \
	    tests/utilTests || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} boggle

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
