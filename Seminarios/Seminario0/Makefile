################################################################################
# makefile
################################################################################

SHELL = /bin/bash

USER = gustavo
HOST = atcgrid.ugr.es
DEST = $(USER)@$(HOST)
SSH  = ssh -o PasswordAuthentication=no $(DEST)

SRC = $(wildcard *.c *.cc)
EXE = $(filter-out suma,$(basename $(SRC)))
SUM = $(wildcard suma*.cc)
LOG = $(filter-out suma.log,$(SUM:.cc=.log))
SVG = $(SUM:.cc=.svg)

CFLAGS = -fopenmp -O2 -Wall
CXXFLAGS = $(CFLAGS) -std=c++11
LDFLAGS = -lrt

PLOT = set terminal svg enhanced; \
       set output '$@'; \
       set grid; \
       set xlabel 'size (double)'; \
       set ylabel 'time'; \
       set key bottom; \
       set logscale x 2; \
       set logscale y 10; \
       set xtics rotate; \
       set xtics (1, 2, 4, 8, 16, 32, 64, 128, 256, 512, '1K' 1024, '2K' 2048, '4K' 4096, '8K' 8192, '16K' 16384, '32K' 32768, '64K' 65526, '128K' 131072, '256K' 262144, '512K' 524288, '1M' 1048576, '2M' 2097152, '4M' 4194304, '8M' 8388608, '16M' 16777216, '32M' 33554432, '64M' 67108864, '128M' 134217728, '256M' 268435456, '512M' 536870912, '1G' 1073741824); \
       set ytics ('1ns' 1, '10ns' 10, '100ns' 100, '1us' 1e3, '10us' 1e4, '100us' 1e5, '1ms' 1e6, '10ms' 1e7, '100ms' 1e8, '1s' 1e9, '10s' 1e10, '100s' 1e11)

################################################################################

default: $(EXE)

all: rsync $(SVG)

check:
	@if [ "$$HOSTNAME" != "atcgrid.ugr.es" ]; then \
		if [ ! -e ~/.ssh/id_rsa ]; then \
			echo "please, press enter 3 times... ;)"; \
			ssh-keygen; \
		fi; \
		if ! $(SSH) ls > /dev/null; then \
			ssh-copy-id $(DEST); \
		fi; \
	fi

clean: check
	$(RM) -v $(EXE) $(LOG) $(SVG) STDIN.* core.* *.{e,o}[[:digit:]]* *~
	if [ "$$HOSTNAME" != "atcgrid.ugr.es" ]; then \
		$(SSH) make -C 0 clean || true & \
	fi

rsync: clean
	if [ "$$HOSTNAME" != "atcgrid.ugr.es" ]; then \
		rsync -avr . $(DEST):0; \
	fi

################################################################################

suma-data : CFLAGS += -DDATA
suma-heap : CFLAGS += -DHEAP
suma-stack: CFLAGS += -DSTACK

%.log: %
	@if [ "$$HOSTNAME" == "atcgrid.ugr.es" ]; then \
		ulimit -s unlimited; \
		echo creando $@...; \
		for (( i=65536; i<=67108864; i*=2 )); do \
			while [ "`qstat`" ]; do sleep 1; done; \
			work=`echo 0/$< $$i | qsub -q ac`; \
			pid=$${work%.atcgrid}; \
			while [ "`qstat`" ]; do sleep 1; done; \
			if [ -s STDIN.e$$pid ]; then \
				echo "fallo en $< $$i:"; \
				cat STDIN.e$$pid; \
				exit 1; \
			else \
				echo -n "$$i " >> $@; \
				cat STDIN.o$$pid >> $@; \
				tail -n 1 -q $@; \
				$(RM) -f STDIN.e$$pid STDIN.o$$pid; \
			fi; \
		done; \
	else \
		$(SSH) make -C 0 $@; \
		scp $(DEST):0/$@ .; \
	fi

%.svg: %.log
	gnuplot <<< "$(PLOT); plot '$<' u 1:2 w lp lc 1 pt 5"

suma.svg: $(LOG)
	gnuplot <<< "$(PLOT); plot 'suma-data.log' u 1:2 w lp lc 1 pt 5 title 'data', 'suma-heap.log' u 1:2 w lp lc 2 pt 7 title 'heap', 'suma-stack.log' u 1:2 w lp lc 3 pt 9 title 'stack'"

################################################################################

.PHONY: all check clean default rsync
.PRECIOUS: $(LOG)
.NOEXPORT:

################################################################################
