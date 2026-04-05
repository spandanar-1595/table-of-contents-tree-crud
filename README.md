# 📘 Table of Contents Tree CRUD – E-Book Reader

## 👥 Team Members

* r.Spandana
* k.Akshara

---

## 🎯 Problem Statement

To design and implement a system that manages the **Table of Contents (TOC)** of an E-Book using a Tree Data Structure. The system should support CRUD operations to efficiently handle hierarchical data such as chapters, sections, and subsections.

---

## 🌳 Data Structure Used

**Tree (General Tree using Child-Sibling Representation)**

Each node represents a section of the E-Book:

* Chapter
* Section
* Subsection

---

## ✨ Features

* ➕ Add Section (Create)
* 📖 Display Table of Contents (Read)
* ✏️ Update Section Title (Update)
* ❌ Delete Section (Delete)
* 🔍 Search Section

---

## ⚙️ Technologies Used

* C Programming Language
* GCC Compiler
* Dynamic Memory Allocation (`malloc`, `free`)
* Structures and Pointers
* Recursion

---

## 🧠 Algorithm Overview

1. Create root node ("E-Book")
2. Add nodes as child or sibling
3. Traverse tree using recursion
4. Perform CRUD operations:

   * Insert node
   * Search node
   * Update node
   * Delete node

---

## 💻 Compilation & Execution

```bash
gcc src/main.c -o project
./project
```

---

## 📄 Sample Output

```
- E-Book
  - Chapter1
    - Section1
      - Subsection1
    - Section2
```

(See full output in `sample_output.txt`)

---

## 🎥 Demo Video

🔗 Add your Google Drive link here

---

## 📂 Project Structure

```
table-of-contents-tree-crud/
├── src/
│   └── main.c
├── docs/
│   └── project_report.pdf
├── ppt/
│   └── presentation.pptx
├── sample_output.txt
├── README.md
└── .gitignore
```

---

## 🚀 Real-World Application

This project simulates how an **E-Book Reader** organizes its content using hierarchical structures, making navigation easy and efficient.

---

## 📌 Conclusion

The project demonstrates how Tree Data Structures can be effectively used to manage hierarchical data in real-world applications like E-Book systems.

---

## 🔮 Future Enhancements

* Add file handling (save/load data)
* GUI-based interface
* Improved search optimization
* Integration with real E-Book platforms

---

## 📚 References

* Data Structures using C – Reema Thareja
* Introduction to Algorithms – Thomas H. Cormen
* GeeksforGeeks
* TutorialsPoint

---
