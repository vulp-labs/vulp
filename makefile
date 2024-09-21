CC_OPTS = -Wall -Wpedantic

CC_CMD = $(CC) $(CC_OPTS) $(CC_DBG)

preprocessed = \
	src/vctype_auto.h \
	src/vctype_auto.c

objects = \
	out/vctype_auto.o \
	out/vio.o    \
	out/vparse.o \
	out/vlex.o   \
	out/vaux.o	


.PRECIOUS: $(preprocessed)


out/vulpes: $(objects)

clean:
	$(RM) -rf out/* src/*_auto.*

test: out/vulpes
	out/vulpes test/test

src/%_auto.c: src/auto/%.m4
	m4 -D M4_CFILE src/auto/$*.m4 > $@

src/%_auto.h: src/auto/%.m4
	m4 -D M4_HFILE src/auto/$*.m4 > $@

out/%.o: src/%.c src/%.h
	$(CC_CMD) -c -o $@ src/$*.c

