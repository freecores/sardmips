//! IF Stage module
//
// $Id: if_stage.h,v 1.1 2006-01-21 03:37:38 igorloi Exp $
//
#ifndef _IF_STAGE_H
#define _IF_STAGE_H

#include <systemc.h>
#include "./if_stage/add.h"
#include "./if_stage/reg_if.h"
#include "./if_stage/select_next_pc.h"

SC_MODULE(if_stage) 
{
	sc_in<bool> in_clk;
	sc_in<bool> reset;
	
	sc_in<bool> insthold;
	sc_in<bool> datahold;
	
	sc_in<sc_lv<32> > pc_out;
	sc_in<sc_lv<32> > id_new_pc;
	sc_in<sc_lv<32> > id_jmp_tar;
	sc_in<sc_logic> id_ctrl;
	sc_in<sc_logic> id_branch;
	
	sc_out<sc_lv<32> > pc_in;
	
	sc_in<sc_lv<32> > instdataread;
	sc_out<sc_lv<32> > if_id_inst;
	sc_out<sc_lv<32> > if_id_next_pc;
	
	// cp0 connections
	sc_in<sc_lv<32> > new_pc;
	sc_in<sc_logic> load_epc;
	
	// Signals
	sc_signal<sc_lv<32> > if_pc_add;
	
	reg_if *reg_if1;
	add *add1;
	select_next_pc *select_next_pc1;

	//! Constructor
	/*!
	No description
	*/
	SC_CTOR(if_stage)
	{
		reg_if1 = new reg_if("reg_if");
		reg_if1->in_clk(in_clk);
		reg_if1->reset(reset);
		reg_if1->insthold(insthold);
		reg_if1->datahold(datahold);
		reg_if1->instdataread(instdataread);
		reg_if1->if_pc_add(if_pc_add);
		reg_if1->if_id_inst(if_id_inst);
		reg_if1->if_id_next_pc(if_id_next_pc);
		
		add1 = new add("add");
		add1->if_pc_add(if_pc_add);
		add1->pc_out(pc_out);
		
		select_next_pc1 = new select_next_pc("select_next_pc");
		select_next_pc1->new_pc(new_pc);
		select_next_pc1->load_epc(load_epc);
		select_next_pc1->id_ctrl(id_ctrl);
		select_next_pc1->id_branch(id_branch);
		select_next_pc1->if_pc_add(if_pc_add);
		select_next_pc1->id_new_pc(id_new_pc);
		select_next_pc1->id_jmp_tar(id_jmp_tar);
		select_next_pc1->pc_in(pc_in);
	}
};

#endif
