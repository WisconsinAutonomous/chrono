Chrono Tutorials, Core Features {#tutorial_table_of_content_chrono}
==========================

The following links describe a set of basic Chrono tutorials. 

-   @subpage tutorial_demo_buildsystem
	
    Tutorial which teaches the basic approach to build and simulate mechanical systems. No 3D user interface is used here, so you compile this example even if you do not have Irrlicht 3D visualization library installed. Learn how:

    - create a physical system (a slider-crank)
    - add/remove rigid bodies
    - create mechanical joints between bodies
    - perform a simulation 
    - No GUI: only text output. 

-   @subpage tutorial_demo_powertrain

    Tutorial which teaches the basic approach to build systems that embed powertrains, made with 1-degree-of-freedom items (rotating shafts).

    - connect 1D shafts with transmission ratios
    - connect 1D shafts with 1D clutches, brakes, etc.
    - connect a 1D shaft to a 3D body. 
    - No GUI: only text output. 

-   @subpage tutorial_demo_chfunctions

    Tutorial that teaches how to use the ChFunction inherited classes to build math functions of y=f(x) type. The ChFunction objects are 'building blocks' whose main usage is to describe motion laws, such as trajectories in automation and robotics, etc.

    - create and use ChFunction objects, from available classes.
    - define a custom function by inheriting from ChFunction class. 
    - No GUI: only text output. 