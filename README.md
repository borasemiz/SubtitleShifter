# Subtitle Shifter

## How to Build

You are going to need compiler that is C++11 compatible and CMake version 3.5 or higher to build this project. Project doesn't depend any external libraries. It should be compatible with all the major operating systems. Tested in Windows 10.

Steps to build the project:
- Create a folder called `Build` in the root directory of this project.
- Use CMake to generate compiler specific structure (Unix makefiles, Visual Studio solution etc.) in this `Build` folder. Just `cd` into the `Build` directory and execute `cmake ..`, it will take care of it.
- If you are using Linux or Mac, while you are in the `Build` directory, go on and execute `make`. If you generated visual studio solution, open that solution inside visual studio and build there.

## Usage

A simple commandline application that has only one functionality: shift times of SubRip (.srt) formatted subtitle files.

For example, this command backwards the timing of each subtitle in the `my_subtitle_file.srt` by 1.5 seconds.

```
# SubtitleShifter <subtitlefile> <(-/+)amount_of_milliseconds>
SubtitleShifter my_subtitle_file.srt -1500
```

Enjoy!