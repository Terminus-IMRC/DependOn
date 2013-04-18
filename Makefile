#20120323 fix a lot
#20120816 fix a lot from [ssk]
#20121225 from [LogicalHeart]. To allocate some memory is too slow.
#PROG=CountAr
PROG=Par
CFLAGS=-I. -Iheader -Wall -Wextra -O2
HDRS=def.h
GCHDRS=$(HDRS:%.h=%.h.gch)
SRCS=main.c findx.c separ.c DependOn.c
OBJS=$(SRCS:%.c=%.o)
INSTALL=install -s -p -o imrc -g staff -m 0777
X=3

all:	$(PROG)

$(PROG):	$(GCHDRS) $(OBJS)
	$(LINK.o) $(OUTPUT_OPTION) $(OBJS)

%.o:	%.c $(GCHDRS) $(MAKEFILE_LIST) /mnt/nfs/usr/bin/mpi/file/mpi.txt
	$(COMPILE.c) $(OUTPUT_OPTION) $<

%.h.gch:	%.h $(MAKEFILE_LIST)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

clean:
	$(RM) $(OBJS) $(GCHDRS) $(PROG)

run:	$(PROG)
	./$< $(X).txt

install:	$(PROG)
	$(INSTALL) $< /mnt/nfs/usr/bin

line:
	@wc -c -l $(SRCS) $(HDRS) $(MAKEFILE_LIST)

vrun:	$(PROG)
	valgrind --leak-check=no --track-origins=no -v ./$< $(X) $(ARG)
