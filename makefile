# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
#
# Makefile for Coalesce utility
#
#----------------------------------------------------------------------------
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make test = Run tests on created files.
#
# To rebuild project do "make clean" then "make all".
#----------------------------------------------------------------------------

TARGET_DIR = bin/
TARGET = Coalesce 


# Object files directory
#     To put object files in current directory, use a dot (.), do NOT make
#     this an empty or blank macro!
OBJDIR = build/ 


# List C source files here. (C dependencies are automatically generated.)
SRC = 


# List C++ source files here. (C dependencies are automatically generated.)
CPPSRC = $(TARGET).cpp


#---------------- Compiler Options C++ ----------------
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -Wall...:     warning level
CPPFLAGS = -g$(DEBUG)
CPPFLAGS += $(CPPDEFS)


# List any extra directories to look for include files here.
EXTRAINCDIRS = 

all: clean coa

coa:
	g++ -Wall coalesce.cpp -o bin/coa

test:
	nothing 

clean:
	rm -rf bin/*; rm -Rf build/*

# Listing of phony targets.
.PHONY : all begin finish end sizebefore sizeafter gccversion \
build elf hex eep lss sym coff extcoff doxygen clean          \
clean_list clean_doxygen program dfu flip flip-ee dfu-ee      \
debug gdb-config


