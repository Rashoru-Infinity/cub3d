# Cub3d
Cub3D represents a realistic 3D graphic of the inside of a maze from a first person perspective.  
# Demo
![ezgif com-gif-maker](https://user-images.githubusercontent.com/49583698/110178483-db2ffe00-7e49-11eb-9bdc-2cb87f97b78b.gif)
# Usage
```
#run
./cub3D xxx.cub
#save screen shot(screenshot.bmp) from a spawn point
./cub3D xxx.cub --save
```
# CubFile
You can determine structure of a maze and textures by editing cub file.  
The map must be composed of only 4 possible characters
- 0 : an empty space
- 1 : wall
- 2 : item
- N,S,E,W : player's start position and spawing orientation
This is a simple valid map  
111111  
100101  
102001  
1100N1  
111111  
  
Contents of the cub file must match the rule as follows.  
- The map must be closed / surrounded by walls.  
- Except for the map content, each type of element can be separated by one or more empty line(s).  
- Except for the map content which always has to be the last, each type of element can be set in any order in the file.
- Except for the map, each type of information from an element can be separated by one or more space(s).　　
- Each elements(except the map) firsts information is the type identifier, followed be all specific informations for each object in astrict order such as:
   - Resolution
      - Identifier : R
      - x render size
      - y render size
   - North texture
      - Identifier : NO
      - path to the north texture
   - South texture
      - Identifier : SO
      - path to the south texture
   - West texture
      - Identifier : WE
      - path to the west texture
   - Sprite texture
      - Identifier : S
      - path to the sprite texture
   - Floor color
      - Identifier : F
      - R,G,B colors in range [0, 255]: 0,255,255
   - Ceiling color
      - Identifier : C
      - R,G,B colors in range [0, 255]: 0,255,255
- Example of the minimalist .cub scene:
```
R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000002000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
# Key Operation
If you do not use the --save option, players can explore the map.  
<kbd>W</kbd> : Go straight  
<kbd>A</kbd> : Slide to the left  
<kbd>D</kbd> : Slide to the right  
<kbd>S</kbd> : Go back  
<kbd>&#8592;</kbd> : Turn right  
<kbd>&#8594;</kbd> : Turn left  
<kbd>ESC</kbd> : Quit game
