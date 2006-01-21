#include "multiply.h"

void multiply::do_multiply()
{ 
  
  sc_lv<32> 	rs = id_ex_alu1.read();
  sc_lv<32> 	rt = id_ex_alu2.read();  
  sc_lv<6> 	func = id_ex_alu_ctrl.read();
  
  if(func == FUNC_MULT)
  {
     sc_lv<64> l64s, l64t, l64r;
     sc_int<64> i64s, i64t, i64r;
     i64s = l64s = (WORD_ZERO,rs);
     i64t = l64t = (WORD_ZERO,rt);
     l64r = i64r = i64s * i64t;
     hi.write(l64r.range(63,32));
     lo.write(l64r.range(31,0));
  }
  else 
     if(func == FUNC_MULTU)
     { 
         sc_lv<64> l64s, l64t, l64r;
         sc_uint<64> i64s, i64t, i64r;
         i64s = l64s = (WORD_ZERO,rs);
         i64t = l64t = (WORD_ZERO,rt);
         l64r = i64r = i64s * i64t;
         hi.write(l64r.range(63,32));
         lo.write(l64r.range(31,0));
     }   
     else;
}
