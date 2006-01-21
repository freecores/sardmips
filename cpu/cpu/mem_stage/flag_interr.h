#include "systemc.h"

SC_MODULE(flag_interr)
{
	sc_in<bool>	in_clk, reset;
	sc_in<bool>	interrupt_in;
	sc_out<bool>	interrupt_out;
	
	void do_flag_interr();
	
	SC_CTOR(flag_interr)
	{
		SC_METHOD(do_flag_interr);
		sensitive << in_clk << interrupt_in;
	}
};
