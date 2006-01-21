#include "mux_instaddr.h"

void mux_instaddr::do_mux_instaddr()
{
	if(m_wb_interrupt_signal.read() == true)
	{
	   if((ex_m_instaddr.read() - m_wb_instaddr.read()) == 4)
	      m_wb_instaddr_s.write(m_wb_instaddr.read());
	   else
	      m_wb_instaddr_s.write(ex_m_instaddr.read());
	}
	else
	   m_wb_instaddr_s.write(m_wb_instaddr.read());
}
