run: Main.exe
	mono ./Main.exe ${run}

Main.exe: Main.cs
	mcs ./Main.cs -out:./Main.exe

clean:
	-rm Main.exe
