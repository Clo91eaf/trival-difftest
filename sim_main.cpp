#include <memory>
#include <verilated.h>
#include <time.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"

// global variables
struct Args {
  bool rand_test;
} args;

VerilatedVcdC *tfp = new VerilatedVcdC();
const std::unique_ptr<Vtop> top{new Vtop{"TOP"}};

// initialize random seed
void rand_init() { srand(time(NULL)); }

// initialize verilator
void verilator_init(int argc, char **argv) {
  Verilated::traceEverOn(true);
  Verilated::commandArgs(argc, argv);
}

// parse args
void parse_args(int argc, char **argv) {
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-r") == 0) {
      args.rand_test = true;
    }
  }
}

void trace_init() {
  top->trace(tfp, 99);
  tfp->open("dump.vcd");
}

void top_init() {
  top->a = 0;
  top->b = 0;
}

void init(int argc, char **argv) {
  // initialize random seed
  rand_init();

  // initialize verilator
  verilator_init(argc, argv);

  // parse args
  parse_args(argc, argv);

  // open trace
  trace_init();

  // top init
  top_init();
}

void difftest() {
  while (!Verilated::gotFinish() && Verilated::time() < 1000) {
    Verilated::timeInc(1);

    top->a = rand() % 2;
    top->b = rand() % 2;

    top->eval();

    tfp->dump(Verilated::time());

    if (top->ref_c != top->dut_c) {
      printf("ERROR: a = %d, b = %d\n", top->a, top->b);
      printf("ERROR: ref_c = %d, dut_c = %d\n", top->ref_c, top->dut_c);
      break;
    }
  }
}

void release() {
  top->final();
  tfp->close();
}

int main(int argc, char **argv) {
  init(argc, argv);

  difftest();

  release();
  return 0;
}