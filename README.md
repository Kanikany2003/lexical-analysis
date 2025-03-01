<h1 align="center">📝 Lexical Analyzer in C</h1>

<p align="center">
  <strong>A C program that performs lexical analysis by identifying keywords, operators, constants, identifiers, and special symbols in an input string.</strong>
</p>

---

## 📌 Overview

This project consists of **two programs** that analyze input strings and classify different tokens such as:
- **Keywords** (e.g., `if`, `else`, `while`)
- **Operators** (e.g., `+`, `-`, `=`, `*`)
- **Identifiers** (e.g., variable names)
- **Constants** (e.g., `123`, `3.14`)
- **Brackets and Special Symbols** (e.g., `(`, `{`, `@`)

🔹 `practical1.c` → Basic lexical analysis using string parsing read from input.  
🔹 `practical2.c` → More advanced lexical analysis, handling expressions, operators, and syntax checking, read from file.

---

## 🚀 Programming Language Used

This project is written in **C**, known for its efficiency in handling low-level operations like token parsing.

---

## 🔑 Main Logic

### 🛠 **Lexical Analysis Process**
1. The user enters a string or expression.
2. The program scans each character and classifies it as:
   - A **keyword** (if it matches predefined C keywords).
   - An **operator** (if it belongs to the set of mathematical or logical operators).
   - An **identifier** (if it follows variable naming conventions).
   - A **constant** (if it's a number).
   - A **bracket** or **special symbol**.
3. The results are displayed on the console.

---
<div style="border: 2px solid #ddd; padding: 15px; border-radius: 5px; background: #f8f9fa;">
  <h2>Example Usage</h2>

  <strong>Input (User Enter string)</strong>
  <pre style="background:#fff;padding:10px;border-radius:5px;">int x = 5 + 3;</pre>

  <strong>Output</strong>
  <pre style="background:#fff;padding:10px;border-radius:5px;">int is a keyword<br>x is an identifier<br>= is an operator<br>5 is a constant<br>+ is an operator<br>3 is a constant<br>; is a special symbol</pre>

  <strong>ciphertext.txt</strong>
  <pre style="background:#fff;padding:10px;border-radius:5px;">thisisencryptionhillcipher</pre>
</div>



