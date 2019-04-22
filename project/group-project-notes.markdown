---
title: Group project notes
layout: default
---

# Group project notes

## S.P.A.M.M. Space/Pirates/Aliens Mad Max

## Goals

Multiplayer text adventure with defined goal & progress; players can talk to each other and create rooms & items in-game. Predefined rooms/items and logic dictate game goals & progress. Backend db stores room/item/player data.

## Milestone 2: 4/22

Derrek:

- add broadcast messaging
- add print to multiple users (given by ids)
- update README for how to connect
- add a user account creation mechanism (dummy code, no account creation)

Charles + Oliver:

- add logo to README
- update Player class to have an integer id, and bool connected
- create example Players (`new Player(...)`)
- then update `main.cpp` to check if the user types the right username and password for some existing player

Nicola + Stephen:

- Rename RedisDemo to Database
- Create an "lastid" variable for redis, and create a function to read last id and increment last id
- Update Item class to have an integer id, make a method called `save()` that saves item to redis, and demo code that loads an item with a certain id

Mike + Kassaundra:

- Make your code work with the existing Item and Player and Room classes; create one player, one item, and two rooms to demonstrate.

Ruby + Noah:

- Make your code actually create items and rooms and connect them appropriately. Create an example main function to demonstrate. 

Ben:

- Update Room class so item requirements (for entering room) work, and update room names, and write example main function to demonstrate.

## Milestone 1: 4/19

Derrek:

- Update [telnet](https://github.com/seanmiddleditch/libtelnet/tree/develop/util) examples to hook into example C++ code for server (client is just telnet/putty)
- Write C++ file that has example functions for: when a line is entered by the client, call this C++ function; and if the line matches certain pattern/word, use a C++ function to send a message to a certain client (by id #). In other words, make the C++ file usable by everyone to process inputs and send outputs, without calling the C code. Write a Makefile that compiles it all together.

Nicola + Stephen:

- Write example C++ code for reading/writing data to a Redis server; use the hiredis library. Make example C++ functions that hide the library details.

Kassaundra + Mike:

- Write example parser for game actions: go direction, get item, drop item, look at item, inventory, open item, close item; write C++ code that checks what they type (item/direction could be anything), and prints a message

Charles + Oliver:

- Classes for rooms/items/players; for player, add last login IP, last login time, password, username, description, build permission (boolean); write getters/setters for everything; for item, create an owner (username), and an enum for item type: UNIQUE, PERPLAYER

Noah + Ruby:

- Write parser for game building & speaking commands: “say”, “tell user XYZ”, “create room called X and described by Y”, “connect room X to Y via DIR”, “create item called X and described by Y”, “put item X in room Y”

Ben:

- Write parser for room creation: “set first description for room X to Y”, “require item X to enter room Y”, “when player enters X and [has/has not] item Y, teleport player to room Z”, “when player enters X, with random Y% chance, teleport player to room Z”

