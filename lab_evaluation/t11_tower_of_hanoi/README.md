# Tower of Hanoi

## Algorithm 

T(N, Beg, Aux, End)
Begin
	if N:=1
		print Beg -> End
		return

	call T(N-1,Beg,Aux,End)
	print N, Beg, End
	call T(N-1,Aux,End,Beg) 