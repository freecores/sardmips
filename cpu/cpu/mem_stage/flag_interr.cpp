#include "flag_interr.h"

void flag_interr::do_flag_interr()
{
	if(reset.read() == true)
	   interrupt_out.write(false);
	else
	   if(interrupt_in.read() == true)
	      interrupt_out.write(true);
	   else
	      if((in_clk.read() == true)  && (interrupt_in.read() == false))
	         interrupt_out.write(false);
	      else;

} 
