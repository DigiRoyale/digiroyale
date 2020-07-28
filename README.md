# DigiRoyale, The Battle Royale Simulator

Welcome! If you are here from the DigiPen cohort server and want to be added to the group, post your GitHub username in the `#digiroyale-dev` channel. You are also welcome to fork and pull request.

## Plans/Ideas
View the plans/ideas [here](ideas.md).  
These are mostly just taken from the Discord.
Feel free to add others' or your own ideas to this file.

## Setup

Clone the repository and init all submodules. I recommend using a git GUI such as GitKraken when dealing with submodules but in git it is this:  
`git clone https://github.com/DigiRoyale/digiroyale.git`  
`cd digiroyale`  
`git submodule update --init --recursive`

If you want to build you will need OpenSSL installed!

**Windows:**  
[Download](https://slproweb.com/products/Win32OpenSSL.html)  
Get the `OpenSSL v1.1.1g` installer (not the Light version) and install it.

**Linux Debian/Ubuntu/Mint:**  
Just install libssl-dev.  
`sudo apt-get install libssl-dev`  
If that doesn't work then install libcurl-openssl-dev.  
`sudo apt-get install libcurl-openssl-dev`

Now use CMake to generate build files. I don't recommend using the CMake CLI tool as it will put build files in the repo root directory unless you specifically override it.  
If using Visual Studio, just use "Open a local folder" and open the cloned repo.

## Project Structure
There are 3 components to the project so far.  
* `digiroyale-sim` is the actual battle royale simulator. It is a library that can be used in applications.  
* `digiroyale-bot` is a Discord bot application that uses the simulator library to run battle royale sims on Discord.  
* `digiroyale-test` is a testing application to test the simulation library without needing to use Discord.
