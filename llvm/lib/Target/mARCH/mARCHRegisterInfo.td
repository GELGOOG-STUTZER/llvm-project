//===-- mARCHRegisterInfo.td - mARCH Register defs -----------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the mARCH register file
//===----------------------------------------------------------------------===//

// For tablegen(... -gen-emitter)  in CMakeLists.txt
class mARCHReg<bits<16> Enc, string n> : Register<n> {
  let HWEncoding = Enc;
}

// mARCH CPU Registers
class mARCHGPRReg<bits<16> Enc, string n> : mARCHReg<Enc, n>;

//===----------------------------------------------------------------------===//
//@Registers
//===----------------------------------------------------------------------===//
//@ All registers definition
let Namespace = "mARCH" in {
  //@ General Purpose Registers
  def R0    : mARCHGPRReg<0,  "r0">,    DwarfRegNum<[0]>;
  def R1    : mARCHGPRReg<1,  "r1">,    DwarfRegNum<[1]>;
  def R2    : mARCHGPRReg<2,  "r2">,    DwarfRegNum<[2]>;
  def R3    : mARCHGPRReg<3,  "r3">,    DwarfRegNum<[3]>;
  def R4    : mARCHGPRReg<4,  "r4">,    DwarfRegNum<[4]>;
  def R5    : mARCHGPRReg<5,  "r5">,    DwarfRegNum<[5]>;
  def R6    : mARCHGPRReg<6,  "r6">,    DwarfRegNum<[6]>;
  def R7    : mARCHGPRReg<7,  "r7">,    DwarfRegNum<[7]>;
  def R8    : mARCHGPRReg<8,  "r8">,    DwarfRegNum<[8]>;
  def R9    : mARCHGPRReg<9,  "r9">,    DwarfRegNum<[9]>;
  def R10   : mARCHGPRReg<10, "r10">,   DwarfRegNum<[10]>;
  def R11   : mARCHGPRReg<11, "r11">,   DwarfRegNum<[11]>;
  def R12   : mARCHGPRReg<12, "r12">,   DwarfRegNum<[12]>;
  def R13   : mARCHGPRReg<13, "r13">,   DwarfRegNum<[13]>;
  def R14   : mARCHGPRReg<14, "r14">,   DwarfRegNum<[14]>;
  def R15   : mARCHGPRReg<15, "r15">,   DwarfRegNum<[15]>;
  def R16    : mARCHGPRReg<16,  "r16">,    DwarfRegNum<[16]>;
  def R17    : mARCHGPRReg<17,  "r17">,    DwarfRegNum<[17]>;
  def R18    : mARCHGPRReg<18,  "r18">,    DwarfRegNum<[18]>;
  def R19    : mARCHGPRReg<19,  "r19">,    DwarfRegNum<[19]>;
  def R20    : mARCHGPRReg<20,  "r20">,    DwarfRegNum<[20]>;
  def R21    : mARCHGPRReg<21,  "r21">,    DwarfRegNum<[21]>;
  def R22    : mARCHGPRReg<22,  "r22">,    DwarfRegNum<[22]>;
  def R23    : mARCHGPRReg<23,  "r23">,    DwarfRegNum<[23]>;
  def R24    : mARCHGPRReg<24,  "r24">,    DwarfRegNum<[24]>;
  def R25    : mARCHGPRReg<25,  "r25">,    DwarfRegNum<[25]>;
  def R26    : mARCHGPRReg<26,  "r26">,    DwarfRegNum<[26]>;
  def R27    : mARCHGPRReg<27,  "r27">,    DwarfRegNum<[27]>;
  def R28    : mARCHGPRReg<28,  "r28">,    DwarfRegNum<[28]>;
  def R29    : mARCHGPRReg<29,  "r29">,    DwarfRegNum<[29]>;
  def R30    : mARCHGPRReg<30,  "r30">,    DwarfRegNum<[30]>;
  def R31    : mARCHGPRReg<31,  "r31">,    DwarfRegNum<[31]>;
}

//===----------------------------------------------------------------------===//
//@Register Classes
//===----------------------------------------------------------------------===//

def CPURegs : RegisterClass<"mARCH", [i32], 32, (add
  R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31)>;