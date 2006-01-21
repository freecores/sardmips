//
// $Id: ex_stage.h,v 1.1 2006-01-21 03:37:34 igorloi Exp $
//
#ifndef _EX_STAGE_H
#define _EX_STAGE_H

#include <systemc.h>
#include "reg_ex.h"
#include "alu.h"
#include "backwrite.h"
#include "multiply.h"
#include "mux_lo.h"
#include "mux_hi.h"
#include "mux_rd.h"


/*#include "./ex_stage/reg_ex.h"
#include "./ex_stage/alu.h"
#include "./ex_stage/backwrite.h"
#include "./ex_stage/multiply.h"
#include "./ex_stage/mux_lo.h"
#include "./ex_stage/mux_hi.h"
#include "./ex_stage/mux_rd.h"
*/
SC_MODULE(ex_stage) 
{
	sc_in<bool> in_clk;
	sc_in<bool> reset;
	
	sc_in<bool> insthold;
	sc_in<bool> datahold;
	
	// signals from id_stage
	sc_in<sc_lv<32> > id_ex_alu1;
	sc_in<sc_lv<32> > id_ex_alu2;
	sc_in<sc_lv<32> > id_ex_datastore;
	sc_in<sc_lv<6> >  id_ex_alu_ctrl;
	sc_in<sc_logic>   id_ex_equal;
	sc_in<sc_lv<2> >  id_ex_byteselect;
	sc_in<sc_logic>   id_ex_bssign;
	sc_in<sc_lv<5> >  id_ex_alu_sa;
	
	// signals to be sent on to mem_stage
	sc_in<sc_logic> id_ex_datareq;
	sc_in<sc_logic> id_ex_datarw;
	sc_in<sc_logic> id_ex_memtoreg;
	
	// signal to control save in register
	sc_in<sc_lv<5> > id_ex_writeregister_out;
	sc_in<sc_logic> id_ex_regwrite_out;
	
	sc_out<sc_lv<5> > id_ex_m_writeregister;
	sc_out<sc_logic> id_ex_m_regwrite;
	
	sc_out<sc_logic> id_ex_m_datareq;
	sc_out<sc_logic> id_ex_m_datarw;
	sc_out<sc_lv<32> > id_ex_m_datastore;
	sc_out<sc_lv<32> > ex_m_alu;
	
	sc_out<sc_logic> id_ex_m_memtoreg;
	
	sc_out<sc_lv<32> > ex_id_forward;
	
	// Signals directly to mem stage
	sc_out<sc_lv<2> > id_ex_m_byteselect;
	sc_out<sc_logic>  id_ex_m_bssign;
	
	// Signals to cp0
	sc_out<sc_logic> ovf_excep;
	
	// Signals from cp0
	// To prevent memory access in case of Address Error Exception or OCP action
	sc_in<sc_logic> addr_err;
	
	// sc_in<sc_lv<32> > cp0_data_from;
	
	sc_signal<sc_lv<32> > ex_alu_s;
	sc_signal<sc_lv<32> > ex_id_forward_s;
	sc_signal<sc_lv<32> > in_ex_alu_s;
	sc_signal<sc_lv<32> > in_ex_id_forward_s;
	
	// special registers
	sc_signal<sc_lv<32> > hi;
	sc_signal<sc_lv<32> > lo;
	sc_signal<sc_lv<32> > in_lo;
	sc_signal<sc_lv<32> > in_hi;
	sc_signal<sc_lv<32> > out_lo;
	sc_signal<sc_lv<32> > out_hi;
	
	
	
	sc_signal<sc_logic> carry;
	
	reg_ex *reg_ex1;
	alu *alu1;
	backwrite *backwrite1;
	multiply *multiply1;
	mux_lo *mux_lo1;
	mux_hi *mux_hi1;
	mux_rd *mux_rd1;
	
	SC_CTOR(ex_stage)
	{
		reg_ex1 = new reg_ex("reg_ex");
		reg_ex1->in_clk(in_clk);
		reg_ex1->reset(reset);
		reg_ex1->insthold(insthold);
		reg_ex1->datahold(datahold);
		reg_ex1->addr_err(addr_err);
		reg_ex1->ex_alu_s(ex_alu_s);
		reg_ex1->ex_m_alu(ex_m_alu);
		reg_ex1->id_ex_datastore(id_ex_datastore);
		reg_ex1->id_ex_m_datastore(id_ex_m_datastore);
		reg_ex1->id_ex_datareq(id_ex_datareq);
		reg_ex1->id_ex_m_datareq(id_ex_m_datareq);
		reg_ex1->id_ex_datarw(id_ex_datarw);
		reg_ex1->id_ex_m_datarw(id_ex_m_datarw);
		reg_ex1->id_ex_memtoreg(id_ex_memtoreg);
		reg_ex1->id_ex_m_memtoreg(id_ex_m_memtoreg);
		reg_ex1->id_ex_writeregister_out(id_ex_writeregister_out);
		reg_ex1->id_ex_m_writeregister(id_ex_m_writeregister);
		reg_ex1->id_ex_regwrite_out(id_ex_regwrite_out);
		reg_ex1->id_ex_m_regwrite(id_ex_m_regwrite);
		reg_ex1->id_ex_byteselect(id_ex_byteselect);
		reg_ex1->id_ex_m_byteselect(id_ex_m_byteselect);
		reg_ex1->id_ex_bssign(id_ex_bssign);
		reg_ex1->id_ex_m_bssign(id_ex_m_bssign);
		reg_ex1->in_lo(in_lo);
		reg_ex1->out_lo(out_lo);
		reg_ex1->in_hi(in_hi);
		reg_ex1->out_hi(out_hi);

		
		alu1 = new alu("alu");
		alu1->id_ex_alu1(id_ex_alu1);
		alu1->id_ex_alu2(id_ex_alu2);
		alu1->id_ex_alu_ctrl(id_ex_alu_ctrl);
		alu1->id_ex_equal(id_ex_equal);
		alu1->id_ex_alu_sa(id_ex_alu_sa);
		alu1->ovf_excep(ovf_excep);
		alu1->carry(carry);
		alu1->ex_alu_s(in_ex_alu_s);
		alu1->ex_id_forward_s(in_ex_id_forward_s);
		
		backwrite1 = new backwrite("backwrite");
		backwrite1->ex_id_forward_s(ex_id_forward_s);
		backwrite1->ex_id_forward(ex_id_forward);
		
		multiply1 = new multiply("multiply");
		multiply1->id_ex_alu1(id_ex_alu1);
		multiply1->id_ex_alu2(id_ex_alu2);
		multiply1->id_ex_alu_ctrl(id_ex_alu_ctrl);
		multiply1->hi(hi);
		multiply1->lo(lo);
		
		mux_lo1 = new mux_lo("mux_lo");
		mux_lo1->lo(lo);
		mux_lo1->rs(id_ex_alu1);
		mux_lo1->id_ex_alu_ctrl(id_ex_alu_ctrl);
		mux_lo1->out(in_lo);
		
		mux_hi1 = new mux_hi("mux_hi");
		mux_hi1->hi(hi);
		mux_hi1->rs(id_ex_alu1);
		mux_hi1->id_ex_alu_ctrl(id_ex_alu_ctrl);
		mux_hi1->out(in_hi);
		
		mux_rd1 = new mux_rd("mux_rd");
		mux_rd1->in_ex_id_forward_s(in_ex_id_forward_s);	//dalla ALU
		mux_rd1->in_ex_alu_s(in_ex_alu_s);      		// dalla ALU
		mux_rd1->out_lo(out_lo);            			// dai registri LO
		mux_rd1->out_hi(out_hi);            			// dai registri HI 
		mux_rd1->id_ex_alu_ctrl(id_ex_alu_ctrl);     		// selettore del MUX
		mux_rd1->out_ex_id_forward_s(ex_id_forward_s);	// USCITE verso i registri di pipeline
		mux_rd1->out_ex_alu_s(ex_alu_s);  
	}
};

#endif

