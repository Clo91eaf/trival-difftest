# 🚀 Trival-DiffTest

Trival-DiffTest is a tool inspired by [OpenXiangShan's Difftest](https://github.com/OpenXiangShan/difftest) that allows for the comparison of behavioral differences between two Verilog modules. This tool is particularly useful for agile development and rapid iteration.

## ✨ Features

- [x] Compare behavioral differences between two Verilog modules.
- [ ] Add random testing interface.
- [ ] Add unit testing interface. 
- [ ] Add Chisel interface. 
- [ ] Add Rust interface as part of the project [Hemu](https://github.com/Clo91eaf/hemu). 

## 🛠️ Installation

To use Trival-DiffTest, follow these steps:

1. Make sure you have [Verilator](https://www.veripool.org/wiki/verilator) installed on your machine
```bash
verilator --version
Verilator 5.008 2023-03-04 rev v5.008
```

verilator 5.008 is recommanded.

2. Clone the repository:

   ```bash
   git clone https://github.com/your_username/trival-difftest.git
   cd trival-difftest
   make
   ```

## 💡 Usage(TODO)

To compare behavioral differences between two Verilog modules, use the following command:

```bash
trival-difftest <module_1.v> <module_2.v>
```

Replace `<module_1.v>` and `<module_2.v>` with the paths to the Verilog files you want to compare.

### Random Testing Interface (TODO)

To add random testing functionality, modify the appropriate files or classes in the project. (Specify the specific steps to add the random testing interface)

### Unit Testing Interface (TODO)

To add unit testing functionality, modify the appropriate files or classes in the project. (Specify the specific steps to add the unit testing interface)

### Chisel Interface (TODO)

To add Chisel interface, modify the appropriate files or classes in the project. (Specify the specific steps to add the Chisel interface)

### Rust Interface (Hemu Project) (TODO)

To integrate Trival-DiffTest with the [Hemu](https://github.com/Clo91eaf/hemu) project, follow these steps:

1. Clone the Hemu repository:

   ```bash
   git clone https://github.com/your_username/hemu.git
   cd hemu
   ```

2. Integrate Trival-DiffTest as a submodule:

   ```bash
   git submodule add https://github.com/your_username/trival-difftest.git
   ```

3. Modify the necessary files or classes in the Hemu project to utilize Trival-DiffTest.

## 🤝 Contributing

Contributions to Trival-DiffTest are welcome! If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with descriptive commit messages.
4. Push your changes to your forked repository.
5. Submit a pull request detailing your changes.

Please ensure that your code follows the existing coding style and includes appropriate tests.

## 📄 License

[MIT License](LICENSE)

## 🙏 Acknowledgments

Trival-DiffTest is built upon the ideas from [OpenXiangShan's Difftest](https://github.com/OpenXiangShan/difftest). We would like to thank the contributors of Difftest for their valuable work.

## TODO

- Add random testing interface.
- Add unit testing interface.
- Add Chisel interface.
- Add Rust interface as part of the project [Hemu](https://github.com/Clo91eaf/hemu).