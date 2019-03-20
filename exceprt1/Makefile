OBJS = swtch.o proc.o main.o\

sim : $(OBJS)
	cc -o sim $(OBJS)

%.o: %.c
	cc -c -o $@ $<

clean :
	rm sim $(OBJS)
