<div id="top"></div>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/MGufo/bellaPadova/blob/89679ba27112403a5598cda9c8a490080b251ebd/relazione/logo.png">
    <img src="relazione/logo.png" alt="Logo" width="100" height="100">
  </a>
<h3 align="center">Bella Padova</h3>

  <p align="center">
    An all-in-one management solution for a pizzeria's inventory, menu and orders. 
  <br />
    
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contacts">Contacts</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->

## About The Project

BellaPadova has been developed as an all-in-one solution to computerize the
workflow of any pizzeria, implementing an efficient management of inventory,
menus and orders.

The application was designed using the MVC (Model-View-Controller) architectural
design pattern in order to separate the business logic from the user interface,
which was implemented using the Qt framework.

In addition to the application itself the assignment required the development of
a type hierarchy whose objects would depict all physical items relative to the
business logic (ingredients, menu courses etc), and a data structure to manage
said objects. A doubly linked list template was implemented along with
bidirectional iterators, comparison operators and methods for inserting,
removing, searching and counting items.

<p align="right">(<a href="#top">back to top</a>)</p>

### Built With

- [Qt Framework](https://www.qt.io/)
- [MinGW](https://www.mingw-w64.org/)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->

## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

- [Qt 5.9.5](https://download.qt.io/archive/qt/5.9/5.9.5/):
  Although Qt ended support for the 5.9 release in July 2020 the assignment's
  requirements prevented usage of an up-to-date release.
  Version 5.9.5 is **strongly** recommended to run this application properly; furthermore we cannot guarantee compatibility with newer Qt releases.

- C++:
  A full C++ environment is required to build the application, with C++11 being
  the minimum version supported.

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/MGufo/bellaPadova.git
   ```
2. Generate the required makefiles using the the included project file
   ```sh
   qmake bellaPadova.pro
   ```
3. Build the project
   ```sh
   make
   ```
4. Run the application

   ```sh
   ./bellaPadova
   ```

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->

## License

Distributed under the GNU AGPLv3 License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->

## Contacts

Marco - [GitHub Profile](https://github.com/MGufo)

Gabriel - [GitHub Profile](https://github.com/killbizz)

Andrea - [GitHub Profile](https://github.com/AndreaMoscon)

Project Link: [https://github.com/MGufo/bellaPadova](https://github.com/MGufo/bellaPadova)

<p align="right">(<a href="#top">back to top</a>)</p>
