#include "set_stop_pc.h"

void set_stop_pc::update_state()
{
    if (reset.read() == true)
    {
        currentstate = 0;
    }
    else
       currentstate = nextstate;
}

void set_stop_pc::do_set_stop_pc()
{

      //insthold = x_insthold.read();
      // FSM
      switch(currentstate)
	{
	case 0:
	{
	   
	   if( check_excep.read() == SC_LOGIC_1 )
	   {
	   	cout << " ECCEZIONE " << endl;
		
	   	//sc_stop();
		nextstate = 1 ;
		new_pc.write(WORD_ZERO);
		load_epc.write(SC_LOGIC_0);
		insthold.write(true);
	   }
	   else
	   	if(cp0_inst.read() == CP0_ERET)
		{
		cout <<" CPO ERET" << endl;
		   nextstate = 3;
		   new_pc.write(WORD_ZERO);
		   load_epc.write(SC_LOGIC_0);
		   insthold.write(true);
		}
		else
	          {
		     nextstate = 0;
		     new_pc.write(WORD_ZERO);
        	     load_epc.write(SC_LOGIC_0);
		     insthold = x_insthold.read();
		  }
	}
	break;
	
	case 1:
	{   
	   insthold.write(false);
	   new_pc.write(0x00000008);
	   load_epc.write(SC_LOGIC_1);
	   nextstate = 2; 
	}
	break;
	
	case 2:
	{
	   nextstate = 0;
	   insthold.write(x_insthold.read());
	   new_pc.write(0x00000008);
	   load_epc.write(SC_LOGIC_1);
	}
	break;
	
	case 3:
	{
	   insthold.write(false);
	   new_pc.write(EPC_FOR_RFE.read());
	   load_epc.write(SC_LOGIC_1);
	   nextstate = 0;
	}
	break;
	
	case 4:
	{
	   nextstate = 0;
	   insthold.write(x_insthold.read());
	   new_pc.write(EPC_FOR_RFE.read());
	   load_epc.write(SC_LOGIC_1);
	}
	break;
	  
	default: nextstate = 0;
	break;
	}
} 
