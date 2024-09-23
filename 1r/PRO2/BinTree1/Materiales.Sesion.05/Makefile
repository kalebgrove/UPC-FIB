###############################################################################
# Paths & Configuration
###############################################################################
CPP=g++
CPP_FLAGS=-Wall

###############################################################################
# Modules
###############################################################################
BINARIES=bt1_example \
         bt2_io \
				 bt3_inline2visual \
				 bt4_exercise1 \
				 bt5_sum \
				 bt6_traversal \
				 bt7_exercise2

SRCS=$(addsuffix .cc, $(BINARIES))

###############################################################################
# Build rules
###############################################################################
all: CC_FLAGS+=-O3
all: $(BINARIES)

debug: CC_FLAGS+=-g
debug: $(BINARIES)

# General building rule
%: %.cc BinTree.hh
	$(CPP) $(CPP_FLAGS) $< -o $@

clean:
	rm -rf $(BINARIES) 2> /dev/null