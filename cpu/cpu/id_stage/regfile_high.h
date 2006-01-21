//
// $Id: regfile_high.h,v 1.1 2006-01-21 03:37:36 igorloi Exp $
//

#ifndef _REGFILE_H
#define _REGFILE_H

#include <systemc.h>
#include "../../constants/config.h"
#include "../../constants/constants.h"

SC_MODULE(regfile)
{
  // default input
  sc_in<bool> in_clk;
  sc_in<bool> reset;
  sc_in<sc_lv<5> > rs;
  sc_in<sc_lv<5> > rt;
  sc_in<sc_logic> wr;
  sc_in<sc_lv<32> > rd_in;
  sc_in<sc_lv<5> > rd;
  sc_out<sc_lv<32> > rs_out;
  sc_out<sc_lv<32> > rt_out;

  sc_signal<sc_lv<32> > r[32];

  void storeregister();
  void loadregister();

  SC_CTOR(regfile)
    {
      SC_METHOD(storeregister);
      sensitive_neg << in_clk;
      
      SC_METHOD(loadregister);
      sensitive << rs << rt << in_clk;
    }
};

#endif




