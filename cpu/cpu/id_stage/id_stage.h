#include "systemc.h"
#include "./id_stage/control.h"
#include "./id_stage/mux_writeregister.h"
#include "./id_stage/sign_extend.h"
#include "./id_stage/add_new_pc.h"
#include "./id_stage/mux_jump.h"
#include "./id_stage/mux_forward_select.h"
#include "./id_stage/mux_alu1.h"
#include "./id_stage/mux_alu2.h"
#include "./id_stage/comparator.h"
#include "./id_stage/forwarding_control.h"
#include "./id_stage/reg.h"

#include "./id_stage/regfile_high.h"

#include "../constants/config.h"
#include "../constants/constants.h"

SC_MODULE(id_stage)
{
	sc_in<bool> in_clk;
	sc_in<bool> reset;

	sc_in<bool> insthold;
	sc_in<bool> datahold;

	sc_in<sc_lv<32> > if_id_next_pc;
	sc_in<sc_lv<32> > if_id_inst;
 
	// signal to if_stage NOT clk
	sc_out<sc_lv<32> > id_jmp_tar;
	sc_out<sc_lv<32> > id_new_pc;
	sc_out<sc_logic> id_branch;
	sc_out<sc_logic> id_ctrl;

	// signal to ex_stage
	sc_out<sc_lv<32> > id_ex_alu1;
	sc_out<sc_lv<32> > id_ex_alu2;
	sc_out<sc_lv<32> > id_ex_datastore;
	sc_out<sc_lv<6> >  id_ex_alu_ctrl;
	sc_out<sc_logic>   id_ex_equal;
	sc_out<sc_lv<2> >  id_ex_byteselect;
	sc_out<sc_logic>   id_ex_bssign;
	sc_out<sc_lv<5> >  id_ex_alu_sa;
  
	// signal to mem_stage throught ex_stage
	sc_out<sc_logic> id_ex_datareq;
	sc_out<sc_logic> id_ex_datarw;
	sc_out<sc_logic> id_ex_memtoreg;

	sc_signal<sc_lv<2> > id_byteselect;
	sc_signal<sc_logic>  id_bssign;
	sc_signal<sc_lv<5> > id_alu_sa;

	// signal to control save in register
	sc_out<sc_lv<5> > id_ex_writeregister_out;
	sc_out<sc_logic>  id_ex_regwrite_out;

	// forwarding control signal
	sc_signal<sc_lv<5> > id_ex_writeregister;
	sc_in<sc_lv<5> >     id_ex_m_writeregister;
	sc_in<sc_lv<5> >     id_ex_m_wb_writeregister;
	sc_signal<sc_logic>  id_ex_regwrite;
	sc_in<sc_logic>      id_ex_m_regwrite;
	sc_in<sc_logic>      id_ex_m_wb_regwrite;
	sc_in<sc_lv<32> >    ex_id_forward;
	sc_in<sc_lv<32> >    m_id_forward;
	sc_in<sc_lv<32> >    wb_id_forward;
	
	// signals to cp0
	sc_out<sc_lv<4> >   cp0_inst;     // Current instruction
	sc_out<sc_uint<5> > cp0_reg_no;   // Register to read/write in cp0
	sc_out<sc_logic>    cp0_reg_rw;   // Read/Write signal, 1 for write
	sc_out<sc_lv<32> >  cp0_reg_rs;   // Contents of register rd in instruction for mtc0
	sc_in<sc_lv<32> >   cp0_reg_out;  // For reading out from cp0 - for mfc0

	// signals used in control
	sc_signal<sc_lv<5> > rt, rs, rd, sa;
	
	/*   sc_lv<5> lrs, lrt, lrd, lsa;        // lv version of reg # */
	/*   sc_uint<5> uirs, uirt, uird, uisa;  // unsigned integer version of reg # */
	/*   sc_int<32> is, it, id;              // integer version of register contents... */
	
	// sign/zero extend and lui control
	sc_signal<sc_lv<32> > id_sign_extend;
	sc_signal<sc_lv<2> >  id_extend_ctrl;
	
	sc_signal<sc_lv<32> > id_mux_fw1;
	sc_signal<sc_lv<32> > id_mux_fw2;
	
	sc_signal<sc_lv<32> > id_reg1;
	sc_signal<sc_lv<32> > id_reg2;
	
	sc_signal<sc_lv<32> > id_alu1;
	sc_signal<sc_lv<32> > id_alu2;
	
	sc_signal<sc_logic> id_equal;

	// signal from control unit
	sc_signal<sc_lv<5> > id_writeregister;
	sc_signal<sc_logic>  id_regwrite;
	sc_signal<sc_lv<2> > regdest;
	sc_signal<sc_logic>  id_select_jump;
	sc_signal<sc_logic>  id_pc_store;
	sc_signal<sc_lv<2> > id_sign_ctrl;
	sc_signal<sc_lv<3> > id_branch_select;
	sc_signal<sc_lv<6> > id_alu_ctrl;
	sc_signal<sc_logic>  id_datareq;
	sc_signal<sc_logic>  id_datarw;
	sc_signal<sc_logic>  id_memtoreg;
	sc_signal<sc_logic>  id_shamt_ctrl;
	sc_signal<sc_logic>  id_mfc0;
	
	// forwarding ctrl unit
	sc_signal<sc_lv<2> > id_fw_ctrl1;
	sc_signal<sc_lv<2> > id_fw_ctrl2;

#ifdef ONEHOT_DEBUG
	sc_signal<sc_logic> inst_addiu;
	sc_signal<sc_logic> inst_jalr;
	sc_signal<sc_logic> inst_lw;
	sc_signal<sc_logic> inst_mfc0;
	sc_signal<sc_logic> inst_mtc0;
	sc_signal<sc_logic> inst_nop;
	sc_signal<sc_logic> inst_sw;
	sc_signal<sc_logic> inst_wait;
#endif
	
	
	control *control1;
	mux_writeregister *mux_writeregister1;
	sign_extend *sign_extend1;
	add_new_pc *add_new_pc1;
	mux_jump *mux_jump1;
	mux_forward_select *mux_forward_select1;
	mux_forward_select *mux_forward_select2;
	mux_alu1 *mux_alu_1;
	mux_alu2 *mux_alu_2;
	comparator *comparator1;
	forwarding_control *forwarding_control1;
	forwarding_control *forwarding_control2;
	reg *reg1;
	regfile *localreg;
	
	
	SC_CTOR(id_stage)
	{
		control1 = new control("control");
		control1->if_id_inst(if_id_inst);
		control1->rs(rs);
		control1->rt(rt);
		control1->rd(rd);
		control1->id_alu_ctrl(id_alu_ctrl);
		control1->id_alu_sa(id_alu_sa);
		control1->id_ctrl(id_ctrl);
		control1->id_extend_ctrl(id_extend_ctrl);
		control1->id_sign_ctrl(id_sign_ctrl);
		control1->regdest(regdest);
		control1->id_select_jump(id_select_jump);
		control1->id_pc_store(id_pc_store);
		control1->id_branch_select(id_branch_select);
		control1->id_regwrite(id_regwrite);
		control1->id_shamt_ctrl(id_shamt_ctrl);
		control1->id_datarw(id_datarw);
		control1->id_datareq(id_datareq);
		control1->id_memtoreg(id_memtoreg);
		control1->id_byteselect(id_byteselect);
		control1->cp0_inst(cp0_inst);
		control1->cp0_reg_no(cp0_reg_no);
		control1->cp0_reg_rw(cp0_reg_rw);
		control1->id_mfc0(id_mfc0);
	#ifdef ONEHOT_DEBUG
		control1->inst_addiu(inst_addiu);
		control1->inst_jalr(inst_jalr);
		control1->inst_lw(inst_lw);
		control1->inst_mfc0(inst_mfc0);
		control1->inst_mtc0(inst_mtc0);
		control1->inst_nop(inst_nop);
		control1->inst_sw(inst_sw);
		control1->inst_wait(inst_wait);
	#endif
	
		mux_writeregister1 =  new mux_writeregister("mux_writeregister");
		mux_writeregister1->regdest(regdest);
		mux_writeregister1->rt(rt);
		mux_writeregister1->rd(rd);
		mux_writeregister1->id_writeregister(id_writeregister);
		
		sign_extend1 = new sign_extend("sign_extend");
		sign_extend1->if_id_inst(if_id_inst);
		sign_extend1->id_extend_ctrl(id_extend_ctrl);
		sign_extend1->id_sign_extend(id_sign_extend);
		
		add_new_pc1 = new add_new_pc("add_new_pc");
		add_new_pc1->if_id_next_pc(if_id_next_pc);
		add_new_pc1->id_sign_extend(id_sign_extend);
		add_new_pc1->id_new_pc(id_new_pc);
		
		mux_jump1 = new mux_jump("mux_jump");
		mux_jump1->if_id_next_pc(if_id_next_pc);
		mux_jump1->if_id_inst(if_id_inst);
		mux_jump1->id_select_jump(id_select_jump);
		mux_jump1->id_mux_fw1(id_mux_fw1);
		mux_jump1->id_jmp_tar(id_jmp_tar);
		
		mux_forward_select1 = new mux_forward_select("mux_forward_select1");
		mux_forward_select1->id_reg(id_reg1);
		mux_forward_select1->ex_id_forward(ex_id_forward);
		mux_forward_select1->m_id_forward(m_id_forward);
		mux_forward_select1->wb_id_forward(wb_id_forward);
		mux_forward_select1->id_fw_ctrl(id_fw_ctrl1);
		mux_forward_select1->id_mux_fw(id_mux_fw1);
		
		mux_forward_select2 = new mux_forward_select("mux_forward_select2");
		mux_forward_select2->id_reg(id_reg2);
		mux_forward_select2->ex_id_forward(ex_id_forward);
		mux_forward_select2->m_id_forward(m_id_forward);
		mux_forward_select2->wb_id_forward(wb_id_forward);
		mux_forward_select2->id_fw_ctrl(id_fw_ctrl2);
		mux_forward_select2->id_mux_fw(id_mux_fw2);
		
		mux_alu_1 = new mux_alu1("mux_alu1");
		mux_alu_1->if_id_inst(if_id_inst);
		mux_alu_1->id_shamt_ctrl(id_shamt_ctrl);
		mux_alu_1->id_pc_store(id_pc_store);
		mux_alu_1->id_alu1(id_alu1);
		mux_alu_1->if_id_next_pc(if_id_next_pc);
		mux_alu_1->cp0_reg_out(cp0_reg_out);
		mux_alu_1->id_mux_fw1(id_mux_fw1);
		mux_alu_1->id_mfc0(id_mfc0);
		
		mux_alu_2 = new mux_alu2("mux_alu2");
		mux_alu_2->id_sign_extend(id_sign_extend);
		mux_alu_2->id_sign_ctrl(id_sign_ctrl);
		mux_alu_2->id_alu2(id_alu2);
		mux_alu_2->cp0_reg_rs(cp0_reg_rs);
		mux_alu_2->id_mux_fw2(id_mux_fw2);
		
		comparator1 = new comparator("comparator");
		comparator1->id_mux_fw1(id_mux_fw1);
		comparator1->id_mux_fw2(id_mux_fw2);
		comparator1->id_branch_select(id_branch_select);
		comparator1->id_equal(id_equal);
		comparator1->id_branch(id_branch);
		
		forwarding_control1 = new forwarding_control("forwarding_control1");
		forwarding_control1->id_ex_writeregister(id_ex_writeregister);
		forwarding_control1->id_ex_m_writeregister(id_ex_m_writeregister);
		forwarding_control1->id_ex_m_wb_writeregister(id_ex_m_wb_writeregister);
		forwarding_control1->id_ex_regwrite(id_ex_regwrite);
		forwarding_control1->id_ex_m_regwrite(id_ex_m_regwrite);
		forwarding_control1->id_ex_m_wb_regwrite(id_ex_m_wb_regwrite);
		forwarding_control1->rs(rs);
		forwarding_control1->id_fw_ctrl(id_fw_ctrl1);
		
		forwarding_control2 = new forwarding_control("forwarding_control2");
		forwarding_control2->id_ex_writeregister(id_ex_writeregister);
		forwarding_control2->id_ex_m_writeregister(id_ex_m_writeregister);
		forwarding_control2->id_ex_m_wb_writeregister(id_ex_m_wb_writeregister);
		forwarding_control2->id_ex_regwrite(id_ex_regwrite);
		forwarding_control2->id_ex_m_regwrite(id_ex_m_regwrite);
		forwarding_control2->id_ex_m_wb_regwrite(id_ex_m_wb_regwrite);
		forwarding_control2->rs(rt);
		forwarding_control2->id_fw_ctrl(id_fw_ctrl2);
		
		reg1 = new reg("reg");
		reg1->in_clk(in_clk);
		reg1->reset(reset);
		reg1->datahold(datahold);
		reg1->insthold(insthold);
		reg1->id_ex_alu1(id_ex_alu1);
		reg1->id_alu1(id_alu1);
		reg1->id_ex_alu2(id_ex_alu2);
		reg1->id_alu2(id_alu2);
		reg1->id_ex_datastore(id_ex_datastore);
		reg1->id_mux_fw2(id_mux_fw2);
		reg1->id_ex_alu_ctrl(id_ex_alu_ctrl);
		reg1->id_alu_ctrl(id_alu_ctrl);
		reg1->id_ex_alu_sa(id_ex_alu_sa);
		reg1->id_alu_sa(id_alu_sa);
		reg1->id_ex_equal(id_ex_equal);
		reg1->id_equal(id_equal);
		reg1->id_ex_datareq(id_ex_datareq);
		reg1->id_datareq(id_datareq);
		reg1->id_ex_datarw(id_ex_datarw);
		reg1->id_datarw(id_datarw);
		reg1->id_ex_memtoreg(id_ex_memtoreg);
		reg1->id_memtoreg(id_memtoreg);
		reg1->id_ex_writeregister_out(id_ex_writeregister_out);
		reg1->id_writeregister(id_writeregister);
		reg1->id_ex_writeregister(id_ex_writeregister);
		reg1->id_ex_regwrite_out(id_ex_regwrite_out);
		reg1->id_regwrite(id_regwrite);
		reg1->id_ex_regwrite(id_ex_regwrite);
		reg1->id_ex_byteselect(id_ex_byteselect);
		reg1->id_byteselect(id_byteselect);
		reg1->id_ex_bssign(id_ex_bssign);
		reg1->id_bssign(id_bssign);
		
		localreg = new regfile("regfiles");
		localreg->in_clk(in_clk);
		localreg->reset(reset);
		localreg->rs(rs);
		localreg->rt(rt);
		localreg->wr(id_ex_m_wb_regwrite);
		localreg->rd_in(wb_id_forward);
		localreg->rd(id_ex_m_wb_writeregister);
		localreg->rs_out(id_reg1);
		localreg->rt_out(id_reg2);
	}
};
