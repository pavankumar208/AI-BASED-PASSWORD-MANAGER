
# 📘 Secure Password Manager (C++)

## 🔐 Project Title:
**Secure Password Manager (C++)**

## 📄 Description:
This is a simple command-line **Password Manager** built in C++ that allows users to:
- Securely **store login credentials** (usernames & passwords).
- View previously stored credentials.
- Protect all stored data using a **master password** and basic **XOR-based encryption**.

It demonstrates the concepts of:
- Basic encryption (XOR cipher),
- Secure input handling,
- Structured data (using structs and vectors),
- Menu-driven command-line applications.

## 🚀 Features:
- 🔑 Master Password Authentication
- ✨ XOR-based encryption for username and password
- 📦 Store multiple credentials in memory
- 👁️ View decrypted credentials securely

---

## 🧑‍💻 How to Run

### 🔧 Prerequisites:
- A C++ compiler (like g++, clang++)
- A terminal or command prompt

### 🛠️ Compile the Code:
```bash
g++ -o password_manager password_manager.cpp
```

### ▶️ Run the Program:
```bash
./password_manager
```

### 🧪 Sample Master Password:
```
admin123
```

---

## 📸 Sample Output

```bash
Enter Master Password to unlock: admin123

===== Secure Password Manager =====
1. Add Credential
2. View All Credentials
3. Exit
Choose an option: 1

Enter username: john_doe
Enter password: mySecurePass!

✅ Credential saved successfully!
Stored Credential:
Username: john_doe
Password: mySecurePass!
```

---

## ⚠️ Security Warning

This project uses a **simple XOR cipher** for encryption, which is **not suitable for production or real-world use**. It is only meant for educational purposes to demonstrate basic encryption logic.

For real-world applications, use robust encryption libraries such as:
- OpenSSL
- Libsodium
- Crypto++ (C++ specific)

---

## 📁 File Structure

```
password_manager.cpp     # Main source file
README.md                # Project documentation
```

---

## 📌 Future Improvements

- Add persistent storage (e.g., saving to encrypted file)
- Upgrade to strong encryption (AES, RSA)
- Implement password strength checker
- Create a GUI interface (e.g., Qt or ImGui)

---

## 🧑‍🏫 Author:
Pavan Kumar
