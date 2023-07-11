#include <memory>
#include <verilated.h>
#include <time.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"

void init() {
  srand(time(NULL));
}

int main(int argc, char **argv) {
  Verilated::traceEverOn(true);
  Verilated::commandArgs(argc, argv);

  // get dump.vcd
  VerilatedVcdC* tfp = new VerilatedVcdC();

  const std::unique_ptr<Vtop> top{new Vtop{"TOP"}};
  top->trace(tfp, 99);
  tfp->open("dump.vcd");
 
  // initalize simulation inputs
  top->a = 0;
  top->b = 0;

  while (!Verilated::gotFinish() && Verilated::time() < 1000) {
    top->a = rand() % 2;
    top->b = rand() % 2;
    
    Verilated::timeInc(1);

    if (top->ref_c != top->dut_c) {
      printf("ERROR: a = %d, b = %d\n", top->a, top->b);
      printf("ERROR: ref_c = %d, dut_c = %d\n", top->ref_c, top->dut_c);
      break;
    }

    top->eval();
    tfp->dump(Verilated::time());
  }

  top->final();
  tfp->close();

  return 0;
}