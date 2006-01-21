#include "systemc.h"

#include "../../constants/constants.h"

SC_MODULE(set_stop_pc)
{
	sc_in<bool>		in_clk;
	sc_in<bool>		reset;
	
	sc_in<bool>		x_insthold;
	sc_out<bool>		insthold;
	
	sc_in<sc_lv<32> >	pc_in;
	sc_in<sc_lv<4> >	cp0_inst;
	sc_out<sc_lv<32> >	new_pc;
	sc_out<sc_logic>	load_epc;
	sc_in<bool>		check_excep;
	sc_in<sc_uint<32> >	EPC_FOR_RFE;
	
	sc_signal<int> 	currentstate , nextstate;
	
	void update_state();
	void do_set_stop_pc();
	
	SC_CTOR(set_stop_pc)
	{
		SC_METHOD(update_state);
		sensitive_pos << in_clk;
		
		SC_METHOD(do_set_stop_pc);
		sensitive << reset;
		sensitive << x_insthold;
		sensitive << check_excep;
		sensitive << currentstate;
		sensitive << cp0_inst;
		sensitive << EPC_FOR_RFE;
	}
}; 
