# Purple Rain

>This C++ program creates  a canvas based particle system to simulate rainfall.
>You know... Purple Rain ~ ♪.


## Building

Requires the SFML library

On Ubuntu:

```sh
sudo apt-get install libsfml-dev
cmake <path-to-source>
make
```

On OSX with [Homebrew](https://brew.sh/):
```sh
brew install sfml
cmake <path-to-source>
make
```

## Run
```sh
./Purple-Rain
```

---
## RoadMap
	[x] Create a canvas with random number of particles spaced at random intervals that animate down through the height of the canvas
	[x] For every fame of the animation, update the number of rain drops to create a continuous, infinite rainfall
	[x] Allow users to control those aspects:
		[x] start
		[x] stop
		[x] reset
		[x] speed
		[x] density
	[x] Add an UI to control those aspects.
	[ ] Add a check boxes to the GUI (FPS display, etc.)
    [ ] Add some wind to blow the rain diagonally
    [ ] As the rain reaches the bottom of the canvas, have them form a puddle which fills the screen evenly
