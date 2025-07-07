# 🌐 SocialNetworkApp (C++)

A fully functional, **console-based social network simulation** built in **C++**, following **core Object-Oriented Programming (OOP)** principles. This project mimics a basic version of platforms like Facebook with users, pages, posts, likes, comments, and memory posts.

---

## 🚀 Features

- ✅ **User System**: Load and manage multiple users with friends and liked pages.
- 📄 **Posts & Timelines**: Users and pages can share posts, which are viewable on timelines.
- 💬 **Commenting System**: Add and display comments on any post.
- 👍 **Likes**: Users can like posts, with a display of who liked them.
- 🧠 **Memory Posts**: Share a memory from a past post (just like Facebook).
- 📆 **Date-aware Feed**: Shows custom timeline posts from the last two days.
- 🏠 **Home Page Feed**: Aggregates posts from the current user, their friends, and liked pages.
- 📂 **File-Based Data Loading**: All users, posts, pages, comments, and relationships are loaded from structured files.
- 🧪 **Interactive Controller**: The `Controller` class runs test commands like setting a user, viewing a post, adding a like, and generating a memory.

---

## 🔧 Technologies Used

- **Language**: C++ (C++11+)
- **Environment**: Console-based
- **No External Libraries**: Entirely standard C++ with file I/O

---

## 🔍 Object-Oriented Concepts Applied

| Concept           | Description                                                                 |
|-------------------|-----------------------------------------------------------------------------|
| **Encapsulation** | All data is managed via class members and accessors.                        |
| **Inheritance**   | `Pages`, `Users`, and `Memory` posts inherit from base classes.             |
| **Polymorphism**  | Virtual methods like `DisplayPost()` and `PrintName()` used for dynamic behavior. |
| **Abstraction**   | Complex logic abstracted into `Controller`, `Post`, `Object`, etc.          |
| **Composition**   | Users contain friends, liked pages, and timeline posts.                     |
| **File Handling** | Entire data is loaded from and managed via `Userslist.txt`.                 |

---
