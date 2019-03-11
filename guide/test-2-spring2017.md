---
layout: default
title: Test 2 from Spring 2017
categories: [studyguides]
---

# Test 2 from Spring 2017

Create a bitbucket repo called `csci221-test2`. There is only one task. **Do not work with anyone else on this test. Evidence of cheating will result in a zero.**

## Task

Finish my code to build a simple MP3 file database. This code began life as a 221 assignment from earlier semesters, but all the work required in this test is different from the work required for that earlier assignment.

Copy the files from `/home/jeckroth/csci221/test2` to your own folder. You should have these files:

- database.cpp -- needs updates
- database.h -- needs updates
- main.cpp -- needs updates
- Makefile -- no updates required
- track.h -- no updates required
- track.o -- no updates required

Notice that track.cpp is missing. This is intentional. Often you will need to work with a "library" file that is pre-compiled (using `g++ -c`). Precompiled libraries save time (you avoid compiling them again) but also hide secret code. The track.h header file indicates which functions are available.

Finish the code so that the user can list all unique artists, albums, and years; show some basic statistics; set ratings on individual tracks (1-5 ratings only); and search for tracks. Your updates must match the following UML diagram:

![Test 2 UML](/guide/test-2-uml-spring2017.png)

**Avoid all memory leaks.** Check with valgrind.

## Example

