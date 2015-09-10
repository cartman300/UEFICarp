public _disable
public _enable
public _crash

.CODE

_disable:
	cli
	ret

_enable:
	sti
	ret

_crash:
	int 42
	ret

END