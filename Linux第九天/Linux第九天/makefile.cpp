myprocess:myprocess.c task.c
gcc - o $@ $ ^
.PHONT:clean
clean:
	rm -f myprocess