```
$ ./main
Read 32 tracks.


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> list
(1)       Nine Inch Nails - 999,999 (The Slip, 2008) [] Unknown
(2)       Nine Inch Nails - Echoplex (The Slip, 2008) [] Unknown
(3)       Nine Inch Nails - Corona Radiata (The Slip, 2008) [] Unknown
(4)       Nine Inch Nails - 1,000,000 (The Slip, 2008) [] Unknown
(5)       Nine Inch Nails - Demon Seed (The Slip, 2008) [] Unknown
(6)       Nine Inch Nails - Head Down (The Slip, 2008) [] Unknown
(7)       Nine Inch Nails - Descipline (The Slip, 2008) [] Unknown
(8)       Nine Inch Nails - The Four of us are Dying (The Slip, 2008) [] Unknown
(9)       Nine Inch Nails - Lights in the Sky (The Slip, 2008) [] Unknown
(10)      Nine Inch Nails - Letting You (The Slip, 2008) [] Unknown
(11)      Monk Turner - Agustus (Calendar, 2008) [] Unknown
(12)      Monk Turner - Hot July (Calendar, 2008) [] Unknown
(13)      Monk Turner - Merry May (Calendar, 2008) [] Unknown
(14)      Monk Turner - Turkey Time (Calendar, 2008) [] Unknown
(15)      Monk Turner - December Song (Calendar, 2008) [] Unknown
(16)      Monk Turner - Labor Day Sale (Calendar, 2008) [] Unknown
(17)      Monk Turner - January 1st (Calendar, 2008) [] Unknown
(18)      Monk Turner - March in March (Calendar, 2008) [] Unknown
(19)      Monk Turner - Valentines Directions for the (Calendar, 2008) [] Unknown
(20)      Monk Turner - June (I Hate This Month) (Calendar, 2008) [] Unknown
(21)      Monk Turner - Halloween Night (Calendar, 2008) [] Unknown
(22)      Monk Turner - April Girl (Calendar, 2008) [] Unknown
(23)      Hungry Lucy - Bumble (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(24)      Hungry Lucy - Pulse of the Earth (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(25)      Hungry Lucy - Just Imagine (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(26)      Hungry Lucy - Simone (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(27)      Hungry Lucy - Hill (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(28)      Hungry Lucy - Sunday Smiled (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(29)      Hungry Lucy - Voyeur (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(30)      Hungry Lucy - Balloon Girl (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(31)      Hungry Lucy - Wandering (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(32)      Hungry Lucy - The Standing Ones (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> artists
Hungry Lucy
Monk Turner
Nine Inch Nails


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> albums
Calendar
Pulse of the Earth
The Slip


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> years
2008
2010


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> stats
Artist stats (count, artist):
10      Hungry Lucy
12      Monk Turner
10      Nine Inch Nails

Genre stats (count, genre):
32      Unknown

Year stats (count, year):
22      2008
10      2010


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> artist Nine
(1)       Nine Inch Nails - 999,999 (The Slip, 2008) [] Unknown
(2)       Nine Inch Nails - Echoplex (The Slip, 2008) [] Unknown
(3)       Nine Inch Nails - Corona Radiata (The Slip, 2008) [] Unknown
(4)       Nine Inch Nails - 1,000,000 (The Slip, 2008) [] Unknown
(5)       Nine Inch Nails - Demon Seed (The Slip, 2008) [] Unknown
(6)       Nine Inch Nails - Head Down (The Slip, 2008) [] Unknown
(7)       Nine Inch Nails - Descipline (The Slip, 2008) [] Unknown
(8)       Nine Inch Nails - The Four of us are Dying (The Slip, 2008) [] Unknown
(9)       Nine Inch Nails - Lights in the Sky (The Slip, 2008) [] Unknown
(10)      Nine Inch Nails - Letting You (The Slip, 2008) [] Unknown


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> title Demon
(5)       Nine Inch Nails - Demon Seed (The Slip, 2008) [] Unknown


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> album Pulse
(23)      Hungry Lucy - Bumble (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(24)      Hungry Lucy - Pulse of the Earth (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(25)      Hungry Lucy - Just Imagine (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(26)      Hungry Lucy - Simone (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(27)      Hungry Lucy - Hill (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(28)      Hungry Lucy - Sunday Smiled (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(29)      Hungry Lucy - Voyeur (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(30)      Hungry Lucy - Balloon Girl (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(31)      Hungry Lucy - Wandering (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(32)      Hungry Lucy - The Standing Ones (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> year 2010
(23)      Hungry Lucy - Bumble (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(24)      Hungry Lucy - Pulse of the Earth (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(25)      Hungry Lucy - Just Imagine (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(26)      Hungry Lucy - Simone (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(27)      Hungry Lucy - Hill (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(28)      Hungry Lucy - Sunday Smiled (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(29)      Hungry Lucy - Voyeur (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(30)      Hungry Lucy - Balloon Girl (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(31)      Hungry Lucy - Wandering (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(32)      Hungry Lucy - The Standing Ones (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> rate 26 3


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> rate 27 8
Error, rating must be between 1 and 5.


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> rate 27 0
Error, rating must be between 1 and 5.


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> rate 27 -5
Error, rating must be between 1 and 5.


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> rate 27 5


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> list
(1)       Nine Inch Nails - 999,999 (The Slip, 2008) [] Unknown
(2)       Nine Inch Nails - Echoplex (The Slip, 2008) [] Unknown
(3)       Nine Inch Nails - Corona Radiata (The Slip, 2008) [] Unknown
(4)       Nine Inch Nails - 1,000,000 (The Slip, 2008) [] Unknown
(5)       Nine Inch Nails - Demon Seed (The Slip, 2008) [] Unknown
(6)       Nine Inch Nails - Head Down (The Slip, 2008) [] Unknown
(7)       Nine Inch Nails - Descipline (The Slip, 2008) [] Unknown
(8)       Nine Inch Nails - The Four of us are Dying (The Slip, 2008) [] Unknown
(9)       Nine Inch Nails - Lights in the Sky (The Slip, 2008) [] Unknown
(10)      Nine Inch Nails - Letting You (The Slip, 2008) [] Unknown
(11)      Monk Turner - Agustus (Calendar, 2008) [] Unknown
(12)      Monk Turner - Hot July (Calendar, 2008) [] Unknown
(13)      Monk Turner - Merry May (Calendar, 2008) [] Unknown
(14)      Monk Turner - Turkey Time (Calendar, 2008) [] Unknown
(15)      Monk Turner - December Song (Calendar, 2008) [] Unknown
(16)      Monk Turner - Labor Day Sale (Calendar, 2008) [] Unknown
(17)      Monk Turner - January 1st (Calendar, 2008) [] Unknown
(18)      Monk Turner - March in March (Calendar, 2008) [] Unknown
(19)      Monk Turner - Valentines Directions for the (Calendar, 2008) [] Unknown
(20)      Monk Turner - June (I Hate This Month) (Calendar, 2008) [] Unknown
(21)      Monk Turner - Halloween Night (Calendar, 2008) [] Unknown
(22)      Monk Turner - April Girl (Calendar, 2008) [] Unknown
(23)      Hungry Lucy - Bumble (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(24)      Hungry Lucy - Pulse of the Earth (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(25)      Hungry Lucy - Just Imagine (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(26)    3 Hungry Lucy - Simone (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(27)    5 Hungry Lucy - Hill (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(28)      Hungry Lucy - Sunday Smiled (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(29)      Hungry Lucy - Voyeur (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(30)      Hungry Lucy - Balloon Girl (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(31)      Hungry Lucy - Wandering (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown
(32)      Hungry Lucy - The Standing Ones (Pulse of the Earth, 2010) [http://www.archive.org/detai] Unknown


Type 'list', 'artists', 'albums', 'years', 'stats', 'rate [trackid] [rating 1-5]', 'quit',
or enter a search query: [artist/title/album/year] [query]
> quit
```
