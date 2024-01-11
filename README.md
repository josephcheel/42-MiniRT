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
Configuration file has three **mandatory** elements: **Camera**, **Light** and **Ambient Light**. And three optional geomtrical figures: **Plane**, **Sphere**, **Cylinder**. Each element has the following identifier:

|      Name     | Identifier |   Name   | Identifier  |
|:-------------:|:----------:|:--------:|:-----------:|
| Ambient Light |      A     |   Plane  |      pl     |
|     Camera    |      C     |  Sphere  |      sp     |
|     Light     |      L     | Cylinder |      cy     |



### File configuration:
##### Mandatory Elements
*  Ambient Light:
    * **Identifier**: A
    *  **Ambient lighting ratio** in range [0.0,1.0]: 0.2
    *  **Colors** in RGB in range [0-255]: 255, 255, 255
*  Camera
    *  **Identifier**: C
    *  **XYZ coordinates** of the view point: -50.0,0,20
    *  **3D normalized orientation** vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
    *  FOV : Horizontal field of view in degrees in range [0,180]: 70
*  Light
    * **Identifier**: L
    * **XYZ coordinates** of the light point: -40.0,50.0,0.0
    * The light brightness ratio in range [0.0,1.0]: 0.6
    * (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255  

##### Optional Elements
*  Plane
    * **Identifier**: pl
    * **XYZ coordinates** of a point in the plane: 0.0,0.0,-10.0
    * **3D normalized** vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0 ∗ R,G,B colors in range [0-255]: 0,0,225
*  Sphere
    * **Identifier**: sp
    * **XYZ coordinates** of the sphere center: 0.0,0.0,20.6 ∗ the sphere diameter: 12.6
    * **Colors** in RGB in range [0-255]: 10, 0, 255
*   Cylinder
    * **Identifier**: cy
    * **XYZ coordinates** of the center of the cylinder: 50.0,0.0,20.6
    * **3D normalized** vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
    * **Diameter**: 14.2
    * **Height**: 21.42
    * **Colors** in RGB in range [0,255]: 10, 0, 255

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
