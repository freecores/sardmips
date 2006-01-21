#include "systemc.h"
#include "../../constants/constants.h"

SC_MODULE(multiply)
{
	sc_in<sc_lv<32> >	id_ex_alu1;
	sc_in<sc_lv<32> >	id_ex_alu2;
	
	sc_in<sc_lv<6> >	id_ex_alu_ctrl;
	
	sc_out<sc_lv<32> >	hi;
	sc_out<sc_lv<32> >	lo;
	
	
	void do_multiply();
	
	SC_CTOR(multiply)
	{
		SC_METHOD(do_multiply);
		sensitive << id_ex_alu1 << id_ex_alu2;
		sensitive << id_ex_alu_ctrl;
	};
};
