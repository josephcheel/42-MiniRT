<!--HEADER-->
<h1 align="center"> MiniRT | 
  <picture>
  <source media="(prefers-color-scheme: dark)" srcset="https://cdn.simpleicons.org/42/white">
  <img alt="42" width=40 align="center" src="https://cdn.simpleicons.org/42/Black">
 </picture>
 Cursus 
 <!--<img alt="Complete" src="https://raw.githubusercontent.com/Mqxx/GitHub-Markdown/main/blockquotes/badge/dark-theme/complete.svg">-->
</h1>
<!--FINISH HEADER-->

>A project on Ray-Tracing and rendering three-dimensional computer-generated images. Using MiniLibX, the 42 graphical library.

<div align="center">
<img align="center"  width="800" src="https://github.com/josephcheel/42-MiniRT/blob/main/Scenes/Images/img5.png">
</div>

### What is the project about
MiniRT is a project that introduces the basics of Ray tracing, focusing on 3D computer-generated images from a configuration file. It includes ambient light, lights, camera, and three geometrical figures (Plane, Sphere, Cylinder). The bonus part introduces multiple lights, cones as a geometrical figure, and additional elements.
## General Instrucctions
* Makefile will compile your source files. It must include 'all' and 'bonus' rules for the Mandatory and Bonus parts, respectively. It should not relink.
* You are required to use MiniLibX for this project.
* The program should be compiled using the following commands:
 
```shell
> ./miniRT <filename>.rt
> ./miniRT_bonus <filename>.rt
```
> [!WARNING]
> Maps must have the ***.rt*** extension
## Mandatory Instrucctions
#### File configuration structure:

## Bonus Instrucctions

### Resources
* [**Ray Tracing in One Weekend, (Peter Shirley, Trevor David Black, Steve Hollasch)**](https://raytracing.github.io/)
* [**Ray Tracing [YouTube]**](https://youtu.be/gfW1Fhd9u9Q?si=BI667gXh8sOryeaU)
* [**Phong Reflection Model**](https://en.wikipedia.org/wiki/Phong_reflection_model)
* [**Modelo de Color HSV**](https://es.wikipedia.org/wiki/Modelo_de_color_HSV?useskin=vector)

<!--### Description of file arguments structure

# Ambient light
A 0.2            255,255,255
^  ^ Brightness        rgb color separeted by a comma.
| identifier  

Camera position
C -50,0,20       0,0,0     70
^   ^               ^      ^angular vision
|   |               |vector orientation
|   | Camera position in space
|identifier  

Light:
L -40,0,30       0.7              255,255,255 
^   ^             ^                   ^color of the light
|   |             |brightness
|   | Light position in  space
|identifier  

Plane:
pl 0,80,90      0,1.0,0          255,0,225
^   ^             ^                   ^color of the plane
|   |             |Vector direction
|   | Vector position in space
|identifier  

Sphere:
sp 0,0,20        20               255,0,0     
^   ^             ^                   ^color of the sphere
|   |             |Radious
|   | Vector position in space
|identifier  


Cylinder:
cy  50.0,0.0,20.6 0,0,1.0          14.2  12.21      10,0,255
^   ^              ^                ^      ^         ^color of the cylinder
|   |              |                |      |High
|   |              |                |Diameter
|   |              |Vector direction of the cylinder
|   | Vector position in space
|identifier  -->
