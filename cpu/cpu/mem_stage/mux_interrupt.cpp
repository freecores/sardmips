#include "mux_interrupt.h"

void mux_interrupt::do_mux_interrupt()
{
	if(SEL.read() == SC_LOGIC_1)
	   OUT.write(IN_A.read());
	else
	   if(SEL.read() == SC_LOGIC_0)
	      OUT.write(IN_B.read());
	   else
	      OUT.write(IN_A.read());
}
