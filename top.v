module top(
  input a,
  input b,
  output dut_c,
  output ref_c
);
  add add0(
    .a(a),
    .b(b),
    .c(dut_c)
  );
  sub sub0(
    .a(a),
    .b(b),
    .c(ref_c)
  );
endmodule
