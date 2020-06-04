# raytracer
A simple raytracer renderer. I am following [this tutorial](https://raytracing.github.io/books/RayTracingInOneWeekend.html) by Peter Shirley.

## What does this project do?
At the moment, it renders a simple image:

![raytrace](https://pbs.twimg.com/media/EZipRqHUYAA9Nwf?format=png&name=small)

It's not much, but it demonstrates a basic diffuse and metal materials.

## How do I compile and run this project?
Tools you need:
* [Codeblocks](http://www.codeblocks.org/)
* [MinGW](http://www.mingw.org/)

Simply import the project into Codeblocks and build it.

Now, when running it, you want to navigate to `[PROJECT ROOT]/bin/Debug/` and *in the command line* run `./raytracer.out > image.ppm`. This will actually write the image to a file `image.ppm`.
