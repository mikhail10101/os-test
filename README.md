# 🌀 CuriOS

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)  
✨ *Exploring OS development one component at a time!*

CuriOS is a 32-bit 🖥️ operating system developed in GAS (GNU Assembler) as a learning project to dive deep into OS development concepts.

## 🌟 Overview

🔧 This project is my hands-on playground for understanding operating systems, currently featuring:

- 🚀 GRUB Multiboot (Specification 1) support
- 🗂️ Global Descriptor Table (GDT)
- 📚 Paging and virtual memory
- ⚡ Interrupt handling
- 💾 Basic memory allocation

## 📦 Current Features

| Component       | Status     |
|----------------|------------|
| GDT Setup      | ✅ Working |
| Kernel         | ✅ Basic   |
| Paging         | ✅ Basic |
| Interrupts     | 🚧 Partial |
| Memory Manager | 🚧 Partial |

## 🛣️ Roadmap

- [ ] Process scheduling
- [ ] System calls
- [ ] User mode protection
- [ ] Device drivers
- [ ] File system
- [ ] And whatever else I find interesting!

## 🛠️ Quick Start

```bash```
./run.sh

## 💡 Emulator Support

The OS runs in both of these emulators - pick your favorite!

- **QEMU** - Fast and lightweight
- **Bochs** - Great for debugging

## 🔧 Setup & Development Environment

To build CuriOS, you'll need a **GCC cross-compiler** targeting `i686-elf`. This ensures your host system's libraries don't interfere with the OS build. Visit the [OSDev Wiki's GCC Cross-Compiler page](https://wiki.osdev.org/GCC_Cross-Compiler) for more information on setting it up.

## 📚 Learning Resources

Massive thanks to these amazing resources that made this project possible:

- [OSDev Wiki](https://wiki.osdev.org/) 📖
- [Oliver Stem Learning](https://www.youtube.com/@olivestemlearning) 🎥
