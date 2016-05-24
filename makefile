#compiler
CC = gcc

#flags
CFLAGS = -g -Wall -std=c99 

#define
CDEF  = 

#target program
_TARGET = program
TARGET  := $(addprefix bin/,$(_TARGET))

#include directory
IDIR = -Iinclude/
#header files
HEADER := $(notdir $(wildcard $(IDIR)*.h))

#source files
SDIR = src/
_SRC := $(notdir $(wildcard $(SDIR)*.c))
SRC  := $(addprefix $(SDIR),$(_SRC))

#object files
ODIR = build/
_OBJ := $(patsubst %.c,%.o,$(_SRC))
OBJ  := $(addprefix $(ODIR),$(_OBJ))

#dependencies
DDIR = deps/
_DEPS := $(patsubst %.o,%.d,$(_OBJ))
DEPS := $(addprefix $(DDIR),$(_DEPS))

#default target
all: $(TARGET) 

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

#include dependencies in the makefile, so rebuilds itself. 
#If a .c or .h has been changed, gcc recompiles them.
#The minus sign '-' prevent from error if a file is removed or renamed.
-include $(DEPS)

#first create object files,
#the updates dependencies
$(ODIR)%.o: $(SDIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(IDIR)
	$(CC) -MM -MT $(ODIR)$*.o $(CFLAGS) $(IDIR) \
	$(SDIR)$*.c > $(DDIR)$*.d
	@cp -f $(DDIR)$*.d $(DDIR)$*.d.tmp
	@sed -e 's/.*://' -e 's/\\\\$$//' < $(DDIR)$*.d.tmp | fmt -1 | \
		sed -e 's/^ *//' -e 's/$$/:/' >> $(DDIR)$*.d
	@rm -f $(DDIR)$*.d.tmp

#run executable
.PHONY: run
run: $(TARGET)
	bin/program

#clean objects
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET) $(DEPS)
	
