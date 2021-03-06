#include <iostream>
#include <vector>
#include <string>

using namespace std;
class CicloSimple{
private:
	static int PC;
	static vector<int> $; //registros
	bool ALUSrc;
	int ALUFunc;
	bool RegWrite;
	int RegDst;
	int RegInSrc;
	bool AddSub;
	int LogicFn;
	int FnClass;
	bool DataRead;
	bool DataWrite;
	int BrType;
	int PCSrc;
	int op;
	int fn;
	
public:
	CicloSimple(){
		this->ALUSrc = 0;
		this->ALUFunc = 0;
		this->RegDst = 0;
		if ($.empty()){
			for (int i = 0; i < 31; i++)
				 $.push_back(0);
		}
	}
	void lui(int reg, int imm);
	void add(int rd, int rs, int rt){
		this->op = 0;
		this->fn = 32;
		this->RegWrite = 1;
		this->RegDst = 1;
		this->RegInSrc = 1;
		this->ALUSrc = 0;
		this->AddSub = 0;
		this->FnClass = 2;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
		
	}
	void sub(int rd, int rs, int rt){
		this->op = 0;
		this->fn = 34;
		this->RegWrite = 1;
		this->RegDst = 1;
		this->RegInSrc = 1 ;
		this->ALUSrc = 0;
		this->AddSub = 1;
		this->FnClass = 2;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void slt(int rd, int rs, int rt){
		this->op = 0;
		this->fn = 50;
		this->RegWrite = 1;
		this->RegDst = 1;
		this->RegInSrc = 1;
		this->ALUSrc = 0;
		this->AddSub = 1;
		this->FnClass = 1;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void addi(int rd, int rs, int imm){
		this->op = 16;
		this->RegWrite = 1;
		this->RegDst = 0;
		this->RegInSrc =1 ;
		this->ALUSrc = 1;
		this->AddSub = 0;
		this->FnClass = 2;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void slti(int rd, int rs, int imm){
		this->op = 18;
		this->RegWrite = 1;
		this->RegDst = 0;
		this->RegInSrc = 1;
		this->ALUSrc = 1;
		this->AddSub = 1;
		this->FnClass = 1;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void AND(int rd, int rs, int rt){
		this->op = 0;
		this->fn = 36;
		this->RegWrite = 1;
		this->RegDst = 1;
		this->RegInSrc =1 ;
		this->ALUSrc = 0;
		this->LogicFn = 0;
		this->FnClass = 3;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void OR(int rd, int rs, int rt){
		this->op = 0;
		this->fn = 37;
		this->RegWrite = 1;
		this->RegDst = 1;
		this->RegInSrc = 1;
		this->ALUSrc = 0;
		this->LogicFn = 1; 
		this->FnClass = 3;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void XOR(int rd, int rs, int rt){
		this->op = 0;
		this->fn = 38;
		this->RegWrite = 1;
		this->RegDst = 1;
		this->RegInSrc = 1;
		this->ALUSrc = 0;
		this->LogicFn = 2; 
		this->FnClass = 3;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
		
	}
	void NOR(int rd, int rs, int rt){
		this->op = 0;
		this->fn = 39;
		this->RegWrite = 1;
		this->RegDst = 1;
		this->RegInSrc = 1;
		this->ALUSrc = 0;
		this->LogicFn = 3; 
		this->FnClass = 3;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void andi(int rd, int rs, int imm){
		this->op = 24;
		this->RegWrite = 1;
		this->RegDst = 0;
		this->RegInSrc = 1;
		this->ALUSrc = 1;
		this->LogicFn = 0; 
		this->FnClass = 3;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void ori(int rd, int rs, int imm){
		this->op = 26;
		this->RegWrite = 1;
		this->RegDst = 0;
		this->RegInSrc = 1;
		this->ALUSrc = 1;
		this->LogicFn = 1; 
		this->FnClass = 3;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void xori(int rd, int rs, int imm){
		this->op = 28;
		this->RegWrite = 1;
		this->RegDst = 0;
		this->RegInSrc = 1;
		this->ALUSrc = 1;
		this->LogicFn = 2; 
		this->FnClass = 3;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void lw(int rt, int imm){
		this->op = 35;
		this->RegWrite = 1;
		this->RegDst = 0;
		this->RegInSrc = 0;
		this->ALUSrc = 1;
		this->AddSub = 0;
		this->FnClass = 2;
		this->DataRead = 1;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void sw(int rt, int imm){
		this->op = 51;
		this->RegWrite = 0;
		this->ALUSrc = 1;
		this->AddSub = 0;
		this->FnClass = 2;
		this->DataRead = 0;
		this->DataWrite = 1;
		this->BrType = 0;
		this->PCSrc = 0;
	}
	void j(string L){
		this->op = 2;
		this->RegWrite = 0;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->PCSrc = 1;
	}
	void jr(int rs){
		this->op = 0;
		this->fn = 16;
		this->RegWrite = 0;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->PCSrc = 2;
	}
	void bltz(int rs, string L){
		this->op = 1;
		this->RegWrite = 0;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 3;
		this->PCSrc = 0;
	}
	void beq(int rs, int rt, string){
		this->op = 4;
		this->RegWrite = 0;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 1;
		this->PCSrc = 0;
	}
	void bne(int rs, int rt, string){
		this->op = 6;
		this->RegWrite = 0;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 2;
		this->PCSrc = 0;
	}
	void jal(string L){
		this->op = 6;
		this->RegWrite = 0;
		this->RegDst = 2;
		this->RegInSrc = 2;
		this->DataRead = 0;
		this->DataWrite = 0;
		this->BrType = 0;
		this->PCSrc = 3;
	}
};

int CicloSimple::PC = 0;

int main(int argc, char *argv[]) {
	
	return 0;
}
