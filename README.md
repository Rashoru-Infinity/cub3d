# cub3d
Cub3D represents a realistic 3D graphic of the inside of a maze from a first person perspective.  
# demo
![Videotogif](https://user-images.githubusercontent.com/49583698/109904245-452c9400-7ce0-11eb-9a07-8194cd0777ec.gif)
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
