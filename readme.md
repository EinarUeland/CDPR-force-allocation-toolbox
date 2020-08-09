This repository considers methods for force-allocation onto overconstrained CDPR setups.

  <img src="Gif/LATEXFORMULATION.PNG" width="750" title="hover text">

We refer to the paper *Optimal Force Allocation for Overconstrained Cable-Driven Parallel Robots: Continuously
Differentiable Solutions with Assessment of Computational Efficiency*, by Ueland E, Sauder T, Skjetne R for documentation on included methods. 

Try running *QuickExample.m* for a quick demonstration. 

-Make sure to add the whole folder with subfolders to your MATLAB path.

-Verified to be working in MATLAB 2019a.

-For older versions of MATLAB, one need to rerun COMPILEC_CODE.m to regenerate C-Code. (you need an appropriate C-Comppiler).

-For versions earlier than MATLAB 2018a, the syntax for manipulating Figures is different, such that some adaptations is needed to reproduce the figures.

-There is little use of internal MATLAB functions, so there should not be a need for many MATLAB packages excluding the standard ones.


![](Gif/ExampleTraj.gif)

