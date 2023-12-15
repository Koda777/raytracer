# Raytracer

## Authors

- Alexandre Decobert
- Raphael Camblong
- Guillaume Lebreton

## Description

Ray tracing is a technique used to generate realistic digital images by simulating the inverse path of light. The goal of this project is to create a program that can generate an image from a file describing the scene.

This is a C++ implementation of a raytracer that supports various primitives, transformations, lighting, and materials. The program is capable of generating an image from a scene configuration file.

## Installation

### Dependencies

- `libconfig++`
- `SFML 2.5.1`

## Compilation

The project can be compiled using `cmake`. The following commands can be used to build the project:

```sh
mkdir build
cd build
cmake ..
make
```

## Usage

The program can be executed with the following command:

```sh
./raytracer <SCENE_FILE>
```

The `SCENE_FILE` argument should be a file that describes the scene to be rendered.

## Features

The raytracer supports the following features:

### Primitives

- Sphere
- Plane

### Transformations

- Translation

### Light

- Directional light
- Ambient light

### Material

- Flat color

### Scene Configuration

- Add primitives to scene
- Set up lighting
- Set up camera

### Interface

- Output to a PPM file

## Scene File Format

The scene must be configured in an external file using the `libconfig++` library. The following is an example of the file format:

```sh
camera :
{
    resolution = { width = 1920; height = 1080; };
    position = { x = 0; y = -100; z = 20; };
    rotation = { x = 0; y = 0; z = 0; };
    fieldOfView = 72.0;
};

primitives :
{
    spheres = (
        { x = 60; y = 5; z = 40; r = 25; color = { r = 255; g = 64; b = 64; }; } ,
        { x = -40; y = 20; z = -10; r = 35; color = { r = 64; g = 255; b = 64; }; }
    );
    planes = (
        { axis = "Z"; position = -20; color = { r = 64; g = 64; b = 255; }; }
    );
};

lights :
{
    ambient = 0.4;
    diffuse = 0.6;
    point = (
        { x = 400; y = 100; z = 500; };
    );
    directional = ();
};
```
## Acknowledgments

We would like to thank our pedagogical team for their support and guidance throughout this project. Their feedback and encouragement helped us to improve and deliver a high-quality raytracer.

We also want to express our gratitude to the developers of the authorized libraries for making their software available to us. Their work helped to make this project possible.

Finally, we would like to thank the entire community for their contributions and feedback. Your input helped to shape this project and make it better. Thank you!
