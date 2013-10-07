#Set this to @ to keep the makefile quiet
SILENCE = @
CPPUTEST_HOME =  /Users/james/repos/github/cpputest/builds/mp-gcc44
#---- Outputs ----#
COMPONENT_NAME = Untitled

#--- Inputs ----#
PROJECT_HOME_DIR = .

SRC_FILES = TddStart.cpp TddStartMain.cpp

TEST_SRC_FILES = AllTests.cpp TddStartTest.cpp TddStartMainTest.cpp 

INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include/ \
  $(CPPUTEST_HOME)/include/Platforms/Gcc\

CPPUTEST_WARNINGFLAGS = -Wall -Werror -Wswitch-default  -Wfatal-errors
CPPUTEST_CXXFLAGS =  -std=c++0x
CPPUTEST_CFLAGS = -std=c99

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
