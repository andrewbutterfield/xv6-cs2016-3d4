OBJS = \
	swtch.o\
	proc.o\
	main.o\

	# mp.o\
	# spinlock.o\
	# vm.o\
	# bio.o\
	# console.o\
	# exec.o\
	# file.o\
	# fs.o\
	# ide.o\
	# ioapic.o\
	# kalloc.o\
	# kbd.o\
	# lapic.o\
	# log.o\
	# picirq.o\
	# pipe.o\
	# sleeplock.o\
	# string.o\
	# swtch.o\
	# syscall.o\
	# sysfile.o\
	# sysproc.o\
	# trapasm.o\
	# trap.o\
	# uart.o\
	# vectors.o\


sim : $(OBJS)
	cc -o sim $(OBJS)

%.o: %.c
	cc -c -o $@ $<

clean :
	rm sim $(OBJS)

# edit : main.o kbd.o command.o display.o \
#        insert.o search.o files.o utils.o
#         cc -o edit main.o kbd.o command.o display.o \
#                    insert.o search.o files.o utils.o
#
# main.o : main.c defs.h
#         cc -c main.c
# kbd.o : kbd.c defs.h command.h
#         cc -c kbd.c
# command.o : command.c defs.h command.h
#         cc -c command.c
# display.o : display.c defs.h buffer.h
#         cc -c display.c
# insert.o : insert.c defs.h buffer.h
#         cc -c insert.c
# search.o : search.c defs.h buffer.h
#         cc -c search.c
# files.o : files.c defs.h buffer.h command.h
#         cc -c files.c
# utils.o : utils.c defs.h
#         cc -c utils.c
# clean :
#         rm edit main.o kbd.o command.o display.o \
#            insert.o search.o files.o utils.o
